#include <stdio.h>
#include <stdlib.h>

/*global variables used in my program */

int pageTable[256];
int TLBPage[16];
int TLBPageFrame[16];
int TLBindex=0;
int TLBHit = 0;
int numOfPageEntries=0;


int main(int argc, char *argv[])
{
 if(argc != 2) {
printf("Please enter list of addresses eg. 'addresses.txt'\n");
}


	int translatedAddresses = 0;
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	
	fp = fopen(argv[1], "r");
	
	if(fp == NULL){
			exit(EXIT_FAILURE);
			}
	
	while((read = getline(&line, &len, fp)) != -1) {
	/* i can now print the offset and the page number
 	 * 
 	 */
	unsigned long pN = ((unsigned long) atoi(line) & 0xff00UL)>>8;
	unsigned long  offS = (unsigned long)atoi(line) & 0x00ffUL;
	int pageNumber = (int) pN;
	int offSet = (int) offS;
	int physicalAddress = TLB(pageNumber,offSet);
	if(physicalAddress == -1){
	physicalAddress = LookPageTable(pageNumber,offSet);
    	}
		printf("Virtual Address: %d   ", atoi(line));
		printf("Physical address:  %d\n",physicalAddress);
	translatedAddresses++;

	}
	

	printf("Number of Translated Addresses = %d\n", translatedAddresses);
	printf("TLB hit = %d\n", TLBHit);
	printf("TLB hit ratio = %.3f\n", (float) TLBHit /1000);
	fclose(fp);
	if(line){free(line);}
	exit(EXIT_SUCCESS);
	







}


int TLB(int page, int offset){
int physicalAddress = -1;
int i = 0;
while(i < 16){
if(TLBPage[i] == page){
physicalAddress = TLBPageFrame[i]*256 + offset;

TLBHit++;
break;
}
i++;
}



return physicalAddress;


}



int LookPageTable(int page, int offset){

int physicalAddress = -1;
int pagePos = 0;
if(numOfPageEntries == 0){
pageTable[0] = page;
numOfPageEntries++;

}
while(pagePos <= numOfPageEntries){
	if(pageTable[pagePos] == page){
		physicalAddress =  256*pagePos + offset;
		TLBPage[TLBindex] = page;
		TLBPageFrame[TLBindex] = pagePos;
		if(TLBindex < 16){TLBindex++;}
		else{TLBindex == 0;}
		break;
		}
	else if(pagePos == numOfPageEntries){
		pageTable[numOfPageEntries] = page;
		physicalAddress = 256*numOfPageEntries + offset;
		TLBPage[TLBindex] = page;
		TLBPageFrame[TLBindex] = numOfPageEntries;
		if(TLBindex < 16){TLBindex++;}
		else{TLBindex == 0;}
		numOfPageEntries++;
		break;
		}

	pagePos++;
	}

return physicalAddress;
}




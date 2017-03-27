#include <pthread.h>
#include <stdio.h>
int puzzleCorrect = 1;
int sudoko[] = {6,2,4,5,3,9,1,8,7,5,1,9,7,2,8,6,3,4,8,3,7,6,1,4,2,9,5,1,4,3,8,6,5,7,2,9,9,5,8,2,4,7,3,6,1,7,6,2,3,9,1,4,5,8,3,7,1,9,5,6,8,4,2,4,9,6,1,8,2,5,7,3,2,8,5,4,7,3,9,1,6};
int location[27][9]={{0,1,2,3,4,5,6,7,8},
{9,10,11,12,13,14,15,16,17},
{18,19,20,21,22,23,24,25,26},
{27,28,29,30,31,32,33,34,35},
{36,37,38,39,40,41,42,43,44},
{45,46,47,48,49,50,51,52,53},
{54,55,56,57,58,59,60,61,62},
{63,64,65,66,67,68,69,70,71},
{72,73,74,75,76,77,78,79,80},
{0,9,18,27,36,45,54,63,72},
{1,10,19,28,37,46,55,64,73},
{2,11,20,29,38,47,56,65,74},
{3,12,21,30,39,48,57,66,75},
{4,13,22,31,40,49,58,67,76},
{5,14,23,32,41,50,59,68,77},
{6,15,24,33,42,51,60,69,78},
{7,16,25,34,43,52,61,70,79},
{8,17,26,35,44,53,62,71,80},
{0,1,2,9,10,11,18,19,20},
{3,4,5,12,13,14,21,22,23},
{6,7,8,15,16,17,24,25,26},
{27,28,29,36,37,38,45,46,47},
{30,31,32,39,40,41,48,49,50},
{33,34,35,42,43,44,51,52,53},
{54,55,56,63,64,65,72,73,74},
{57,58,59,66,67,68,75,76,77},
{60,61,62,69,70,71,78,79,80}};
/* this function is run by the second thread */
void *sudokoArrayCheck(void *i_void_ptr){

int *i_ptr = (int *)i_void_ptr;

int sudokoCheck[9] = {0,0,0,0,0,0,0,0,0};

//bool computationDone = false;
//bool isCorrect = true;
int i = 0;

while (i<9){

if(sudokoCheck[sudoko[location[*i_ptr][i]] -1 ] == 0){

sudokoCheck[sudoko[location[*i_ptr][i]] -1 ] = 1;
//if(i == 8){computationDone = true;}
i++;
}
else{
puzzleCorrect = 0;
//ComputationDone = true;
break;
}

}
if(*i_ptr == 6){
int l = 0;
while(1){

if(l == 8){break;}
l++;
}
}
/* the function must return something - NULL will do */
return NULL;

}

int main(){

int i ;
printf("Currently testing the following Sudoko Puzzle\n\n\n");
 i = 0;
printf("%d", sudoko[i]);
i++; 
while(i<=8){
                printf(" %d", sudoko[i]);
                i++;
                }

                printf("\n%d",sudoko[i]);
                i++;
 while(i<=17){
                printf(" %d", sudoko[i]);
                i++;
                }

                printf("\n%d",sudoko[i]);
                i++;
 while(i<=26){
                printf(" %d", sudoko[i]);
                i++;
                }

                printf("\n%d",sudoko[i]);
                i++;
 while(i<=35){
                printf(" %d", sudoko[i]);
                i++;
                }

                printf("\n%d",sudoko[i]);
                i++;
 while(i<=44){
                printf(" %d", sudoko[i]);
                i++;
                }

                printf("\n%d",sudoko[i]);
                i++;
 while(i<=53){
                printf(" %d", sudoko[i]);
                i++;
                }

                printf("\n%d",sudoko[i]);
                i++;
 while(i<=62){
                printf(" %d", sudoko[i]);
                i++;
                }

                printf("\n%d",sudoko[i]);
                i++;

 while(i<=71){
                printf(" %d", sudoko[i]);
                i++;
                }

                printf("\n%d",sudoko[i]);
                i++;
 while(i<=80){
                printf(" %d", sudoko[i]);
                i++;
                }

            




pthread_t tests[27]; 		
		for(i=0; i<27; i++){
		

			if(pthread_create(&tests[i], NULL,sudokoArrayCheck, &i)) {

fprintf(stderr, "Error creating thread\n");
return 1;

}
		}

wait(4);
if(puzzleCorrect == 1){
	printf("\n\n\nThe puzzle is Correct\n");
printf("thank you\n\n");
	
}
else{printf("The puzzle is wrong");}

		
		



return 0;
}




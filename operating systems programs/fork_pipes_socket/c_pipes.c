#include <unistd.h>
#include <stdio.h>

int main()
{
int fd1[2], fd2[2] , pid , pipe1 , pipe2;
pipe1 = pipe(fd1);
if(pipe1 == -1) {printf("PIPE_FAILED");
return(0);}
pipe2 = pipe(fd2);
if(pipe2 == -1) {printf("PIPE_FAILED");
return(0);}


pid = fork();
if(pid == -1) /* Error */
{printf("Fork failed.\n");
return(0);
}


else if (pid == 0){


close(fd1[1]);
close(fd2[0]);
char givenString[20];
char* outputString;
int i = 0;
while(1){
givenString[0] ='0';
read(fd1[0], givenString , 20);


/* algorithm that inverts Caps ----------------*/

if(givenString[0] != '0'){
while(i < 20){

      if(givenString[i] >= 'a' && givenString[i] <= 'z'){
            outputString[i] = ('A' + givenString[i] - 'a');
}
else if(givenString[i] >= 'A' && givenString[i] <= 'Z'){outputString[i] =givenString[i] + 32;}
i++;}

write(fd2[1] , outputString , 20);
}}}

else{
close(fd1[0]);
close(fd2[1]);
char inputString[20];
char invertedString[20];
while(1){
/* algorithm to take a string from user */

	printf("please enter a string:");
	fgets(inputString,20,stdin);
	
		write(fd1[1], inputString , 20);
		sleep(10);
		
			read(fd2[0] , invertedString , 20);
			
				printf("\n result :  %s \n", invertedString);
				
							
			}
		
	
}
return(0);
}

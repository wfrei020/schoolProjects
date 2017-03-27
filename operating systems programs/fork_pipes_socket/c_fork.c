#include <stdio.h>
#include <unistd.h>

int main()
{
int pid1, pid2, pid3;
pid1 = fork();
pid2 = fork();
pid3 = fork();
printf("pid 1 : %d\n" ,pid1);
printf("pid 2 : %d\n", pid2);
printf("pid 3 : %d\n", pid3); 
return(0);
}

#include "barrier.h"
#include <pthread.h>
#include <stdio.h>
int numOfThreads;
int currentThreads=0;
int barrier_init(int n){
	numOfThreads = n;
return 0;
}

int barrier_barrierPoint(){
	currentThreads++;
        
	while(1){
	if(currentThreads == numOfThreads){break;}
	
}


	
	
}

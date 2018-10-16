#include<stdio.h>
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main(){
	int cpid=fork();
	if(cpid>0){
		sleep(1);
		printf("I am a child.\n");
	}
	else {
		printf("i am parent.\n");
	}
}

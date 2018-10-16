#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include<stdio.h>

int main() 
{ 
    // Fork returns process id 
    // in parent process 
    pid_t child_pid = fork(); 
  
    // Parent process  
    if (child_pid > 0) {
        sleep(50);
	printf("Parent Process.\n");
    }
  
    // Child process 
    else{
	printf("Child Process.\n");        
        exit(0); 
  }
    return 0; 
} 

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int main(){
	int sumT[10];
	int a[1000];
	int ikr=0;
	for(int i=0;i<1000;i++){
		a[i]=i+1;		
	}
	int fd1[2];
	for(int l=0;l<10;l++){
		if(pipe(fd1)==-1){
			printf("pipe failed\n");
		}
			
		int cpid=fork();
		if(cpid==0){
			close(fd1[0]);		
			int sum1=0;
			for(int i=l*100;i<l*100+100;i++){
				sum1=sum1+a[i];	
			}
			ikr=sum1;
			write(fd1[1],&sum1,sizeof(sum1));
			close(fd1[1]);	
			exit(0);
		}
		else{
			wait(NULL);
			close(fd1[1]);
			sumT[l]=0;
			read(fd1[0],&sumT[l],sizeof(sumT[l]));
			printf("%d\n",sumT[l]);
		}
	}
	int totalSum=0;
	for(int i=0;i<10;i++){
		totalSum+=sumT[i];
	}
	printf("%d\n",totalSum);		
	return 0;
}

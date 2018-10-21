#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


void* AddNumber(void* start){
	int sum=0;
	int st=(int)start;
	for(int j=st;j<st+100;j++){
		sum+=j;
	}	
	return ((void*)sum);
}
int main(){
	pthread_t t1[10];
	int sum[10],i=1;
	for(int i=0;i<10;i++)
		sum[i]=0;
	for(i=0;i<10;i++)
		pthread_create(&t1[i],NULL,AddNumber,(void*)(i*100+1));
	for(int i=0;i<10;i++)
		pthread_join(t1[i],(void**)&sum[i]);
	int tSum=0;
	for(int i=0;i<10;i++){
		tSum+=sum[i];
		printf("Sum %d: %d\n",i+1,sum[i]);
	}
	printf("Total sum: %d\n",tSum);
	return 0;

}

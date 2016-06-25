#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define NUM 10000
#define N 4
#define CHILD (NUM/N)

int power(int x){
	int i;
	int result;
	if(x==0)	return 1;
	for(i=0;i<x;++i)	result*=-1;
	return result;
}

void *compute(void *arg){
	int *index,i;
	double *result;
	index=(int*)arg;
	*result=0;
	for(i=0+(*index)*CHILD;i<CHILD+(*index)*CHILD;++i){
		*result+=1.0/((2*i+1)*power(i));
	}
	return result;
}

int main(){
	int i;
	pthread_t workers[N];
	int s[N];
	for(i=0;i<N;++i)	s[i]=i;
	for(i=0;i<N;++i)	pthread_create(&workers[i],NULL,compute,s+i);
	double *result;
	double final;
	for(i=0;i<N;++i){
		pthread_join(workers[i],&result);
		final+=*result;
	}
	printf("%f\n",final);
	return 0;
}

#include<stdio.h>
#include<pthread.h>

int power(int x){
	int i;
	int result=1;
	if(x==0)	return 1;
	for(i=0;i<x;++i)	result*=-1;
	return result;
}

void *worker(void *arg){
	int i;
	float *result;
	int *num;
	float temp;
	num=(int*)arg;
	result=(float)*malloc(sizeof(float));
	*result=0;
	for(i=(*num)/2;i<*num;++i){
		temp=1.0/((2*i+1)*power(i));
		*result+=temp;
		printf("worker : %d\t%f\n",i+1,temp);
	}
	return result;
}

int main(){
	int i,num;
	int *p;
	pthread_t w_tid;
	printf("please input the num:");
	scan("%d",&num);
	p=&num;
	pthread_create(&w_tid,NULL,worker,p);
	float part2=0;
	float *part1;
	float temp;
	for(i=0;i<num/2;++i){
		temp=1.0/((2*i+1)*power(i));
		part2+=temp;
		printf("master : %d\t%f\n",i+1,temp);
	}
	pthread_join(w_tid,&part1);
	printf("%f\n",part2+*part1);
	return 0;
}

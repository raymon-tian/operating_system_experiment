#include<stdio.h>
#include<pthread.h>
#define N 10

int able_r;
int buffer[N];
pthread_mutex_t mutex_r;
pthread_cond_t cond_r;

void *send_receive(void *arg){
	int *p,i;
	p=(int *)arg;
	if((*p)==0){
		pthread_mutex_lock(&mutex_r);
		while(able_r!=*p)	pthread_cond_wait(&cond_r,&mutex_r);
		printf("process %d has received %d\n",((*p)+1)%(N+1),buffer[*p]);
		++buffer[*p];
		pthread_mutex_unlock(&mutex_r);
	}
	buffer[((*p)+1)%N] = (*p)+1;
	printf("process %d has sent %d to %d\n",((*p)+1)%(N+1),((*p)+1)%(N+1),((*p)+2)%(N+1));
	able_r=(able_r+1)%N;
	pthread_mutex_lock(&mutex_r);
	pthread_cond_broadcast(&cond_r);
	pthread_mutex_unlock(&mutex_r);
	if((*p)==0){
		pthread_mutex_lock(&mutex_r);
		while(able_r!=0)	pthread_cond_wait(&cond_r,&mutex_r);
		printf("process %d has received %d\n",((*p)+1)%(N+1),buffer[*p]);
		++buffer[*p];
		pthread_mutex_unlock(&mutex_r);
	}
	return NULL;
}

int main(){
	pthread_t tids[N];
	int tids_index[N];
	int i;
	for(i=0;i<N;++i)	tids_index[i]=i;
	for(i=0;i<N;++i)	pthread_create(tids+i,NULL,send_receive,tids_index+i);
	return 0;
}

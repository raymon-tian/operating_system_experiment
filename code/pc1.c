#include <stdio.h>
#include <pthread.h>
#define CAPACITY 4
#define TOTAL (2*CAPACITY)

int buffer0[CAPACITY];
int buffer1[CAPACITY];

pthread_mutex_t mutex;
pthread_cond_t cond0,cond1,cond2;
int able_r_from_p=0,able_r_from_c=0,able_w=1;

void producer(){
	int i,j;
	for(i=0;i<TOTAL;++i){
		pthread_mutex_lock(&mutex);
		while(!able_w)	pthread_cond_wait(&cond0,&mutex);
		j=i%CAPACITY;
		buffer0[j]=i+'a';
		able_w=0;
		able_r_from_p=1;
		pthread_cond_signal(&cond1);
		pthread_mutex_unlock(&mutex);
	}	
}
void *counter(void *arg){
	int i,j;
	for(i=0;i<TOTAL;++i){
		pthread_mutex_lock(&mutex);
		while(!able_r_from_p){
			pthread_cond_wait(&cond1,&mutex);
		}
		j=i%CAPACITY;
		buffer1[j]=i+'A';
		able_r_from_p=0;
		able_f_from_c=1;
		pthread_cond_signal(&cond2);
		pthread_cond_signal(&mutex);
	}
	return NULL;
}
void *consumer(void *arg){
	int i,j;
	for(i=0;i<TOTAL;++i){
		pthread_mutex_lock(&mutex);
		while(!able_w)	pthread_cond_wait(&cond2,&mutex);
		j=i%CAPACITY;
		printf("%c\n",buffer1[j]);
		able_r_from_c=0;
		able_w=1;
		pthread_cond_signal(&cond0);
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main(){
	pthread_t counter_tid,consumer_tid;

	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond0,NULL);
	pthread_cond_init(&cond1,NULL);
	pthread_cond_init(&cond2,NULL);
	pthread_create(&counter_tid,NULL,counter,NULL);
	pthread_create(&consumer_tid,NULL,consumer,NULL);
	producer();
	return 0;
}

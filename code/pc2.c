#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

typedef struct{
	int value;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
}sema_t;

void sema_init(sema_t *sema,int value){
	sema->value=value;
	pthread_mutex_init(&sema->mutex,NULL);
	pthread_cond_init(&sema->cond,NULL);
}

void sema_wait(sema_t *sema){
	sema->value--;
	pthread_mutex_lock(&sema->mutex);
	while(sema->value<0)	pthread_cond_wait(&sema->cond,&sema->mutex);
	pthread_mutex_unlock(&sema->mutex);
}

void sema_signal(sema_t *sema){
	sema->value++;
	pthread_mutex_lock(&sema->mutex);
	pthread_cond_signal(&sema->cond);
	pthread_mutex_unlock(&sema->mutex);
}

#define CAPACITY 4
#define TOTAL (2*CAPACITY)

sema_t full0,full1,empty0,empty1;
sema_t mutex0,mutex1;

int buffer0[CAPACITY];
int buffer1[CAPACITY];
int in0,in1,out0,out1;

void put_item0(int item){
	buffer0[in0] = item;
	in0=(in0+1)%CAPACITY;
}

void put_item1(int item){
	buffer1[in1] = item;
	in1=(in1+1)%CAPACITY;
}

void get_item0(){
	int item;
	item=buffer0[out0];
	out0=(out0+1)%CAPACITY;
	return item;
}

void get_item1(){
	int item;
	item=buffer1[out1];
	out1=(out1+1)%CAPACITY;
	return item;
}

void producer(){
	int i;
	for(i=0;i<TOTAL;++i){
		sema_wait(&full0);
		sema_wait(&mutex0);
		put_item0(i+'a');
		sema_signal(&mutex0);
		sema_signal(&full0);
	}
}

void *counter(void *arg){
	int i;
	int item;
	for(i=0;i<TOTAL;++i){
		sema_wait(&full0);
		sema_wait(&empty1);
		sema_wait(&mutex0);
		sema_wait(&mutex1);
		item=get_item0();
		put_item1(item-'a'+'A');
		sema_signal(&mutex1);
		sema_signal(&mutex0);
		sema_signal(&empty0);
		sema_signal(&full1);
	}
	return NULL;
}

void *consumer(void *arg){
	int i;
	int item;
	for(i=0;i<TOTAL;++i){
		sema_wait(&full1);
		sema_wait(&mutex1);
		item=get_item1();
		printf("%c\n",item);
		sema_signal(&mutex1);
		sema_signal(&empty1);
	}
	return NULL;
}

int main(){
	pthread_t counter_tid,consumer_tid;
	sema_init(&full0,0);
	sema_init(&full1,0);
	sema_init(&empty0,CAPACITY);
	sema_init(&empty1,CAPACITY);
	producer();
	return 0;
}

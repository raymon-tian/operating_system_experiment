#include<stdio.h>
#include<pthread.h>
#define MAX 100

int num;
int array[MAX];

void select_sort(int left,int right){
	int temp,i,j,k;
	for(i=left;i<right;++i){
		k=i;
		for(j=i+1;j<=right;++j)
			if(array[j]<array[k])	k=j;
		if(k!=i){
			temp=array[i];
			array[i]=array[k];
			array[k]=temp;
		}
	}
}

void merge_sort(int left,int mid,int right){
	int temp[MAX];
	int i,j,k;
	for(i=left;i<=right;++i)	temp[i]=array[i];
	i=left,j=mid+1,k=left;
	while(i<=mid&&j<=right){
		if(temp[i]<=temp[j])	array[k++]=temp[i++];
		else	array[k++]=temp[j++];
	}
	while(i<=mid)	array[k++]=temp[i++];
	while(j<=right)	array[k++]=temp[j++];
}

void *worker(void *arg){
	select_sort(num/2.num-1);
}

int main(){
	pthread_t w_tid;
	int i;
	printf("please input the number of array\n");
	scanf("%d",&num);
	printf("please input the array\n");
	for(i=0;i<num;++i){
		scanf("%d",array+i);
	}
	pthread_create(&w_tid,NULL,worker,NULL);
	select_sort(0,num/2-1);
	pthread_join(w_tid,NULL);
	merge_sort(0,num/2-1,num-1);
	for(i=0;i<num;++i)	printf("%d\t",array[i]);
	printf("\n");
	return 0;
}

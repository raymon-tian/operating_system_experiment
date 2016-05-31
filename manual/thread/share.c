#include <stdio.h>
#include <pthread.h>

char global;

void *worker(void *arg)
{
    printf("worker: %c\n", global);
    global = 'S';
    return NULL;
}

int main()
{
    pthread_t worker_tid;

    global = 'M';
    pthread_create(&worker_tid, NULL, worker, NULL);
    pthread_join(worker_tid, NULL);
    printf("master: %c\n", global);
    return 0;
}

// Output: 
// worker: 'M'
// master: 'S'

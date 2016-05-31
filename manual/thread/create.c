#include <stdio.h>
#include <pthread.h>

void *worker(void *arg)
{
    char i;

    for (i = 'a'; i < 'd'; i++) {
        printf("worker: %c\n", i); 
        sleep(1);
    }
    return NULL;
}

int main()
{
    char i;
    pthread_t worker_tid;

    pthread_create(&worker_tid, NULL, worker, NULL);
    for (i = 'A'; i < 'D'; i++) {
        printf("master: %c\n", i); 
        sleep(1);
    }
    return 0;
}

// Output:
// master: A
// worker: a
// master: B
// worker: b
// master: C
// worker: c

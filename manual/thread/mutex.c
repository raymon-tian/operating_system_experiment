#include <stdio.h>
#include <pthread.h>

int use_mutex;
pthread_mutex_t mutex;
volatile int global = 0;

void *compute(void *arg)
{
    int i;

    for (i = 0; i < 100 * 100 * 100; i++) {
        if (use_mutex) {
            pthread_mutex_lock(&mutex);
            global++;
            pthread_mutex_unlock(&mutex);
        } else
            global++;
    }
    return NULL;
}

void test()
{
    int i;
    pthread_t tids[3];

    global = 0;
    pthread_mutex_init(&mutex, NULL);
    for (i = 0; i < 3; i++)
        pthread_create(&tids[i], NULL, compute, NULL);

    for (i = 0; i < 3; i++)
        pthread_join(tids[i], NULL);
    printf("global = %d\n", global);
}

int main()
{
    use_mutex = 0;
    test();

    use_mutex = 1;
    test();
    return 0;
}

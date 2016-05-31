#include <stdio.h>
#include <pthread.h>

#define CAPACITY 4
int buffer[CAPACITY];
int in;
int out;

int buffer_is_empty()
{
    return in == out;
}

int buffer_is_full()
{
    return (in + 1) % CAPACITY == out;
}

int get_item()
{
    int item;

    item = buffer[out];
    out = (out + 1) % CAPACITY;
    return item;
}

void put_item(int item)
{
    buffer[in] = item;
    in = (in + 1) % CAPACITY;
}

pthread_mutex_t mutex;
pthread_cond_t wait_empty_buffer;
pthread_cond_t wait_full_buffer;

#define ITEM_COUNT (CAPACITY * 2)
void *consume(void *arg)
{
    int i;
    int item;

    for (i = 0; i < ITEM_COUNT; i++) {
        pthread_mutex_lock(&mutex);
       while (buffer_is_empty())
            pthread_cond_wait(
			   &wait_full_buffer, 
			   &mutex);

        item = get_item(); 
        printf("    consume item: %c\n", item);
        sleep(1);

        pthread_cond_signal(&wait_empty_buffer);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void produce()
{
    int i;
    int item;

    for (i = 0; i < ITEM_COUNT; i++) {
        pthread_mutex_lock(&mutex);
        while (buffer_is_full()) 
            pthread_cond_wait(&wait_empty_buffer, &mutex);

        item = i + 'a';
        printf("produce item: %c\n", item);
        put_item(item);
        sleep(1);

        pthread_cond_signal(&wait_full_buffer);
        pthread_mutex_unlock(&mutex);
    }
}

// The program contains a bug. Can you find it?
int main()
{
    pthread_t consumer_tid;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&wait_empty_buffer, NULL);
    pthread_cond_init(&wait_full_buffer, NULL);

    pthread_create(&consumer_tid, NULL, consume, NULL);
    produce();
    return 0;
}

// Output:
// produce item: a
// produce item: b
// produce item: c
//     consume item: a
// produce item: d
//     consume item: b
// produce item: e
//     consume item: c
//     consume item: d
//     consume item: e
// produce item: f
// produce item: g
// produce item: h
//
// produce item: a
// produce item: b
// produce item: c
//     consume item: a
// produce item: d
//     consume item: b
// produce item: e
//     consume item: c
// produce item: f
//     consume item: d
// produce item: g
//     consume item: e
// produce item: h

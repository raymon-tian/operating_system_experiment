#include <stdio.h>

#define POINTERS 1000
#define REGION_SIZE (4000 + 1000*16)

char region[REGION_SIZE];

struct block {
    struct block *next;
    struct block *prev;
    int in_use;
    int size;
    void data[0];
};

struct block free_list;

void my_malloc_init()
{
    struct block *block = region;

    block->in_use = 0;
    block->size = REGION_SIZE;
    // add block to free_list
}

void *my_malloc(int size)
{
}

void my_free(void *p)
{
}

void print_free_memory()
{
}

void test0()
{
    int size;
    void *p1, *p2;

    puts("Test0");

    p1 = mymalloc(10);
    print_free_memory();

    p2 = my_malloc(20);
    print_free_memory();

    my_free(p1);
    print_free_memory();

    my_free(p2);
    print_free_memory();
}

void test1()
{
    void *array[POINTERS];
    int i;
    void *p;

    puts("Test1");
    for (i = 0; i < POINTERS; i++) {
        p = my_malloc(4);
        array[i] = p;
    }

    for (i = 0; i < POINTERS; i++) {
        p = array[i];
        my_free(p);
    }

    print_free_memory();
}

void test2()
{
    void *array[POINTERS];
    int i;
    void *p;

    puts("Test1");
    for (i = 0; i < POINTERS; i++) {
        p = my_malloc(4);
        array[i] = p;
    }

    for (i = POINTERS - 1; i >= 0; i--) {
        p = array[i];
        my_free(p);
    }

    print_free_memory();
}

void test3()
{
    void *array[POINTERS];
    int i;
    void *p;

    puts("Test1");
    for (i = 0; i < POINTERS; i++) {
        p = my_malloc(4);
        array[i] = p;
    }

    for (i = 0; i < POINTERS; i += 2) {
        p = array[i];
        my_free(p);
    }

    for (i = 1; i < POINTERS; i += 2) {
        p = array[i];
        my_free(p);
    }

    print_free_memory();
}

int main()
{
    my_malloc_init();
    test0();
    test1();
    test2();
    test3();
    puts("Finished");
    return 0;
}

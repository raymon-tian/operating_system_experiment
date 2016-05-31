#include <stdio.h>
#include <stdlib.h>

#define POINTERS 1024

void print_free_memory()
{
}

void test0()
{
    int size;
    void *p1, *p2;

    puts("Test0");

    p1 = malloc(10);
    print_free_memory();

    p2 = malloc(20);
    print_free_memory();

    free(p1);
    print_free_memory();

    free(p2);
    print_free_memory();
}

void test1()
{
    void *array[POINTERS];
    int i;
    void *p;

    puts("Test1");
    for (i = 0; i < POINTERS; i++) {
        p = malloc(4);
        array[i] = p;
    }

    for (i = 0; i < POINTERS; i++) {
        p = array[i];
        free(p);
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
        p = malloc(4);
        array[i] = p;
    }

    for (i = POINTERS - 1; i >= 0; i--) {
        p = array[i];
        free(p);
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
        p = malloc(4);
        array[i] = p;
    }

    for (i = 0; i < POINTERS; i += 2) {
        p = array[i];
        free(p);
    }

    for (i = 1; i < POINTERS; i += 2) {
        p = array[i];
        free(p);
    }

    print_free_memory();
}

int main()
{
    test0();
    test1();
    test2();
    test3();
    puts("Finished");
    return 0;
}

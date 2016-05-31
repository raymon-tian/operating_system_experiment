#include <stdio.h>
#include <unistd.h>

void child()
{
    char c;
    for (c = 'a'; c < 'd'; c++) {
        printf("%c\n", c);
        sleep(1);
    }
}

void parent()
{
    char c;
    for (c = 'A'; c < 'D'; c++) {
        printf("%c\n", c);
        sleep(1);
    }
}

int main()
{
    int pid;
    pid = fork();
    if (pid == 0)
        child();        
    else
        parent();
    return 0;
}

// output:
// A
// a
// B
// b
// C
// c

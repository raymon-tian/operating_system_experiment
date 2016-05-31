#include <stdio.h>
#include <unistd.h>

int global;

void child()
{
    for (int i = 0; i < 3; i++) {
        printf("In child, global = %d\n", global);
        global++;
        sleep(1);
    }
}

void parent()
{
    for (int i = 0; i < 3; i++) {
        printf("In parent, global = %d\n", global);
        global++;
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
// In parent, global = 0
// In child, global = 0
// In parent, global = 1
// In child, global = 1
// In parent, global = 2
// In child, global = 2

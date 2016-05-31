#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid;
    pid = fork();
    if (pid == 0)
        printf("child : my = %x, parent = %x\n", getpid(), getppid());
    else
        printf("parent: my = %x, child = %x\n", getpid(), pid);
    return 0;
}

// output:
// parent: my = bf4, child = c00
// child : my = c00, parent = bf4

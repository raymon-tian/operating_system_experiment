#include <stdio.h>
#include <unistd.h>

void child()
{
    printf("Child process start\n");
    sleep(1);
    printf("Child process end\n");
    exit(0);
}

int main()
{
    int pid;
    pid = fork();
    if (pid == 0)
	child();
    waitpid(pid, NULL, 0);
    printf("Parent process end\n");
    return 0;
}

// output:
// Child process start
// Child process end
// Parent process end

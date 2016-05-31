#include <stdio.h>
#include <unistd.h>

void child()
{
    execlp("ls", "ls", "/", NULL);
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
// bin etc home lib sbin tmp usr var
// Parent process end

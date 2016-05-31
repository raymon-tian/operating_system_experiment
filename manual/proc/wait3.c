#include <stdio.h>
#include <unistd.h>

void child()
{
    int error;
    char line[80];
    printf("> ");
    gets(line);
    error = execlp(line, line, NULL);
    if (error == -1)
       fprintf(stderr, "Can't execute %s\n", line);
    exit(0);
}

int main()
{
    int i, pid;

    while (1) {
	pid = fork();
	if (pid == 0)
	    child();
	waitpid(pid, NULL, 0);
    }
    return 0;
}

// output:
// > ls
// a.exe fork1.c fork2.c wait1.c wait2.c wait3.
// > xx
// Can't execute xx 

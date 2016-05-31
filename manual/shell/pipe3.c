#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid;    
    int fd[2];
    char buf[32];

    pipe(fd);
    pid = fork();
    if (pid == 0) { 
        // child
        sleep(1); // let parent execute first
        dup2(fd[1], 1);
        close(fd[0]);
        close(fd[1]);

        write(1, "hello", 6);
        exit(0);
    }
    // parent will block
    dup2(fd[0], 0);
    close(fd[0]);
    close(fd[1]);

    read(0, buf, sizeof(buf));
    printf("Receive:%s\n", buf); 
    return 0;
}

// output:
// Receive:hello

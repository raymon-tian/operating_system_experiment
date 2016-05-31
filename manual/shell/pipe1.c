#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd[2];
    char buf[32];

    pipe(fd);
    write(fd[1], "hello", 6);
    read(fd[0], buf, sizeof(buf));
    printf("Receive:%s\n", buf); 
    return 0;
}
// output:
// Receive:hello

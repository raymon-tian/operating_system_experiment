#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd;
    fd = open("log", O_CREAT|O_RDWR, 0666);
    write(fd, "hello", 6); 
    close(fd);
    return 0;
}

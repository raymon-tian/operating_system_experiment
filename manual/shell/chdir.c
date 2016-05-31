#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd;
    char buf[512];
    int count;

    if (chdir("./dir") < 0) {
        perror("chdir failed");
        return 0;
    }

    fd = open("./data.txt", O_RDONLY);
    if (fd < 0) {
        perror("open failed");
        return 0;
    }
    count = read(fd, buf, sizeof(buf));
    buf[count] = 0;
    printf("read:%s\n", buf);
    close(fd);
    return 0;
}

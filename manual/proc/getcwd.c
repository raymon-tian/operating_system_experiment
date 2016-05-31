#include <stdio.h>
#include <unistd.h>

int main()
{
    char path[512];
    getcwd(path, sizeof(path));
    printf("path=%s\n", path);
    return 0;
}

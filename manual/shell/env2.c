#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
    printf("USER=%s\n", getenv("USER"));
    setenv("USER", "user", 1);
    printf("USER=%s\n", getenv("USER"));
    return 0;
}

// Output: 
// User=Administrator
// User=user

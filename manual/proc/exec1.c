#include <stdio.h>
#include <unistd.h>

// void execlp(program_path, arg0, arg1, ..., NULL);
int main()
{
    execlp("/bin/echo", "echo", "a", "b", "c", NULL);
    // execlp("echo", "echo", "a", "b", "c", NULL);
    return 0;
}
// output:
// a b c

#include <stdio.h>
#include <unistd.h>

// void execvp(program_path, argv);
int main()
{
    char *prog_argv[] = {"echo", "a", "b", "c", NULL};
    execvp("/bin/echo", prog_argv); 
    // execvp("echo", prog_argv); 
    return 0;
}
// output:
// a b c

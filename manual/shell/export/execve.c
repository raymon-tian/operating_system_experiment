#include <stdio.h>
#include <unistd.h>

// void execve(program_path, argv, envp);
int main()
{
    char *prog_argv[] = {"show-var.sh", NULL};
    char *prog_envp[] = {"VAR0=value0", "VAR1=value1", NULL};
    execve("./show-var.sh", prog_argv, prog_envp); 
    return 0;
}

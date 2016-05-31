#include <stdio.h>
#include <stdlib.h> 

void execute(char *command)
{
    system(command);
    printf(">> Command '%s' finished!\n\n", command);
}

int main()
{
    execute("ls /");
    execute("echo HelloWorld");
    return 0;
}

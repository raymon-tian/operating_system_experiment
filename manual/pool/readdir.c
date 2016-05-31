#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main()
{
    int error;
    DIR *dir;
    struct dirent entry;
    struct dirent *result;

    dir = opendir("/var");
    for (;;) {
        error = readdir_r(dir, &entry, &result);
        if (error != 0) {
            perror("readdir");
            return EXIT_FAILURE;
        }

        // readdir_r returns NULL in *result if the end 
        // of the directory stream is reached
        if (result == NULL)
            break;

        printf("%s\n", result->d_name);
    }
    closedir(dir);
    return 0;
}

// Program output:
//
// lost+found
// lib
// games
// spool
// opt
// .
// backups
// mail
// log
// local
// run
// lock
// ..
// crash
// cache

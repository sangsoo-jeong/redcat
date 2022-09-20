/*
Author: Sangsoo Jeong

test module
*/

#include "essential.h"

int checkPath(const char *path)
{
    // return 1 : file
    // return 2 : directory
    // return -1 : NONE

    char *tmp;
    intptr_t fileHandle;
    struct _finddata_t fileInfo;

    switch ((fileHandle = _findfirst(path, &fileInfo)))
    {
    case -1:
        tmp = malloc(1024);
        strcpy(tmp, "[+] path= ");
        strcat(tmp, path);
        strcat(tmp, " | Not directory or file");
        warning(tmp);
        free(tmp);
    }
    printf("%d\n", (int)fileHandle);
}
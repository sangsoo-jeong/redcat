/*
Author: Sangsoo Jeong

test module
*/

#include "essential.h"

// Parsing in order
// [1] Unknown path
// [2] Directory path
// [3] File path
int checkPath(const char *path)
{
    // return 1 : file
    // return 2 : directory
    // return -1 : NONE

    int fd = 0;
    char *tmp;
    intptr_t fileHandle;
    struct _finddata_t fileInfo;
    struct stat st;
    DIR *dir_info;
    struct dirent *dir_entry;

    // Issue : the _findfirst cannot recognise the directory if add ends with a character('/')
    // Solved by a exception [User Friendly]
    // Patched -> remove these lines [09/21/2022]

    fileHandle = _findfirst(path, &fileInfo);

    switch (fileHandle)
    {
    case -1:
        tmp = malloc(1024);
        strcpy(tmp, "[+] path= ");
        strcat(tmp, path);
        strcat(tmp, " | Not directory or file");
        free(tmp);
        return -1;
    }

    dir_info = opendir(path);
    if (dir_info != NULL)
    {
        printf("Directory\n");
        return 2;
    }

    if ((fd = open(path, 'r')) != -1)
    {
        printf("File\n");
        return 1;
    }
}

void optimize(char *path)
{
    int len = 0;
    len = strlen(path);
    if (path[len - 1] == '/')
    {
        path[len - 1] = '\0';
    }
}
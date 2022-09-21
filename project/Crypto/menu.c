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

    int len = 0;
    int fd = 0;
    char *copypath;
    char *tmp;
    intptr_t fileHandle;
    struct _finddata_t fileInfo;
    struct stat st;
    DIR *dir_info;
    struct dirent *dir_entry;

    // Issue : the _findfirst cannot recognise the directory if add ends with a character('/')
    // Solved by a exception [User Friendly]
    len = strlen(path);
    copypath = malloc(len);
    memset(copypath, 0, len);
    strcpy(copypath, path);
    if (copypath[len - 1] == '/')
    {
        copypath[len - 1] = '\0';
    }
    fileHandle = _findfirst(copypath, &fileInfo);

    switch (fileHandle)
    {
    case -1:
        tmp = malloc(1024);
        strcpy(tmp, "[+] path= ");
        strcat(tmp, copypath);
        strcat(tmp, " | Not directory or file");
        free(tmp);
        free(copypath);
        return -1;
    }

    dir_info = opendir(copypath);
    if (dir_info != NULL)
    {
        printf("Directory\n");
        free(copypath);
        return 2;
    }

    if ((fd = open(copypath, 'r')) != -1)
    {
        printf("File\n");
        free(copypath);
        return 1;
    }
}
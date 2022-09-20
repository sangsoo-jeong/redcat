/*
Author: Sangsoo Jeong

Application; File/Directory encryption and decryption sample
*/
#include "essential.h"

void manual();
void warning(const char *data);

extern int checkPath(const char *path);
extern intptr_t _findfirst(const char *filespec, struct _finddata_t *fileinfo);

int main(int argc, char *argv[])
{
    int checker = 0;
    MenuSet struct_MenuSet = {0, 0, 0, 1, 0, 0};
    DataSet struct_DataSet = {
        0,
    };

    if (argc == 1)
    {
        printf("Check Again\n");
        exit(-1);
    }

    while ((checker = getopt(argc, argv, "i:o:a:v:e:d")) != NONE)
    {
        switch (checker)
        {
        case 'i':
            struct_DataSet.element_input = malloc(strlen(optarg) + 1);
            strcpy(struct_DataSet.element_input, optarg);
            struct_MenuSet._flag[INPUT] = 1;
            break;

        case 'o':
            struct_DataSet.element_output = malloc(strlen(optarg) + 1);
            strcpy(struct_DataSet.element_output, optarg);
            struct_MenuSet._flag[OUTPUT] = 1;
            break;

        case 'a':
            struct_DataSet.element_algorithm = malloc(strlen(optarg) + 1);
            strcpy(struct_DataSet.element_algorithm, optarg);
            struct_MenuSet._flag[ALGO] = 1;
            break;

        case 'v':
            struct_MenuSet._flag[VERBOSE] = 1;
            break;

        case 'e':
            // AES128, AES256, RSA
            break;

        case 'd':
            // AES128, AES256, RSA
            struct_MenuSet._flag[DEC] = 1;
            struct_MenuSet._flag[ENC] = 0;
            break;

        default:
            printf("Check again");
            manual();
            exit(-1);
        }
    }

    if (struct_MenuSet._flag[INPUT] && struct_MenuSet._flag[OUTPUT] == FALSE)
    {
        warning("You forgot the option input or output");
    }
    if (!strcmp(struct_DataSet.element_input, struct_DataSet.element_output))
    {
        warning("Input and Output path must set different");
    }
    // case 'd'에서 ENC를 0로 바꾸어버려서 접근할 수는 없음
    if (struct_MenuSet._flag[ENC] && struct_MenuSet._flag[DEC] == TRUE)
    {
        warning("You should check only one");
    }

    // The input path is real?
    if (checkPath(struct_DataSet.element_input) == -1)
    {
        warning("You should check only one");
    }
    return 0;
}

void warning(const char *data)
{
    printf("%s\n", data);
    exit(-1);
}

void manual()
{
}

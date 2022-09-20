/*
Author: Sangsoo Jeong

Application; File/Directory encryption and decryption sample
*/

#include "essential.h"
#include "menu.h"
void manual();

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
        printf("You forgot the option input or output\n");
        exit(-1);
    }
    if (!strcmp(struct_DataSet.element_input, struct_DataSet.element_output))
    {
        printf("Input and Output path must set different\n");
        exit(-1);
    }

    return 0;
}

void manual()
{
}
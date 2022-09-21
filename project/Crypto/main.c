/*
Author: Sangsoo Jeong

Application; File/Directory encryption and decryption sample
*/
#include "essential.h"

void manual();
void warning(const char *data);

extern void optimize(char *path);
extern int checkPath(const char *path);
extern intptr_t _findfirst(const char *filespec, struct _finddata_t *fileinfo);

int main(int argc, char *argv[])
{
    int checker = 0;
    int count = 0;
    MenuSet struct_MenuSet = {0, 0, 0, 1, 0, 0};
    DataSet struct_DataSet = {
        0,
    };

    if (argc == 1)
    {
        printf("Check Again\n");
        exit(-1);
    }

    // Patch
    // Before: i:o:a:v:e:d
    // After : i:o:a:v:ed
    // Intent: 'e' and 'd' are only check options, but do not store data anything
    while ((checker = getopt(argc, argv, "i:o:a:c:v:ed")) != NONE)
    {
        switch (checker)
        {
        case 'i':
            struct_DataSet.element_input = malloc(strlen(optarg) + 1);
            strcpy(struct_DataSet.element_input, optarg);
            // Origin: Remove the ends with '/' on the checkPath function
            // Changed: Remove the ends with '/' on the main function
            optimize(struct_DataSet.element_input);
            struct_MenuSet._flag[INPUT] = 1;
            count++;
            break;

        case 'o':
            struct_DataSet.element_output = malloc(strlen(optarg) + 1);
            strcpy(struct_DataSet.element_output, optarg);
            struct_MenuSet._flag[OUTPUT] = 1;
            count++;
            break;

        case 'a':
            struct_DataSet.element_algorithm = malloc(strlen(optarg) + 1);
            strcpy(struct_DataSet.element_algorithm, optarg);

            // To check correct algorithm name
            if (!strcasecmp(struct_DataSet.element_algorithm, AES128_STR) ||
                !strcasecmp(struct_DataSet.element_algorithm, AES256_STR) ||
                !strcasecmp(struct_DataSet.element_algorithm, RSA_STR))
            {
                struct_MenuSet._flag[ALGO] = 1;
                count++;
            }

            else
            {
                struct_MenuSet._flag[ALGO] = 0;
                warning("If you want to run this program, please double check your algorithm");
            }

            break;

        case 'c': // CBC , ECB .. TODO
            break;

        case 'v':
            struct_MenuSet._flag[VERBOSE] = 1;
            break;

        case 'e':
            count++;
            break;

        case 'd':
            // AES128, AES256, RSA
            struct_MenuSet._flag[DEC] = 1;
            struct_MenuSet._flag[ENC] = 0;
            count++;
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
        warning("You should check only one Encrypt or Decrypt");
    }

    if (count < 4)
    {
        warning("I am sorry you need to add another parameter");
    }

    printf("[input] %s\n", struct_DataSet.element_input);
    printf("[output] %s\n", struct_DataSet.element_output);

    // The input path is real?
    checker = checkPath(struct_DataSet.element_input);
    struct_DataSet.file_attribute = checker;

    if (checker == -1)
    {
        warning("File or Directory is not existed. Please Check Again");
    }
    // File encrypt | decrypt
    // Encryption
    if (checker == 1 && struct_MenuSet._flag[ENC])
    {
        printf("Accessing %s\n", struct_DataSet.element_algorithm);

        // TODO
        // Refactorying -> Parameter use structure directly
        encrypt(struct_DataSet);
    }
    // Decryption
    else if (checker == 1 && struct_MenuSet._flag[DEC])
    {
        printf("Accessing %s\n", struct_DataSet.element_algorithm);
    }
    // Directory encrypt | decrypt
    // Scenario: When the directory is encrypted, the file inside the directory is also encrypted
    if (checker == 2)
    {
        encrypt(struct_DataSet);
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

/*
Author: Sangsoo Jeong

This header file's intent is menu bar.
*/

/**************************************************************/
#ifndef MENU_H_
#define MENU_H_
#pragma once
#define AES128 (1)
#define AES256 (2)
#define RSA (3)
#define INPUT (0)
#define OUTPUT (1)
#define ALGO (2)
#define ENC (3)
#define DEC (4)
#define VERBOSE (5)
#define AES128_STR "AES128"
#define AES256_STR "AES256"
#define RSA_STR "RSA"
/**************************************************************/
// TODO
// element_InputFlag와 element_OutputFlag는 and 연산 결과 반드시 1이 되어야 한다.

typedef struct MenuSet
{
    int _flag[6];
    // int element_OutputFlag;
    // int element_AlgorithmFlag;
    // int element_EncrpytionFlag;
    // int element_DecryptionFlag;
    // int element_VerboseFlag;
} MenuSet;

typedef struct DataSet
{
    int file_attribute;
    char *element_input;
    char *element_output;
    char *element_algorithm;
} DataSet;

int checkPath(const char *path);
void optimize(char *path);
#endif
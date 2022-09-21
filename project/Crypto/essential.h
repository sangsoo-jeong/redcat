#ifndef ESSENTIAL_H_
#define ESSENTIAL_H_

#ifdef WIN32
#include <io.h> // _findfirsti64
#else
#include "findfirst.h"
#include "spec.h"
#endif
#include <stdio.h>  // standard related to input/output
#include <string.h> // strcpy
#include <unistd.h> // getopt
#include <stdlib.h> // exit
#include <fcntl.h>  // fstat
#include <dirent.h> // opendir
#include "menu.h"
#include "algo.h"
#define TRUE (1)
#define FALSE (0)
#define NONE (-1)

//#define PRINT(data) printf(data)

#endif
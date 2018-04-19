//
// Created by Vinicius de Sa Souza on 2/17/16.
//

#ifndef PHP_5_6_18_LIBRARY_H
#define PHP_5_6_18_LIBRARY_H
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include "php.h"


void loadDarumaFramework();
void unloadDarumaFramework();
void* loadFunctionDarumaFramework(const char* nameFunction);

#endif //PHP_5_6_18_LIBRARY_H

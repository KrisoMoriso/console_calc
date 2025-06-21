#ifndef SPLIT_STRING_H
#define SPLIT_STRING_H
#include <iostream>

struct split_string_return_struct{
    double *pNums;
    char *pOps;
    int nums_size;
    int ops_size;
};


split_string_return_struct split_string(std::string usr_inp);
#endif
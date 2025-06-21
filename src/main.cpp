#include <iostream>
#include <time.h>
#include "../header_files/split_string.h"
#include "../header_files/eval_no_parentheses.h"

int main()
{
    double *pNums;
    char *pOps;
    int nums_size;
    int ops_size;
    std::string usr_inp = "2+2*2";
    // std::cin >> usr_inp;
    clock_t tStart = clock();

    split_string_return_struct return_struct = split_string(usr_inp);
    pNums = return_struct.pNums;
    pOps = return_struct.pOps;
    nums_size = return_struct.nums_size;
    ops_size = return_struct.ops_size;
    
    double eval = eval_no_parentheses(return_struct);
    std::cout << eval << '\n';
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    delete[] pNums;
    delete[] pOps;
    return 0;
}

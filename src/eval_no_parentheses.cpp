#include <iostream>
#include <time.h>
#include "../header_files/split_string.h"
#include "../header_files/eval_no_parentheses.h"


double eval_no_parentheses(split_string_return_struct gotten_struct){
    double *pNums;
    char *pOps;
    int nums_size;
    int ops_size;
    pNums = gotten_struct.pNums;
    pOps = gotten_struct.pOps;
    nums_size = gotten_struct.nums_size;
    ops_size = gotten_struct.ops_size;

    bool did_finish_eval = false;

    while (!did_finish_eval){
        did_finish_eval = true;
        for(int i = 0; i <= ops_size; i++){
            if(pOps[i] == '*' or pOps[i] == '/'){
                double temp_eval;
                switch (pOps[i])
                {
                case '*':
                    temp_eval = pNums[i] * pNums[i+1];
                    break;
                case '/':
                    temp_eval = pNums[i] / pNums[i+1];
                    break;
                }
                ops_size--;
                for(int j = i; j <= ops_size; j++){ //delete the operand that was evaluated
                    pOps[j] = pOps[j+1];
                }
                nums_size--;
                pNums[i] = temp_eval;
                // std::cout << temp_eval << "ln: 111" << '\n';
                for(int j = i + 1; j <= nums_size; j++){
                    pNums[j] = pNums[j+1];
                }
                did_finish_eval = false;
                break;
            }
            }
    }
    

    double eval = pNums[0];
    for(int i = 0; i < ops_size; i++){
        switch(pOps[i])
        {
        case '+':
            eval += pNums[i + 1];
            break;
        case '-':
            eval -= pNums[i + 1];
            break;
        }
    }
    return eval;
}
#include <iostream>
#include "../header_files/split_string.h"
#include "../header_files/eval_no_parentheses.h"

split_string_return_struct eval_parentheses(split_string_return_struct gotten_struct){
    double *pNums;
    char *pOps;
    int nums_size;
    int ops_size;
    pNums = gotten_struct.pNums;
    pOps = gotten_struct.pOps;
    nums_size = gotten_struct.nums_size;
    ops_size = gotten_struct.ops_size;

    bool did_finish_eval = false;
    // std::cout << ops_size << "ops size" << '\n';
    while (!did_finish_eval){
        did_finish_eval = true;
        int open_parentheses_index;
        int close_parentheses_index;
        for(int i = 0; i < ops_size; i++){
            if(pOps[i] == '('){
                open_parentheses_index = i;
                did_finish_eval = false;
            } else if (pOps[i] == ')') {
                close_parentheses_index = i;
                did_finish_eval = false;
                break;
            }
        }
        // for(int i = 0; i < ops_size; i++){
        //     std::cout << pOps[i] << '\n';
        // }
        // std::cout << did_finish_eval << '\n';
        if(did_finish_eval){
            continue;
        }
        // std::cout << open_parentheses_index << '\n' << close_parentheses_index << '\n';
        double temp_pNums[close_parentheses_index - open_parentheses_index];
        char temp_pOps[close_parentheses_index - open_parentheses_index];

        int temp_nums_size = close_parentheses_index - open_parentheses_index;//2
        int temp_ops_size = close_parentheses_index - open_parentheses_index - 1;

        for(int i = 0; i < temp_nums_size; i++){
           temp_pNums[i] = pNums[i + open_parentheses_index];
        }
        for(int i = 0; i < temp_ops_size; i++){
            temp_pOps[i] = pOps[i + open_parentheses_index + 1];
        }




        // for(int i = 0; i < temp_nums_size; i++){
        //     std::cout << temp_pNums[i] << '\n';
        // }
        // for(int i = 0; i < temp_ops_size; i++){
        //     std::cout << temp_pOps[i] << '\n';
        // }
        split_string_return_struct temp_return_struct;
        temp_return_struct.pNums = temp_pNums;
        temp_return_struct.pOps = temp_pOps;
        temp_return_struct.nums_size = temp_nums_size;
        temp_return_struct.ops_size = temp_ops_size;
        double temp_eval = eval_no_parentheses(temp_return_struct);
        // std::cout << temp_eval << '\n';


        ops_size -= close_parentheses_index - open_parentheses_index + 1;
        for(int i = open_parentheses_index; i <= ops_size; i++){ //delete the operand that was evaluated
            pOps[i] = pOps[i+temp_ops_size];
        }
        nums_size -= close_parentheses_index - open_parentheses_index - 1;

        pNums[open_parentheses_index] = temp_eval;
        for(int i = open_parentheses_index + 1; i <= nums_size; i++){
            pNums[i] = pNums[i+1];
        }

        // for(int i = 0; i < nums_size; i++){
        //     std::cout << pNums[i] << '\n';
        // }
        // for(int i = 0; i < ops_size; i++){
        //     std::cout << pOps[i] << '\n';
        // }
    }

    split_string_return_struct return_struct;
    return_struct.pNums = pNums;
    return_struct.pOps = pOps;
    return_struct.nums_size = nums_size;
    return_struct.ops_size = ops_size;

    return return_struct;
}
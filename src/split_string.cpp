#include <iostream>
#include "../header_files/split_string.h"

split_string_return_struct split_string(std::string usr_inp){

    int num_start_index;
    bool did_enc_num = false;
    int num_end_index;

    double *pNums = NULL;
    int nums_to_set = 0;
    char *pOps = NULL;
    int ops_to_set = 0;

    int nums_size = 1;
    int ops_size = 0;
    for(int i = 0; i < usr_inp.length(); i++){
        if(usr_inp[i] == '+' or usr_inp[i] == '-' or usr_inp[i] == '/' or usr_inp[i] == '*'){
            nums_size++;
            ops_size++;
        }
    }
    pNums = new double[nums_size];
    pOps = new char[ops_size];

    for(int i = 0; i <= usr_inp.length(); i++){
        if(usr_inp[i] == '+' or usr_inp[i] == '-' or usr_inp[i] == '/' or usr_inp[i] == '*' or i == usr_inp.length()){
            num_end_index = i - 1;
            if (!(i == usr_inp.length())){
                pOps[ops_to_set] = usr_inp[i];
                ops_to_set++;
            }

            int num_length = (num_end_index - num_start_index);
            char temp[num_length + 1];
            for(int i = 0; i <= num_length; i++){
                temp[i] = usr_inp[i + num_start_index];
            }
            temp[num_length + 1] = ' ';

            pNums[nums_to_set] = std::atof(temp);
            nums_to_set++;
            did_enc_num = false;

        } else if (!did_enc_num){
            num_start_index = i;
            did_enc_num = true;
        }
    }
    split_string_return_struct return_struct;
    return_struct.pNums = pNums;
    return_struct.pOps = pOps;
    return_struct.nums_size = nums_size;
    return_struct.ops_size = ops_size;

    return return_struct;

    
}
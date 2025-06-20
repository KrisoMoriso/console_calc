#include <iostream>
#include <cmath>
#include <time.h>

struct split_string_return_struct{
    double *pNums;
    char *pOps;
    int nums_size;
    int ops_size;
};

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


int main()
{
    double *pNums;
    char *pOps;
    int nums_size;
    int ops_size;
    std::string usr_inp = "199+2";
    std::cin >> usr_inp;
    clock_t tStart = clock();

    split_string_return_struct return_struct = split_string(usr_inp);
    pNums = return_struct.pNums;
    pOps = return_struct.pOps;
    nums_size = return_struct.nums_size;
    ops_size = return_struct.ops_size;
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
        case '*':
            eval *= pNums[i + 1];
            break;
        case '/':
            eval /= pNums[i + 1];
            break;
        default:
            break;
        }
    }

    std::cout << eval << '\n';
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    delete[] pNums;
    delete[] pOps;
    return 0;
}

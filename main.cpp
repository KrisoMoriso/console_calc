#include <iostream>
#include <cmath>
#include <time.h>

struct split_string_return_struct{
    double a;
    double b;
    char op;
};

split_string_return_struct split_string(std::string usr_inp){

    int num_start_index = 0;
    int num_end_index;

    double a;
    double b;
    char op;
    
    for(int i = 0; i <= usr_inp.length(); i++){
        if(usr_inp[i] == '+' or usr_inp[i] == '-' or usr_inp[i] == '/' or usr_inp[i] == '*'){
            op = usr_inp[i];
            num_end_index = i-1;
            int num_length = (num_end_index - num_start_index);
            char temp[num_length+1];
            for(int i = 0; i < num_length+1; i++){
                temp[i] = usr_inp[i + num_start_index];
            }
            a = std::atof(temp);
            num_start_index = i+1;
        } 
        else if (i == usr_inp.length()){
            num_end_index = i;
            int num_length = (num_end_index - num_start_index);
            char temp[num_length+1];
            for(int i = 0; i < num_length+1; i++){
                temp[i] = usr_inp[i + num_start_index];
            }
            b = std::atof(temp);
        }
    }
    split_string_return_struct return_struct;
    return_struct.a = a;
    return_struct.b = b;
    return_struct.op = op;
    return return_struct;
}


int main()
{
    double a;
    double b;
    char op;
    std::string usr_inp;
    std::cin >> usr_inp;
    clock_t tStart = clock();

    split_string_return_struct return_struct = split_string(usr_inp);
    a = return_struct.a;
    b = return_struct.b;
    op = return_struct.op;

    double c;
    
    switch (op)
    {
    case '+':
    c = a + b;
        break;

    case '-':
        c = a - b;
        break;
    case '*':
        c = a*b;
        break;
    case '/':
        c = a/b;
        break;
    
    default:
        break;
    }

    std::cout << "Result: " << c << '\n';

    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);


    return 0;
}

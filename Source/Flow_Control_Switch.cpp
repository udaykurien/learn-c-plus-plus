#include <iostream>

int main(){

    /*
    - Alternate and compact way to test if-else conditionals.
    - The cases within a switch must be a constant (integral-int,char or an enum type) and can not be a string or array.
    - As soon as a case is matched, its instructions are executed and the break returns control to the next line of code after the switch block.
    - Curly braces can optionally be used to define scope following the case statement of a switch block.
    - If break isn't use, every case after the matching case is executed.
    */

    int num1 {5};
    const int case1 {1};
    const int case2{2};

    std::cout<<"The number is: "<<num1<<std::endl;

    switch(num1){
        case case1:{
            std::cout<<"The number is 1"<<std::endl;
        }
            break;
        case (case2):
            std::cout<<"The number is 2"<<std::endl;
            break;
        case 3:
            std::cout<<"The number is 3"<<std::endl;
            break;
        case 4:
        case 5:
        case 6:
            std::cout<<"The number is either 4,5 or 6"<<std::endl;
            break;
        default:
            std::cout<<"Input does not match any of the switch cases"<<std::endl;
            break;
    }

    return 0;
}
#include <iostream>
int main() {
    
    /*
    Sequential conditionals. Test several conditions. As soon as a condition is satisfied, the instructions within its scope is implemented and then control is passed to the next statement after the if-else conditional code block.
    */

    int num1 {20};

    std::cout<<"The number is: "<<num1<<std::endl;

    if(num1 < 10) {
        std::cout << "Number is less than 10" << std::endl;
    }
    else if (num1>30){
        std::cout<<"Number is greater than 30"<<std::endl;
    }
    else if (num1>10 && num1<30){
        std::cout<<"Number is between 10 and 30"<<std::endl;
    }
    else if (num1 == 20){
        std::cout<<"The number is the middle of 10 and 30"<<std::endl;
    }
    else {
        std::cout<<"Input error"<<std::endl;
    }

    return 0;
}
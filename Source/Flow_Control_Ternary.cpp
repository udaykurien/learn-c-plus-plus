#include<iostream>

int main() {

    /*
    result = (conditional expression) ? option1 : option2 ;
    if condition is true then result = option1
    if condition is false then result = option2
    - option1 and option2 must be of the same type (or can be auto type converted eg float to int) and should match the type of result.
    */

    int num1 {10};
    int num2 {15};
    int max, min;

    std::cout<<"Num1 is: " << num1 << std::endl << "Num2 is: " << num2 <<std::endl;

    max = (num1>num2) ? num1 : num2; // Ternamry expression to find max
    /*
    Syntactic sugar / shorthand for:
    if (num1 > num2 ) {
        max = num1
    }
    else if (num1 < num2) {
        max = num2
    }
    */
    min = (num1>num2) ? num2 : num1; // Ternary expression to find min

    std::cout << "Max is: " << max << std::endl;
    std::cout << "Min is: " << min << std::endl;

    bool fast = false;
    int speed {fast ? 300:100}; // Ternary initialization

    std::cout <<"Speed from ternary initialization: " << speed << std::endl;

    return 0;
}
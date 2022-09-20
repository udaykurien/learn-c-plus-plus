#include <iostream>

int main()
{
    /*
    Sum: result_var = var1 + var2
    Subtract: result_var = var1 - var2
    Mult: result_var = var1 * var2
    Div: result_var = var1 / var2
    If var1 and var2 = int then var1/var2 returns only quotient
    Modulus: result_var = var1 % var2
    If var1 and var2 = int then var1 % var2 returns remainder
    */

    // Addition
    int num1 {2};
    int num2 {7};
    int result = num1 + num2;
    std::cout << "num1: " << num1 << "\nnum2:" << num2 <<std::endl;
    std::cout << "num1+num2: " << result << std::endl;

    // Subtraction
    int result1 = num1 -num2;
    std::cout<<"num1-num2: "<<result1<<std::endl;
    int result2 = num2 -num1;
    std::cout<<"num2-num1: "<<result2<<std::endl;

    // Multiplication
    result = num1 * num2;
    std::cout<<"num1*num2: "<<result<<std::endl;

    // Integer divison (remainder or fraction is truncated)
    int result3 = num2/num1;
    std::cout << "num2/num1, result var type int: " << result3 << std::endl;
    float result4 = num2/num1;
    std::cout << "num2/num1, result var type float: " << result4 << std::endl;

    // Modulus
    result = num2 % num1;
    std::cout << "num2 % num1: " << result << std::endl;

    return 0;
}
#include <iostream>

int addNumbers (int num_1, int num_2)
{
    int sum;
    sum = num_1 + num_2;
    return sum;
}

int main ()
{
    int number1, number2, result;
    int number3 {7}; // another way to assign a variable
    number3 = 8;
    number1 = 9;
    number2 = 12;
    result = addNumbers(number1,number2);
    std::cout<<"Sum: "<<result<<"\n";
    std::cout<<"number3: "<<number3<<std::endl;

    return 0;
}
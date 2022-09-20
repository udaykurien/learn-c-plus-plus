#include <iostream>

int main()
{
    /*
    Shorthand to update a variable via a mathematical operation
    eg. value = value / 3 => value /= 3 (similarly for +,-,*,%,/)
    */

    int value {45};
    std::cout << "Original Value: " << value << std::endl; // 45

    value += 5;
    std::cout << "value += 5 : " << value << std::endl; // 50

    value -= 5;
    std::cout << "value -=5 : " << value << std::endl; // 45

    value *= 2;
    std::cout << "value *=2 : " << value << std::endl; // 90

    value /= 3;
    std::cout << "value /=3 : " << value << std::endl; // 30

    value %= 11;
    std::cout << "value %=11 : " << value << std::endl; // 8

    return 0;
}
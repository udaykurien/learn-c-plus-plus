#include <iostream>

int main()
{
    int num1 = 15; // Decimal
    int num2 = 017; // Octal
    int num3 = 0x0F; // Hexadecimal
    int num4 = 0b00001111; // Binary (8-bit in this case)
    // Representaion of all of the above in memory is the same
    // i.e. binary representation

    std::cout<<"Decimal: "<<num1<<std::endl;
    std::cout<<"Octal: "<<num2<<std::endl;
    std::cout<<"Hexadecimal: "<<num3<<std::endl;
    std::cout<<"Binary: "<<num4<<std::endl;

    return 0;
}
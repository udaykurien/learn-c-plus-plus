#include <iostream>

int main()
{
    /*
    Data type: char
    Used for: letters
    Size: 8 bits or 1 byte -> 2^8 or 256 possible values or 256 distinct characters can be represented by a 8 bit char data type (ASCII encoding)
    
    ASCII (A) = 65
    ASCII (a) = 97
    ASCII(a) - ASCII(A) = 32
    ASCII(A) + 7 = 65+7 = 72
    ASCII(72) = H
    ASCII(5) = 53 //Numbers can be interpreted as ints or characters.
    */

    char character1 {'a'};
    std::cout << "character1: " <<character1 << std::endl;
    std::cout << "int(character1): " << static_cast<int>(character1) << std::endl;
    std::cout << std::endl;

    std::cout << "size of character: " << sizeof(char) << " bytes" << std::endl;
    std::cout << std::endl;

    char value = 65; // ASCII code for 'A'
    char value2 = value + 32;
    std::cout << "value: " << value << std::endl;
    std::cout << "int(value): " << static_cast<int>(value) <<std::endl;
    std::cout << "value+32: " << value+32 <<std::endl;
    std::cout << "char value2 = value + 32: " << value2 << std::endl;

    return 0;
}
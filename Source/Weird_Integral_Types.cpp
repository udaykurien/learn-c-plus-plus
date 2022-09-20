#include <iostream>

int main()
{
    /*
    Integral types < 4 bytes don't support ariithmetic operations (+,-,/,*)
    eg. char (1 byte), short int (2 bytes)
    why? - relatedd to processor design. by convention int is chosen as the shortest data type to perform arithmetic operations.
    compilers recognize programmer intent and implicitly converts weird integral types to ints for arithmetic operations
    */

    short int var1 {10};
    short int var2 {20};

    char var3 {30};
    char var4 {50};

    std::cout << "Size of var1: " << sizeof(var1) << std::endl;
    std::cout << "Size of var2: " << sizeof(var2) << std::endl;
    std::cout << "Size of var3: " << sizeof(var3) << std::endl;
    std::cout << "Size of var4: " << sizeof(var4) << std::endl;

    auto result1 = var1 + var2;
    auto result2 = var3 + var4;

    std::cout << "Size of result1 = var1 + var2 : " << sizeof(result1) << std::endl;
    std::cout << "Size of result1 = var3 + var4 : " << sizeof(result2) << std::endl;

    return 0;
}
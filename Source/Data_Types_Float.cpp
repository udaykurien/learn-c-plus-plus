#include <iostream>
#include <iomanip>

int main()
{
    /*
    Type        Size    Precesion(digits)
    float       4       7
    double      8       12
    long double 16      >double
    Precision uses all digits before and after decimal
    Size can depend on compiler used
    Watch out of narrowing conversion
    */

    /*
    With floating point numbers:
    * float num/0 returns +/- infinity
    * 0.0/0.0 returns NaN
    In both these cases, the program doesn't crash.
    */
    
    // Declare floats
    // Standard notation
    float number1 {1.12345678901234567890f}; //f (suffix)-> tell compiler that then number is floating point. Without this the compiler will interpret the number as a simple double
    // Since the precision is 7 digits all digits after the 7th digit will be garbage
    double number2 {1.12345678901234567890}; // no suffix
    //precision is 15 digits
    long double number3 {1.12345678901234567890L}; // L (suffix)
    //precision is 19 digits
    // Scientific notation:
    double number5 {192400023};
    double number6 {1.92400023e8};
    double number7 {1.924e8};
    double number8 {0.00000000003498};
    double number9 {3.498e-11};

    // Print size of float types
    std::cout << "size of float: " << sizeof(float) << std::endl;
    std::cout << "size of double: " << sizeof(double) << std::endl;
    std::cout << "size of long double: " << sizeof(long double) << std::endl;

    // Print declared variables
    std::cout << std::setprecision(20); // control precision from std::cout
    std::cout << "number1 is: " << number1 << std::endl;
    std::cout << "number2 is: " << number2 << std::endl;
    std::cout << "number3 is: " << number3 << std::endl;

    // Float calculations - inf and nan
    float num01 {}; // initialize num01 to 0
    float num02 {};
    float numVal1 {5.6};
    float numVal2 {-3.7};

    std::cout << num01 << "/" << num02 << " : " << num01/num02 << std::endl;
    std::cout << numVal1 << "/" << num02 << " : " << numVal1/num02 << std::endl;
    std::cout << numVal2 << "/" << num02 << " : " << numVal2/num02 << std::endl;

    return 0;
}
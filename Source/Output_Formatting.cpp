#include <iostream>
// Formatting libraries
#include <ios>
#include <iomanip>

int main()
{
    /*
    1. Look up diff between endl and \n
    */

    // std::endl - move to new line
    std::cout << "Hello world" << std::endl;

    // std::flush - empty output buffer to terminal ie don't wait for output buffer to fill before printing to terminal
    std::cout << "Hellow world" << std::endl << std::flush;

    // std::setw(n) - specifies width for whatever text we want to print. Text will be printed in field n characters wide
    std::cout << std::setw(20) << "Last name" << std::setw(20) << "First name" << std::setw(10) << "Age" << std::endl;
    std::cout << std::setw(20) << "Randome" << std::setw(20) << "Person" << std::setw(10) << "20" << std::endl;
    // std::right or std::left - right, left, internal justification
    std::cout << std::endl;
    std::cout << "Right justification" << std::endl;
    std::cout << std::right;
    std::cout << std::setw(20) << "Right" << std::setw(20) << "Justification" << std::setw(10) << "32" << std::endl;
    
    std::cout << std::endl;
    std::cout << "Left justification" << std::endl;
    std::cout << std::left;
    std::cout << std::setw(20) << "Last name" << std::setw(20) << "First name" << std::setw(10) << "Age" << std::endl;
    std::cout << std::setw(20) << "Left" << std::setw(20) << "Justification" << std::setw(10) << "43" << std::endl;
    
    std::cout << std::endl;
    std::cout << "Internal justification" << std::endl;
    std::cout << std::internal;
    std::cout << std::setw(20) << "Neg Num" << std::setw(20) << "Positive num" << std::endl;
    std::cout << std::setw(20) << -123.45 << std::setw(20) << 123.45 << std::endl;

    // std::setfill(' ') - sets fill character
    std::cout << std::endl;
    std::cout << "Fill character" << std::endl;
    std::cout << std::setfill('-');
    std::cout << std::setw(20) << "Randome" << std::setw(20) << "Person" << std::setw(10) << "20" << std::endl;
    
    // std::boolalpha, std::noboolalpha - shows boolean as true and false instead of 0 and 1
    std::cout << std::endl;
    std::cout << std::noboolalpha;
    std::cout << "Numerica representation of booleans" << std::endl;
    std::cout << true << "----------" << false <<std::endl;
    std::cout << std::boolalpha;
    std::cout << "Char representation of booleans, std::boolalpha" << std::endl;
    std::cout << true << "----------" << false <<std::endl;
    
    //std::shoowpos, std::noshowpos - shows and hides positive symbol of a numeric data type

    //std::dec, std::hex, std::oct - show the decimal, hexadecimal and octal representation of the number
    std::cout << std::endl;
    std::cout << "Number is dec, hex and octal bases" << std::endl;
    float num1  = -498.32; // no effect on floating point numbers
    int num2 = 3345;
    std::cout << "Dec: " << std::dec << num1 << std::endl;
    std::cout << "Hex: " << std::hex << num1 << std::endl;
    std::cout << "Oct: " << std::oct << num1 << std::endl;
    std::cout << "Dec: " << std::dec << num2 << std::endl;
    std::cout << "Hex: " << std::hex << num2 << std::endl;
    std::cout << "Oct: " << std::oct << num2 << std::endl;
    
    //std::showbase - shows base of the representation 
    // 0x for hex, 0 for octal, nothing for decimal

    //std::uppercase, std::lowercase - print all chars in uppercase and lowercase, respectively
    
    // std::scientific std::fixed - manipulate how floating point numbers are displayed.
    // default cout behaviour - std::fixed unless scientific is necessary

    // std::setprecision(n) - control precision of printed output to n places, default cout precision 6
    double num3 = 3.14159039853980980989832530954309543;
    double num6 = 7.1;
    std::cout << "Precision 5 : " << std::setprecision(5) << num3 << std::endl;
    std::cout << "Precision 15 : " << std::setprecision(15) << num3 << std::endl;
    std::cout << "Precision 15 : " << std::setprecision(15) << num6 << std::endl;

    // std::showpoint - force decimal point to be shown (and traling 0s)
    double num4 = 12;
    float num5 = 13;
    std::cout << "std::showpoint with double " << std::showpoint << num4 << std::endl;
    std::cout << "std::showpoint with int " << std::showpoint << num5 << std::endl;
    return 0;
}
#include <iostream>

int main()
{
    /*
    Order of operations for binary math operations:
    1. Inner paranthesis
    2. Outer paranthesis
    3. Multiplication, Modulous and Division
    4. Addition and Subtraction
    5. Evaluation from Left to Right for operators of equal precedence
    */

    int a {6};
    int b {3};
    int c {8};
    int d {9};
    int e {3};
    int f {2};
    int g {5};

    int result;

    result = a + b * c - d / e -f + g; // Implicit order of operation
    std::cout << result << std::endl;

    result = ((((a + (b * c)) - (d / e)) -f) + g); // Explicit order of operation
    std::cout << result << std::endl;
    
    return 0;
}
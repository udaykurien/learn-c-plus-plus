#include <ios>
#include <iostream>

int main()
{
    /*
    Relational operators : Used to relate 2 objects 
    Returns True/1 is relation is true or Flase/0 is relation is false
    >, >=, <, <=, ==, !=
    */

    int num1 {45};
    int num2 {60};

    std::cout << "num1: " << num1 << std::endl;
    std::cout << "num2: " << num2 << std::endl;

    std::cout << std::endl;
    std::cout << std::boolalpha;

    std::cout << "num1 < num2: " << (num1 < num2) << std::endl;
    std::cout << "num1 <= num2: " << (num1 <= num2) << std::endl;
    std::cout << "num1 > num2: " << (num1 > num2) << std::endl;
    std::cout << "num1 >= num2: " << (num1 >= num2) << std::endl;
    std::cout << "num1 == num2: " << (num1 == num2) << std::endl;
    std::cout << "num1 != num2: " << (num1 != num2) << std::endl;

    bool result = (num1 == num2);
    std::cout << "bool result = (num1 == num2): " << result << std::endl;


    return 0;
}
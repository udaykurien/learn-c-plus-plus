#include <iostream>
#include <iomanip>

int main()
{
    /*
    We can use nested conditionals
    Conditionals can be mixed with logical and boolean expressions
    */

    int number1 {55};
    int number2 {60};

    bool result = (number1 < number2);

    std::cout << "Number 1: " << number1 << std::endl;
    std::cout << "Number 2: " << number2 << std::endl;
    std::cout << "result = (number1 < number2): " << std::boolalpha << result << std::endl;
    
    std::cout << std::endl << "If clauses: " << std::endl;

    if(result){ // or if(result == true) or if (number1 < number2)
        std::cout << number1 << " is less than " << number2 << std::endl;
    }
    if(!result){ // or if(result == false) or if(!(result == true)) or else
        std::cout << number2 << " is less than " << number1 << std::endl;
    }

    std::cout << "If-Else clause: " <<std::endl;
    
    if(result){ // or if(result == true)
        std::cout << number1 << " is less than " << number2 << std::endl;
    }
    else{ // or if(result == false) or if(!(result == true)) or else
        std::cout << number2 << " is less than " << number1 << std::endl;
    }

    return 0;
}
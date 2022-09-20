#include <iostream>

int main()
{
    /*
    Postfix:
    value++ => value + 1, but value is only incremented after the original value is printed
    value-- => value - 1, but value is only decremented after the original value is printed

    Prefix:
    ++value => value + 1, but value is incremented before use
    --value => value -1, but value is decremented before use
    */

    int value;

    value = 5;
    std::cout << "value: " << value << std::endl;
    std::cout << "value++: " << value++ << std::endl;
    std::cout << "value: " << value << std::endl;
    std::cout << std::endl;

    value = 5;
    std::cout << "value: " << value << std::endl;
    std::cout << "++value: " << ++value << std::endl;
    std::cout << "value: " << value << std::endl;
    std::cout << std::endl;

    value = 5;
    std::cout << "value: " << value << std::endl;
    std::cout << "value--: " << value-- << std::endl;
    std::cout << "value: " << value << std::endl;
    std::cout << std::endl;

    value = 5;
    std::cout << "value: " << value << std::endl;
    std::cout << "--value: " << --value << std::endl;
    std::cout << "value: " << value << std::endl;
    std::cout << std::endl;


    return 0;
}
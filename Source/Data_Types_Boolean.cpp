#include <iostream>

int main()
{
    /*
    Boolean values: true (1), false (0)
    Boolean data_type: bool
    Boolean size: 8 bits or 1 byte
    */

    bool red_light{true};
    bool green_light{false};

    if (red_light)
    {
        std::cout << "Stop"<< std::endl;
        std::cout << "Value of red_light: " << red_light << std::endl;
    }

    std::cout << std::boolalpha; // std::cout setting that represents booleans as true & false instead of 1 & 0

    if (!green_light)
    {
        std::cout << "Go" << std::endl;
        std::cout << "Value of not(green light) in alpha: " << !green_light << std::endl;
    }

    std::cout << "Size of bool: " << sizeof(bool) << " bytes" << std::endl;

    return 0;
}
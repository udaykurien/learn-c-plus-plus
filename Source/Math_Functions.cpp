#include <iostream>
#include <cmath>
int main()
{
    /*
    #include <cmath>
    */

    double weight {7.7};
    double savings {-5000};

    //default
    std::cout << "Default weight: " << weight << std::endl;
    std::cout << "Default savings: " << savings << std::endl;
    //floor - round down to next int
    std::cout << "Floor weight: " << std::floor(weight) << std::endl;
    //ceil - round up to next int
    std::cout << "Ceiling weight: " << std::ceil(weight) <<std::endl;
    //abs - absolute value
    std::cout << "Absolute valaues: " << std::abs(savings) << std::endl;
    //exp - exponention function, std::exp(n), ie e^n
    //pow - power function, std::pow(a,n), ie a^n
    //log - log function, std::log(a), ie log to base e of a
    //log10 - log function, std::log10(a), ir log to base 10 of a
    //std::sqrt(a)
    //std::round(a), decimal part >= 0.5 is rounded up. decimal part < 0.5 is rounded down
    //std::sin cos, tan etc etc etc

    return 0;
}
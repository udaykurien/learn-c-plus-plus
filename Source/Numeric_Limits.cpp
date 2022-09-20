#include <iostream>
#include <limits>

int main()
{
    /*
    #include <limits>
    std::numberic_limits<T>::min() or max() or lowest()
    T - data type for which min, max or lowest is determined
    dtype           min                 max                 lowest
    float           smallest +ve num    largest +ve num     largest -ve num
    signed int      largest -ve num     largest +ve num     -
    unsigned int    0                   largest +ve num     -
    */
    
    std::cout << "Short range: " << std::numeric_limits<short>::min() << " to " << std::numeric_limits<short>::max() << std::endl;

    std::cout << std::endl;

    std::cout << "Float min: " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "Float max: " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "Float lowest: " << std::numeric_limits<float>::lowest() << std::endl;

    std::cout << std::endl;

    // other functions in limits
    std::cout << "int digits: " << std::numeric_limits<int>::digits << std::endl;
    std::cout << "int range: " << std::numeric_limits<int>::min() << " to " << std::numeric_limits<int>::max() << std::endl;

    return 0;
}
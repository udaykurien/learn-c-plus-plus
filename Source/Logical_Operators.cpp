#include <iostream>

int main()
{
    /*
    && (And), || (Or), ! (Not)
    Logical operators operate on boolean operands
    Look up their truth tables 
    */

    bool a {true};
    bool b {false};
    bool c {true};

    std::cout << std::boolalpha;
    
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;

    std::cout << std::endl;

    std::cout << "a && b : " << (a && b) << std::endl;
    std::cout << "a && c : " << (a && c) << std::endl;
    std::cout << "a && b && c : " << (a && b && c) << std::endl;

    std::cout << std::endl;

    std::cout << "a || b : " << (a || b) << std::endl;
    std::cout << "a || c : " << (a || c) << std::endl;
    std::cout << "a || b || c : " << (a || b || c) << std::endl;

    std::cout << std::endl;

    std::cout << "!a : " << (!a) << std::endl;
    std::cout << "!b : " << (!b) << std::endl;
    std::cout << "!(a || b) : " << (!(a || b)) << std::endl;
    std::cout << "!(a && b) || c : " << (!(a && b) || c) <<std::endl;

    std::cout << std::endl;

    // Combining logical and relational operators into expressions
    int d {45};
    int e {20};
    int f {11};

    std::cout << "(d > e ) && ( d <= f) || !a : " << ((d > e) && (d <=f ) || (!a)) << std::endl;

    return 0;
}
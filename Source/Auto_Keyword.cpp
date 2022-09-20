#include <iostream>

int main()
{
    /*
    auto keyword: instructs compiler to deduce variable type
    */

    auto var1 {12};
    auto var2 {13.0};
    auto var3 {14.0f};
    auto var4 {15.01};
    auto var5 {'e'};

    // int modifiers
    auto var6 {123u};
    auto var7 {123ul};
    auto var8 {123ll};
    std::cout <<"var8: " << var8 << std::endl;
    std::cout <<"sizeof(var8): " << sizeof(var8) << std::endl;
    
    // Re-assigning variable
    var8 ='c';
    std::cout <<"var8: " << var8 << std::endl;
    std::cout <<"sizeof(var8): " << sizeof(var8) << std::endl;

    return 0;
}
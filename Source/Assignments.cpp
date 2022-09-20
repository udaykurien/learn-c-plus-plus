#include <iostream>

int main()
{
    /*
    After initialization, a variable can be assigned a new value.
    Applicable to all data types.
    Be careful during reassignment of auto-type.
    */

    // Given type
    int var1{123}; // Declaration and initialization
    std::cout << "var1: " << var1 << std::endl;
    var1 = 55; // Re-assignment
    std::cout << "var1: " << var1 << std::endl;

    // Auto type
    auto var3 {333u}; // type - unsigned int
    std::cout << "var3: " << var3 << std::endl;
    var3 = -22; // type - signed int
    std::cout <<"var3: " << var3 << std::endl; // Does not return whats expected (returns garbage value) because of illegal assignment of a signed int literal to an unsigned int variable

    return 0;
}
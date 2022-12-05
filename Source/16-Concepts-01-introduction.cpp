#include <iostream>

template <typename T> void print_number (T n) {
    static_assert(std::is_integral<T>::value,"Must pass integral argument");
    //static assert : check value at compile time
    //syntax: static_assert(check_condition, "print msg is condition unment")
    //std::is_itegral<T>::value :
    //value- true if T is an integral type , false otherwise 
    std::cout << "n: " << n << std::endl;
}

//Concepts are a cleaner way to code the above function template (i.e. shifting parameter type check from function body to function head)

int main () {

    /*
    Concepts (19:04:34):
    (One of the big features in c++ 20)
    A mechanism to place contraints on the template parameter types.
    eg. we can specify that we want to function to be called only with integer type params. If the params are of another type we'll get a compiler error.

    2 types of concepts in c++:
    1. Standard built in concepts that come built into the standard libraries of C++.
    2. Custom concepts.

    Some common concepts:
    same_as
    derived_from
    convertible_to
    common_reference_with
    common_with
    integral
    signed_integral
    unsigned_integral
    floating_point
    */

    return 0;

}

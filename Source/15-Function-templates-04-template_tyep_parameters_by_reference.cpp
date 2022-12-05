#include <iostream>

template <typename T> const T max_pass_by_val(const T a, const T b);      //Pass by value
template <typename T> const T& max_pass_by_ref(const T& a, const T& b);    //Pass by reference (&)
//references in max_pass_by_value are const to prevent accidental changes to it, as it can modify the original arguments. This is good programming pracice

/*
Also valid prototypes:
template <typename T> T max_pass_by_val(T a, T b);      //Pass by value
template <typename T> T max_pass_by_ref(T& a, T& b);    //Pass by reference
Not using const with pass by reference is poor programming practice, unless you intend on modifying the values
*/

/*
// Don't do this, it confuses the compiler:
template <typename T> T maximum(T a, T b);
template <typename T> const T& maximum(const T& a, const T& b);

//The above are examples of function template overloads

int main() {
    double max1=maximum(a,b); //The compiler won't know which template to use
    return 0;
}
*/

int main () {

    /*
    Template type parameters by reference (18:35:48):
    - We have till now been passing arguments by value into instances of the template function. This causes the parameters of the template function instance to be copies of the arguments. ie. the arguments and the template function instance parameters have separate memory addresses, and modifying the template function instance parameters will not effect the original arguments.
    */

    double a{23.5},b{51.2};

    //Example of pass by value (the function instance parameters are copies of the arguments)
    std::cout << "In main - &a: " << &a << std::endl;
    double max1 = max_pass_by_val(a,b);
    std::cout << "max1: " << max1 <<std::endl;

    std::cout << std::endl;

    //Example of pass by reference (the function instance parameters are references/aliases of the arguments. ie. they read and write to the same memory location as the arguments.). This is achieved by making the parameters in the prototype of the function template references by placing the '&' symbol before them.
    std::cout << "In main - &a: " << &a << std::endl;
    double max2 = max_pass_by_ref(a,b);
    std::cout << "max2: " << max2 <<std::endl;

    return 0;

}

template <typename T> const T max_pass_by_val(const T a, const T b) {
    std::cout << "In max_pass_by_val - &a: " << &a << std::endl;
    return (a>b)?a:b;
}

template <typename T> const T& max_pass_by_ref(const T& a, const T& b) {
    std::cout << "In max_pass_by_ref - &a: " << &a << std::endl;
    return (a>b)?a:b;
}

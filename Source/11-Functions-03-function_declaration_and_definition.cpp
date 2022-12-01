#include <iostream>

// Function declarations/header/prototype - summary of function
// Note: parameter names are not important in prototypes and they don't have to be included
// In practive it is better to include parameter names as it makes the function self documenting
// The function definitions must include the variable names as they are used
int max (int , int);
int min (int a, int b);
int inc_mult (int , int);

// Main function
int main() {

    /*
    Function declaration and definition:
    Sometimes its more flexible to split the function into its header and body and keep the code for each in different places
    Adding a function header lets the compiler know that the function definition will be found later in the program. That way when the compiler sees a function call, it will know that the function exists.
    If the function was not prototyped (or defined) before it is called, the compiler will be unaware of its existence, and will return an error when it sees a call to it.
    Therefore, a function must be prototyped or defined before it is first called.

    Function prototype vs function signature:
    Prototype: return type + function name + list of parameters (only types of params considered)
    Signature : function name + list of parameter (only type of params considered)
    or, the function signature, unlike the function prototype, does not include the return type.
    */

   int a{3}, b{4};

   std::cout << "max(" << a << "," << b << "): " << max(a,b) << std::endl;
   std::cout << "min(" << a << "," << b << "): " << min(a,b) << std::endl;
   std::cout << "inc_mult(" << a << "," << b << "): " << inc_mult(a,b) << std::endl;
   std::cout << "a: " << a << ", b: " << b << std::endl;
   
   return 0;
}

// Function definition/implementation
int max (int a, int b) {
    if (a>b)
        return a;
    else
        return b;
}

int min (int a, int b) {
    if (a<b)
        return a;
    else
        return b;
}

int inc_mult (int a, int b) {
    return ((++a)*(++b));
}
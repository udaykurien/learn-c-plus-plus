#include <iostream>
#include <string>

int max(int a, int b) {
    std::cout << "int-int overload called: " << std::endl;
    return (a>b)? a:b;
}
/*
// Can't overload on return type - Compiler error.
// Can only overload on parameter type (therefore, function signature)
double max(int a, int b) {
    return (a>b)? a:b;
}
*/

//This overloading is valid, because the parameter types (and therefore the function signature) are different compared to the previous function.
double max (double a, double b) {
    std::cout << "double-double overload called: " << std::endl;
    return (a>b)?a:b;
}

//In the next 2 functions, we have only changed the order of the types. This is still a legal overload. 
double max (int a, double b) {
    std::cout << "int-double overload called: " << std::endl;
    return (a>b)?a:b;
}

double max (double a, int b) {
    std::cout << "double-int overload called: " << std::endl;
    return (a>b)?a:b;
}

//Another legal overload as the function signature is valid.
std::string_view max(std::string_view str1, std::string_view str2) {
    std::cout << "string-string overload called: " << std::endl;
    return (str1>str2)? str1:str2;
}

int main() {

    /*
    Overloading with different parameters (16:34:19):
    Some ways to make legal overloads:
    - Change order of parameter (types)
    - Change number of parameters
    - Change types
    */

   //Calling the overloads
   int int_val1{41}, int_val2{29};
   double dbl_val1{47.2}, dbl_val2{55.01};

   std::string_view first {"Hello"};
   std::string_view second {"World"};

   //C++ automatically matches the function signature to the call below, and therefore implements the correct function.
   std::cout << "max (" << int_val1 <<"," << int_val2 << "): " << max(int_val1,int_val2) << std::endl;
   std::cout << std::endl;

   std::cout << "max (" << 5 <<"," << 7 << "): " << max(5,7) << std::endl;
   std::cout << std::endl;

   std::cout << "max (" << dbl_val1 <<"," << dbl_val2 << "): " << max(dbl_val1,dbl_val2) << std::endl;
   std::cout << std::endl;

   std::cout << "max (" << 1 <<"," << 7.2 << "): " << max(1,7.2) << std::endl;
   std::cout << std::endl;

   std::cout << "max (" << first <<"," << second << "): " << max(first,second) << std::endl;
   std::cout << std::endl;

   std::cout << "max (" << "dog"  <<"," << "cat" << "): " << max("dog","cat") << std::endl;
   std::cout << std::endl; //"dog" and "cat" are char array parameters and NOT string parameters.
   // We haven't defined a max overload for character arrays. So what does the compiler do in this case?
   // The compiler implicity converts the character array (the string literal) to a string_view type and then sends "cat" and "dog" to  the max(string_view,string_view) overload
   

   return 0;
}
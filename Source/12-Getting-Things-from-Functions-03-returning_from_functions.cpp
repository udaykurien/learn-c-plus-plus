#include <iostream>
#include <string>

int sum(int a, int b){
    int result = a+b;
    std::cout << "In sum(): &result(int): " << &result <<std::endl;
    return result;
    //This is an example of return by value.
    //The memory locations of a,b and result in sum() is different from their memory locations in main().
}

/*
Important Note:
In modern compilers, return by value is commonly optimized out by the compiler when possible and the function is modified behind your back to return by reference, avoiding unnecessary copies!
An example of this is present in the subsequent function - add_strings()
*/

std::string add_strings (const std::string str1, const std::string str2){
    std::string result = str1 + str2;
    std::cout << "In add_strings: &result(std::string): " << &result << std::endl;
    return result;
    //Because of compiler optimizations here, result in add_strings and result2 in main() access the same memory address.
}

int main() {

    /*
    Returning from functions (16:17:54):
    Getting data outside the function using the return mechanism.
    This is contrast to using pointers and references to all changes within functions to persist outside it.    
    */

   //In this case result1 in main() and result in sum() have different memory addresses
   int a {34}, b{16};
   
   int result1 =  sum(a,b);
   std::cout << "In main() : &result1(int): " << &result1 << std::endl;
   std::cout << "Result: " << result1 << std::endl;

   //In this case result2 in main() and result in add_strings() have the same memory address. This behaviour is different from the previous case because of auto optimizations made by the compiler.
   std::cout << std::endl;
   std::string str1{"Fat"}, str2{"Cat"};
   std::string result2 = add_strings(str1, str2);
   std::cout << "In main() : &result2(int): " << &result2 << std::endl;
   std::cout << "Result: " << result2 << std::endl;

   return 0;
}
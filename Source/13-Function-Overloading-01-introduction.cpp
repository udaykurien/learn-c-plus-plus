#include <iostream>
#include <string>

//Function declarations
//Functions have same name (max) but different signatures. - This is Overloading.
int max(int a, int b);
double max(double a, double b);
std::string max(const std::string& a, const std::string& b);

int main() {

    /*
    Function overloading introduction (16:32:39):
    - It is a mechanism, available in C++, whereby we can have multiple functions with the same function name but different function param types.
    - Or, it is a mechanism which allows us to have many functions with the same name provided that the function signatures are unique.
    - The advantage of this is that, based on the argument types passed during the function call, C++ will select the appropriate function (based on matching the function signature), and execute the code written in the definition of that function. Or. upon function call, C++ will select the function with the matching signature from the set of all functions with the same name, and execute the code in the definition of that function.
    */

   return 0;
}
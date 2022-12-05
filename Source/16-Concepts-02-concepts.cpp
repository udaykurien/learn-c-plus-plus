#include <iostream>
#include <typeinfo>

// Function template with concepts.
// requires keyword is available from C++ 20 and above
// To compile run: g++ -std=c++20 main.cpp -o main.o
// or, on linux  : g++ -std=gnu++20 main.cpp -o main.o

// //Syntax 1
// template <typename T>
// requires std::integral<T> //requires keyword
// T add (T a, T b) {
//     return a+b;
// }

//Syntax 2
// template <typename T>
// requires std::is_integral_v<T> //Using a type trail
// T add (T a, T b) {
//     return a+b;
// }

//Syntax 3
// template <std::integral T> //include test in the first line
// T add(T a, T b) {
//     return a+b;
// }

//Syntax 4
// auto add(std::integral auto a, std::integral auto b){ 
//     return a+b;
// }
// Syntax 4 is based on the following normal function:
// auto add(auto a, auto b){ 
//     return a+b;
// }

//Syntax 5
template <typename T>
T add (T a, T b) requires std::integral<T> {
    return a+b;
}

//Some syntaxes work better in some situations

int main () {

    /*
    Concepts (19:06:51):
    A mechanism to place constraints on your templeate type parameters.
    */

   std::cout << "Understanding std::integral<T>" << std::endl;
   std::cout << "std::integral<int>: " << std::boolalpha << std::integral<int> << std::endl;
   std::cout << "std::integral<double>: " << std::boolalpha << std::integral<double> << std::endl;
   std::cout << std::endl;

    
    char a_0{33}, a_1{47};
    auto result_a = add(a_0,a_1);
    std::cout << "result_a: " << result_a << std::endl;
    std::cout << "type(result_a) :" << typeid(result_a).name() <<std::endl;
    std::cout << "static_cast<int>(result_a): " << static_cast<int>(result_a) << std::endl;
    std::cout << "type(result_a) :" << typeid(static_cast<int>(result_a)).name() <<std::endl;
    std::cout << std::endl;

    int b_0{11}, b_1{5};
    auto result_b = add(b_0,b_1);
    std::cout << "result_b: " << result_b << std::endl;
    std::cout << "type(result_b) :" << typeid(result_b).name() <<std::endl;
    std::cout << std::endl;

    /*
    double c_0 {11.1}, c_1 {1.9};
    auto result_c = add(c_0,c_1);
    */ //Compiler error as std::inegral concept not satisfied

    std::cout << "End of program reached." << std::endl;
    return 0;

}

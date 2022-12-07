#include <iostream>
#include <typeinfo>
#include <concepts>

//This syntax constrains the auto parameters you pass in to comply with the std::integral concept.
// If the arguments to the function are not of type std::integral, we get a compiler error
std::integral auto add (std::integral auto a, std::integral auto b) {
    return a+b;
}

int main () {

    /*
    Concepts and Auto keyword(20:09:40):
    */

   // Enforcing concepts on declared variables
   std::integral auto x1 = add(10,20);
   // Meaning: The value assigned to x1 should be an integral type. Since x1 is autotyped, the compiler will choose the most appropriate type for it based on the return type of add. std::integral will then check if x1 is an integer. If it isn't we'll get a compiler error.
   std::cout << "x1: " << x1 << " , typeof(x1): " << typeid(x1).name() << std::endl;
   //std::floating_point auto x = add(10,20); //compiler error

   // More examples of enforcing concepts on variables assigned to literals
   //std::integral auto y = 7.7; //error
   std::floating_point auto y2 = 7.7;
   // std::floating_point auto y2 = 7; // failed constraint, as auto will type y2 as in integer

    return 0;

}

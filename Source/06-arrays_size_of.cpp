#include <iostream>

int main () {
    /*
    1. Size/Number of elements of an array can be obtained with std::size.
    Syntax:
    std::size(<name_of_array>)

    2. The size/number of elements in an array can be obtained using the sizeof function
    Syntax:
    sizeof(<name_of_array>)/sizeof(<name_of_array>[0])
    eg.
    element_count = sizeof(scores)/sizeof(scores[0])
    */

   int scores[] {3,5,2,7,3,7,3,6,0};
   std::cout << "The size of scores (std::size(scores)) is: " << std::size(scores) << std::endl;
   std::cout << "The size of scores (sizeof(scores)/sizeof(scores[0])) is: " << sizeof(scores)/sizeof(scores[0]) << std::endl;

   // Iterate through the array using size, instead of hardcoding the value
   std::cout << std::endl;
   std::cout << "Usiing size()" << std::endl;
   for (size_t i {}; i < std::size(scores); i++) {
    std::cout << scores[i] << std::endl;
   }

   // Iterate through the array using sizeof, instead of hardcoding the value
   std::cout << std::endl;
   std::cout << "Using sizeof()" << std::endl;
   int count {sizeof(scores)/sizeof(scores[0])};
   for (size_t i{}; i < count; i++) {
    std::cout << scores[i] << std::endl;
   }

   return 0;
}
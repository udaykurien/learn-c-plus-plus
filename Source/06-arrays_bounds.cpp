#include <iostream>

int main() {
    /*
    It's risky to access or modify data which lie beyond the boundaries of your array as these memory locations have not been reserved for your program.
    Consequently it is possible that other critical programs are using those memory locations, and accessing or modifying the content at those locations,
    with your program, can significantly impact the operations of those programs.
    If that illegal memory location is restricted, the OS may kill the program and the program will crash.
    */

   // Accessing out of boundary value
   int numbers[] {1,2,3,4,5,6,7,8,9,0};
   std::cout << "Accessing an out of boundary element. Value at numbers[12]: " << numbers[12] << std::endl;
   // Modifying out of boundary value
   std::cout << "Assigning a value (28) at an out of boundary element. numbers[12]. " << std::endl;
   numbers[12] =28;
   std::cout << "Accessing the out of boundary element. numbers[12]: " << numbers[12] << std::endl;
   std::cout << "We have successfully modified the contents of a memory location that doesn't belong to this program. This is dangerous. " << std::endl;


   return 0;
}
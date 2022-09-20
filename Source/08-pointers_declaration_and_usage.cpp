#include <iostream>

int main() {
    /*
    
    */

   // Braced intialization of pointers (as shown below) tell the compiler that the pointers are not pointing to anything as yet.
   int * p_number {}; // can only store the address of a variable of type int
   double * p_fractional_number {}; // can only store the address of a variable of type double

   // Explicitly initialize to null pointer
   int * p_number_1 {nullptr}; // nullptr - equivalent to 0 in integer. Tells the compiler that the pointer is pointing at nothing. Can be abbreviated as {} i/e/ int * p_number_1 {}
   double * p_fractional_number_1 {nullptr};

   // Since pointers are memory addresses, all pointers have the same size.
   // i.e. a pointer pointing to an int will be of the same size as a pointer pointing to a double
   std::cout << "Size of pointer to int: " << sizeof(p_number) << std::endl; // size using pointer variable
   std::cout << "Size of pionter to double: " << sizeof(p_fractional_number) << std::endl; // size using pointer variable
   std::cout << "Size of int pointer: " << sizeof(int*) << ". Size of double pointer: " << sizeof(double*) << std::endl; // size using pointer type
   std::cout << std::endl;

   // Equivalent declarations (the placement of * does not matter):
   int* p1;
   int * p2;
   int *p3;

   // Equivalent declaration of nullptr
   int *p_null_1 {nullptr};
   int *p_null_2 {};
   
   // Avoid confusion:
   int* p4 {}, var4 {}; // In this expression, it is hard for the reader to know if var4 is also a pointer or just a normal int variable. As a best practice, declare pointers and regular variables on separate lines.
   int *p5{}, var5 {}; // Same abiguity as above
   // In the above example, p4 and p5 are declared as pointer, while var4 and var5 are declared as integers
   // int *p4 {};
   // int var4 {};

   // Adding data to pointer variables
   int int_var {43};
   int *p_int {&int_var}; // The & operator returns the memory address of the variable
   std::cout << "Value of variable, int_var: " << int_var << std::endl;
   std::cout << "Address of variable, int_var, is: "  << p_int << std::endl;
   std::cout << std::endl;

   std::cout << "Re-assigning value to pointer to a new memory address."  << std::endl;
   int int_var1 {65};
   p_int = &int_var1; // Changing the memory address held in point p_int from the address of int_var to the address of int_var1
   std::cout << "Adress of variable, int_var1, is: " << p_int << std::endl;
   std::cout << std::endl;

   // Remember we can't cross assign
   // Assigning an integer pointer to a double variable will cause a compiler error

   // Dereferencing a pointer : Reading the value contained in the memory address stored in the pointer
   // 1. syntax to de-reference a pointer: *<pointer_name>
   // 2. syntax to declare a pointer: <type> *<pointer_name>
   // 3. assigning an address to pointer: <pointer_name> = &<variable_name>
   // Both 1 and 2 use start notation, ie both declaration and dereferencing use the * notation. Don't confuse the 2 usages.
   int *p_int_2 {nullptr};
   int var_2 {54};
   p_int_2 = &var_2;
   std::cout << "The vale of var_2 is: " << var_2 << std::endl;
   std::cout << "The memory address of var_2 is: " << p_int_2 << std::endl;
   std::cout << " The value contained in memory adress " << p_int_2 << " is: " << *p_int_2 << std::endl;
   std::cout <<std::endl;

   return 0;
}
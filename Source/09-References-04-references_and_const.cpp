#include <iostream>

int main() {

    /*
    References and const (12:37:26):
    set up a constant alias for another variable
    */

   //Non const reference
   std::cout << std::endl;
   std::cout << "Non const reference: " << std::endl;
   int age {27};
   int& ref_age {age};

   std::cout << "age: " << age << std::endl;
   std::cout << "ref_age: " << ref_age << std::endl;

   //Can modify original variable through reference
   std::cout << std::endl;
   std::cout << "Modify original variable through reference: " << std::endl;

   ref_age++; //Modify through reference

   std::cout << "age: " << age << std::endl;
   std::cout  << "ref_age: " << ref_age << std::endl;

   //const reference
   std::cout << std::endl;
   std::cout << "Const references: " << std::endl;
   age=30;
   const int& const_ref_age{age}; //the original variable can't be modified by this reference/alias.

   std::cout << "age: " << age << std::endl;
   std::cout << "const_ref_age: " << const_ref_age << std::endl;

   //const_ref_age = 31; //error as ref (const_ref_age) is const
   ref_age =31; //valid as ref (ref_age) is not const
   age = 32; //also valid, direct variable change

   //We can achieve the same thing as const ref with pointer : const pointer to const data
   //Remember that a referenc by default is just like a const pointer. All we need to do is make the const pointer point to const data
   //Pointers can have 2 placments of const.
   //one before the pointer type and one after the pionter type
   //the first const prevents the pointer from modifying the memory location but does not inhibit the pointer from pointing to another memory location
   //the second const prevents the pointer from pointing to another memory location but does not prevent the pointer from changing the value at the memory location it is pointing at
   //both const, taken together, render the pointer unable to point to a different memory location or to modify the memory location it is pionting at, thereby acting as a constant reference.

   const int* const const_ptr_to_const_age{&age}; //first const to prevent the pointer from preventing changes to that memory location, and second const to prevent the pointer from pointing to another memory address?

   /*
   const int* const_ptr_to_const_age{&age};
   const_ptr_to_const_age = &age2; // runs fine
   *const_ptr_to_const_age=32; //fails

   int* const const_ptr_to_const_age{&age}
   const_ptr_to_const_age = &age2; // fails
   *const_ptr_to_const_age=32; // runs fine
   */

   return 0;
}
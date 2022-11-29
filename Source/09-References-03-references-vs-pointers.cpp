#include <iostream>

int main() {

    /*
    References vs pointers (12:22:29) :
    References:
    1. Don't use dereferencing for reading and writing.
    2. Can't be changed to reference something else.
    3. Must be initialized at declaration.
    Pointers:
    1. Must go through dereference operator to read/write the value pointed to.
    2. Can be changed to point somewhere else.
    3. Can be declared un-initialzed (will contain garbage values).
    */

   double double_val {12.34};
   double& ref_double_val {double_val}; //Reference to double_val
   double* ptr_double_val {&double_val}; //Pointer to double_val

   //Reading
   std::cout << "double_val: " << double_val << std::endl;
   std::cout << "ref_double_val: " << ref_double_val << std::endl;
   std::cout << "&ref_double_val: " << &ref_double_val << std::endl;
   std::cout << "ptr_double_val: " << ptr_double_val << std::endl;
   std::cout << "*ptr_double_val: " << *ptr_double_val << std::endl;

   //Writing through pointer
   std::cout << std::endl;
   std::cout << "Writing through pointer: " << std::endl;

   *ptr_double_val = 15.44;

   std::cout << "double_val: " << double_val << std::endl;
   std::cout << "ref_double_val: " << ref_double_val << std::endl;
   std::cout << "*ptr_double_val: " << *ptr_double_val << std::endl;
   std::cout << "ptr_double_val: " << ptr_double_val << std::endl;

   //Writing through reference
   std::cout << std::endl;
   std::cout << "Writing through reference: " << std::endl;

   ref_double_val = 18.44;

   std::cout << "double_val: " << double_val << std::endl;
   std::cout << "ref_double_val: " << ref_double_val << std::endl;
   std::cout << "*ptr_double_val: " << *ptr_double_val << std::endl;
   std::cout << "ptr_double_val: " << ptr_double_val << std::endl;

   //References can't be changed
   double double_val_2 {100.23};
   
   //This is valid code but ref_double_val doesn't stop referencing double_val. It instad modifies the value to double_val to be equal to the value contained in double_val_2, i.e., 100.23.
   //References remain fixed after declaration and initialization and can NOT be modified
   ref_double_val = double_val_2;

   //If you change ref_double_val now, double_val changes but double_val_2 doesn't change. This is because ref_double_val was initialized to reference double_val, and therefore can NOT be re-referenced to double_val_2.

   //Pointers can be changed
   ptr_double_val = &double_val_2; //ptr_double_val has been modified to point to double_val_2, earlier it pointed to double_var. Modifying the value oof ptr_double_val, by dereferencing, now will only effect double_val_2 and not double_val.

   //IDEA
   /*
   A refernce acts like a pointer which can not be reassigned to another object.
   In this way, a reference can also be thought of as a const pointer.
   */
   double* const const_p_double_val {&double_val};
   //const_p_double_val = &double_val_2 //error
   return 0;
}
#include <iostream>

int main() {
    /*
    Dangling pointers
    Dangling pointers are ponters that don't point to valid memory addresses.
    Trying to derefernce and use a dangling pointer will result in undefined behaviour.

    3 types of dangling pointers:
    - Uninitialized pointer
    - Deleted pointer
    - Multiple pointers pointing to same memory locaton
    */

   //Case 1: Unintialized pointer
   int * p_number; //Dangling unintialized pointer
   std::cout << std::endl;
   std::cout << "Case 1 : Uninitialized pointer :" << std::endl;
   std::cout << "p_number : " << p_number << std::endl;
   //std::cout << "*p_number : " << *p_number << std::endl; //crash or garbage value

   //Case 2: deleted pointer
   std::cout << std::endl;
   std::cout << "Case2: Deleted pointer" << std::endl;
   int *p_number1 {new int{67}};
   std::cout << "*p_number1 before delete: " << *p_number1 << std::endl;
   delete p_number1;
   std::cout << "*p_number1 after delete: " << *p_number1 << std:: endl; // undefined behaviour, crash or garbage value

   //Case3: Multiple pointers pointing to the same address
   std::cout << std::endl;
   std::cout << "Case 3: Multiple pointers pointing to the same memory location" << std::endl;
   int *p_number3 {new int {83}};
   int *p_number4 {p_number3}; //p_number4 stores the memory address that p_number3 points to, i.e. p_number3 and p_number4 point to exactly the same memory address
   std::cout << "p_number3: " << p_number3 << " , *p_number3: " << *p_number3 << std::endl;
   std::cout << "p_number4: " << p_number4 << " , *p_number4: " << *p_number4 << std::endl;
   // Deleting p_number3 ie deleting the heap memory location it is pointing to
   delete p_number3;
   //Now p_number4 points to deleted memory, dereferncing it will lead to undefined behavour live a crash or a garbage value
   //The memory address that p_number4 points to doesn't change, but the contents of that memory address has changed, because deletion of p_number3 releases that memory location back to the OS.
   std::cout<< "p_number4 (after deleting p_number3): " << p_number4 << " , *p_number4 (after deleting p_number3): "  << *p_number4 << std::endl;

   /*
   How do we solve the problem of dangling pointers?
   - Initialize your pointers.
   - Reset pointers after delete (eg. to nullptr).
   - For multiple pointers to same address, make sure the owner/master pointer is very clear / known to other developers. All other slave pointers will not be tasked with releasing the memory.
   */
   
   // Solution1: Initialize your pointers immediately upon declaration
   std::cout << std::endl;
   std::cout << "Solution 1: " << std::endl;
   int *p_number5{}; //Nullptr initialization
   int *p_number6 {new int{56}}; //Dynamic memory initialization
   // Check for nullptr before use
   if(p_number6 != nullptr){
        std::cout << "*p_number6: " << p_number6 << std::endl;
   }

   // Solution2: Right after you call delete on a pointer, remember to reset the pointer to nullptr to make it CLEAR it doesn't point anywhere
   std::cout << std::endl;
   std::cout << "Solution 2: " << std::endl;
   int *p_number7{new int{82}};
   std::cout << "p_number7: " << p_number7 << " , *p_number7: " << *p_number7 << std::endl;
   delete p_number7;
   p_number7 = nullptr; //Reset the pointer
   if(p_number7 != nullptr){ //Check to ensure it is not nullptr before use
        std::cout << "p_number7: " << p_number7 << " , *p_number7: " << *p_number7 << std::endl;
   }
   
   //Solution 3
   // For multiple pointers pointing to the same address, make sure there is one clear pointer (master pointer) that owns the memory (responsible for releasing when ncessary), other pointers should only be able to dereference when the master pointer is valid
   int *p_number8 {new int{382}}; //master pointer
   int *p_number9{p_number8}; //slave pointer
   //Dereference the pointers and use them
   std::cout << "p_number8: " << p_number8 << " , *p_number8" << *p_number8 << std::endl;
   //Only use slave pointers when master pointer is valid
   if(!(p_number8 == nullptr)){
        std::cout << "p_number9: " << p_number9 << " , *p_number8" << *p_number9 << std::endl;
   }
   //Master pointer releases its memory
   delete p_number8;
   p_number8 = nullptr;
   //Only use slave pointers when master pointer is valid
   if(!(p_number8 == nullptr)){
        std::cout << "p_number9: " << p_number9 << " , *p_number8" << *p_number9 << std::endl;
   } else{
    std::cerr << "WARNING : Trying to use an invalid pointer" << std::endl; //cerr- error stream?
   }

    return 0;
}
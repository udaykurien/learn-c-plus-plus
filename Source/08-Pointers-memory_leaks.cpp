#include <iostream>

int main(){
    /*
    Memory Leaks:
    Loss of access to memory dynamically allocated to program.
    We lose the pointer that was pointing to that dynamically allocated piece of memory.
    */

   // Example 1
   int *p_num {new int{67}}; //Points to some address in the heap, less say address1
   //Ideally, delete and reset to nullptr here
   int num {55}; //Lives at some address in the stack, lets say address2
   p_num = &num; //No p_num points to address2, but address 1 is still in use by our program. But our program has lost access to that memory location. This is called a memory leak.
   //p_num was the only way for our program to track that memory location, and when we loose it, we loose our way of modifying or even releasing that memory location. The program will have a bind on this memory location and the OS will not be able to reclaim this memory.

   // Example 2
   int *p_num1 {new int{55}};
   // Should delete and reset the pointer, after use, over here
   p_num1 = new int {44}; //Memory with int{55} leaked

   // Example 3
   {
       int *p_num2 {new int{57}};
   } //p_num2 does not exist outside of the scope and access to the memory location p_num2 points to will be lost when the scope is left. To prevent this time of memory leak, p_num2 may be deleted and reset within its scope.
    

   std::cout << "End of program reached." << std::endl;

   return 0;
}
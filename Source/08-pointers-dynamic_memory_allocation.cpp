#include <iostream>

int main() {
    /*
    Dynamic memory allocation uses heap storage to give us additional space.
    Note about pointers:
    - Make sure not to use uninitialized pointers as they contain junk values. In the very least initialize them to nullptr.
    - Dont modify values of null ptrs, make sure they point to something valid first
    */

   /*
   // Example using uninitialized pointer:
    int *p_number2; // uninitialized integer pointer
    *p_number2 = 55; // writing into uninitialized pointer through dereference
                     // this causes a segmentation error because the junk value references an address that we don't have the right to mess with
    std::cout << "p_number2: " << p_number2 << std::endl;
    std::cout << "*p_number2: " << *p_number2 << std::endl;
    


    // Initializing a pointer to null:
    int *p_number3 {}; // or int *p_number3{nullptr};
                       // This pointer points nowhere
    std::cout << "p_number3: " << p_number3 << std::endl;
    std::cout << "*p_number3: " << *p_number3 << std::endl; // Reading from a null ptr - BAD

    *p_number3 = 33;    // Assigning a value to a pointer that points nowhere  - bad
    std::cout << "*p_number3" << *p_number3 << std::endl;
    
    int num3 = 33;
    p_number3 = &num3; // This is acceptable. The pointer is pointing somewhere valid
    std::cout << "*p_number3: " << *p_number3 << std::endl;
    */

   /*
            STACK           VS          HEAP
            
    Stack:           
    - Memory is finite
    - The developer isnt in full control of memory lifetime
    - Lifetime is controlled by the scope mechanism
    Heap:
    - Memory is finite
    - The developer is in full control of when memory is allocated and when it is released
    - Lifetime is controlled explicitly through new and delete operators. 
   */

  
  // Lifetime of a stack variable
  // ----------------------------
  // local_scope_var does not exist
  {
    int local_scope_var {33}; // local_scope_var created in stack and the variable ceases to exist when we leave this scope
    int *local_ptr_var = new int; // memory allocated in heap and the memory location continues to exist even when we leavee this scope 
    std::cout << local_scope_var << std::endl;
  }  // local_scope_var wiped from stack
  // local_scope_var does not exist
  // std::cout << local_scope_var << std::endl; - error

  // Heap/dynamic memory allocation
  // ------------------------------
  int *p_number4 {nullptr};
  p_number4 = new int;   // Dynanically allocate space for a single int pn the heap
                        // This memory belongs to our program from now on. The system
                        // can't use it for anything else, until we return it.
                        // After this line executes, we will have a valid memoery location allocated.
                        // The size of the allocated memory will be such that it
                        // can store the type pointed to by the pointer.
    *p_number4 = 77; // writing into dynamically allocated memory
    std::cout << std::endl;
    std::cout << "Dynamically allocating memory: " << std::endl;
    std::cout << "*p_number4: " << *p_number4 << std::endl;
    
    // Delete heap memory allocation
    // ------------------------------
    delete p_number4; // deletes memory location pointed to by p_number4. The memory is released back to the OS. but doesn't delte the pointer itself. The pointer can be reused for some other purpose.
    p_number4 = nullptr; // convention, so that others are aware what you've done. Remember to always do this after deleting heap allocations.
    p_number4 = new int(45); // reusing the pointer
    std::cout << "p_number4: " << *p_number4 << std::endl;
    delete p_number4;
    p_number4 = nullptr;

    // Other conventions to declare and initialize heap pointers:
     int *p_number5 {new int}; // Memory location contains junk value
     int *p_number6 {new int(22)}; // Use direct initialization
     int *p_number7 {new int {23}}; // Use uniform initialization

    // Remember to release the memory
    delete p_number5;
    p_number5 = nullptr;

    delete p_number6;
    p_number6 = nullptr;

    delete p_number7;
    p_number7 = nullptr;

    // Really Important: Make sure you dont call the delete operator on the pointer more than once. This will cause unexpected and undefined behaviour.
    // delete p_number7;
    // delete p_number7;

    return 0;
}
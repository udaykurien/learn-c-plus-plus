#include <iostream>

int main(){
    /*
    Dynamic arrays (11:55:47):
    These are arrays that are stored on the heap and not in the stack.
    Arrays are allocated on the heap with the new operator. Can also use the Std::nothrow version of the new operator if we don't want exceptions.
    */

   //Declaring and Initializing single variable in heap
   int *p_single { new(std::nothrow) int{}}; //p_single declared in heap and initialized to 0

   size_t size{10};//Varialbe holding size of dynamic array
   const size_t size_stack{10}; //Const variable holding size of stack array
   // Dynamic array - Variable size, Stack array - Const size
   // Different ways to dynamically declare an array and initiliaze them
   double *p_salaries {new double[size]}; //this array contains garbage values
   int *p_students { new(std::nothrow) int[size]{}}; //all values initialized to 0
   double * p_scores { new(std::nothrow) double[size]{1,2,3,4,5}}; //The first 5 values will be initialized to 1,2,3,4,5 and the next 5 values will be initialized to 0.

   //Pointer arithmetic
   std::cout << "Starting address of p_scores (array element 0): " << p_scores << std::endl;
   std::cout << "Value of p_scores at this address: " << *p_scores << std::endl;
   std::cout << "Address of 3rd array element (p_scores+2), i.e. (address of array element 0) + 2: " << p_scores +2 << std::endl;
   std::cout << "Value of p_scores at this address *(p_scores + 2): " << *(p_scores+2) << std::endl;

   //Now we can do things with the arrays
   //nullptr check and use allocated array
   if(p_scores){
    //Print out elements. Can use regular array access notation (square bracket notation), or pointer arithmetic
    for(size_t i{}; i <size; i++){
        std::cout << "Value: " << p_scores[i] << " : " << *(p_scores+i) << std::endl;
    }
   } //Compact version of nullptr check

   //Releasing the memory allocated to the arrays back to the operating system
   delete[] p_scores;
   p_scores = nullptr;

   delete[] p_students;
   p_students = nullptr;

   delete[] p_salaries;
   p_salaries = nullptr;

   // Important points of differences btween stack arrays and heap/dynamic arrays:
   // Dynamic arrays don't support some stack array operations such ast std::size and range based for loop.
   // This is because a dynamic array is just seen as a pointer to the first element, of a given type, held in the heap. The compiler loses all other information about the dynamic array such as size. This prevents the use of std::size and range based loop.
   // In case of a stack array, the compiler knows its size and type.
   double *temperature_heap = new(std::nothrow) double[size] {10.0,20.0,30.0,40.0,50.0,60.0,70.0,80.0,90.0,100.0}; //dynamic array
   double *temperature_heap2 = new(std::nothrow) double[10] {10.0,20.0,30.0,40.0,50.0,60.0,70.0,80.0,90.0,100.0}; //dynamic array
   double temperature_stack[] {10.0,20.0,30.0,40.0,50.0,60.0,70.0,80.0,90.0,100.0}; //stack array
   std::cout << "std::size(temperature_stack): " << std::size(temperature_stack) << std::endl;
   // std::cout << "std::size(temperature_heap): " << std::size(temperature_heap) << std::endl; //compiler error
   // std::cout << "std::size(temperature_heap2): " << std::size(temperature_heap2) << std::endl; // compiler error
   for (double temp : temperature_stack){
    std::cout << temp << std::endl;
   }
   /*
   for (double temp : temperature_heap){
    std::cout << temp << std::endl;
   } //Compiler error
   */

   return 0;
}
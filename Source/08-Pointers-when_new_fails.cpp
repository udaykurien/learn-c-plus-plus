// This code can crash the computer. Don't run it.

#include <iostream>

int main(){
    /*
    When the new operator fails to allocate memory in the heap:
    In some cases the new operator will fail to allocate dynamic memory from the heap. When that happens, and you have no mechanism in place to handle that ailure, an exception will be thrown and your program will crash.
    This failure is very RARE though.
    */

   // Attempting to purposely force the new operator to fail
   // Try allocate an insanely huge array in one go
//    int* lots_of_ints1{new int[10000000000000]}; //compiler may catch on to this error

   size_t b {}; // Reminder - declare variable t as type unsigned integer (size_t) and initialize it to 0 ({}).

   //Use a huge loop to try and exhaust the memory capabilities of your system. When new fails, your program is going to forcefully terminate.
   //You can acutally monitor the memory usage with a system monitory utility like htop 
//    for(size_t i{}; i < 100000000000000; ++i){
//     int* lots_of_ints2 {new int[10000000]};
//    }

   //We can handle such failures using C++'s exception mechanism
   //We can also use the std::nothrow setting in our new operator and force it not to throw an exception and its going to give us no pointer if the allocation fails.

   //Handling the exception
   // Solution 1 - The try catch statements
   //Handle the problem in a way that makes sense for your application. For example if you were trying to allocate memory to store color information for your applicaton, and th allocation fails, you could opt for showing somee feedback message to the user, and rendering your app in black/white.
//    for(size_t i {};i<100000000000000;++i){
//     try{
//         int* lots_of_ints3{new int[10000000]};
//     }catch(std::exception& ex){
//         std::cout << "Cought exception ourselves: " << ex.what() << std::endl;
//     }
//    } // Try catch not working on my pc in this case

   //Solution 2
   //The nothrow option : ideal if you dont want exceptions thrown when new fails
   for(size_t i{};i<100000000000000;++i){
    int* lots_of_ints4 {new(std::nothrow) int[10000000]};
    if(lots_of_ints4 == nullptr){
        //Don't try to dereference and use lots_of_ints4 in here.
        //you'll get undefined behaviour. No memory has really been allocated here
        //It failed and returned nullptr because of the std::nothrow setting
        std::cout <<"Memory allocation failed"<<std::endl;
    }else{
        std::cout << "memory allocation succeded" << std::endl;
    }
    }
   return 0;
} // This piece of code crashed my computer
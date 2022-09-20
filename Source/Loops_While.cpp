#include <iostream>

int main()
{
    /*
    Parts of a while loop:
    1. Iterator
    2. Starting Point
    3. Test/exit condition
    4. Increment/Decrement
    5. Loop body

    while (exit condition)
    {
        loop body
    }

    while is an entry controlled loop (in contrast to do..while)
    when the exit condition is met the loop with exit immediately
   
    in do..while, because the check for the exit condition is at the bottom, 
    the loop body run atleast once even though the exit condition is met
    */

   const size_t COUNT = 5;
   
   unsigned int i {0};
   while (i<COUNT) {
    std::cout<<"Loop number: "<<i<<std::endl;
    i++;
   }

   return 0;
}
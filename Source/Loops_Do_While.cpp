#include<iostream>

int main ()
{
    /*
    do {

    } while (exit condition);

    In contrast to while, the do..while is an exit controlled loop.
    i.e. the loop will run exactly once, even if the condition is false, because the condition
    is only checked in the end
    */

   const unsigned int COUNT {5};
   
   size_t i {7}; // will run once, because check for exit condition is at bottom of the loop
   do {
    std::cout <<"Value of i in the do..while loop: " << i << std::endl;
    i++;
   } while (i < COUNT);

   size_t j {7};
   while (j < COUNT) // will not run at all because exit condition is checked at start of the loop
   {
    std::cout <<"Value of j in the while loop: " << j << std::endl;
    j++;
   }

   size_t k {0};
   do
   {
    std::cout <<"Value of k in the while loop: " << k << std::endl;
    k++;
   } while (k<COUNT);

   return 0;
}
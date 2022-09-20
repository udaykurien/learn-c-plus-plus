#include<iostream>

int main() {
    /*
    Types of for loops:
    1. Regular for loop.
    2. Ranged based for loop.

    For loop:
    for (iterator = starting point; loop exit condition; interator increment/decrement)
    {
        loop body
    }

    5 parts of a for loop:
    1. Iterator
    2. Starting Point
    3. Test (exit condition)
    4. Increment/Decrement
    5. Loop body
    */

    size_t counter {0}; //size_t is not a type, its just an alias of some type of unsigned int. It is often used as the type for a loop iterator to make to code more readable.
    int limit {10};
    size_t test_var {}; //initialize a var of type unsigned int (size_t) to 0. This is identical to size_t test_var =0;

    std::cout<<"Value of test var is: "<<test_var<<std::endl;
    
    // Regular for loop
    for (counter=0; counter <= limit; counter++) { // iterator declared outside the scope of the loop
        /* Iterator counter was declared outside the for loop. So any changes to the iterator is accessible outside the for loop.
        If counter were re-declared within the for-loop, then it would be treated as a different variable to the global counter. Any changes to the value of the local counter (i.e.) within the for loop would not be accessible outside the for loop.*/
        std::cout << "Iterator value inside the loop: " << counter << std::endl;
    }
    std::cout << "Iterator value outside the loop: "<< counter <<std::endl;

    for (size_t i {}; i <=2; i++) { // iterator declared within the scope of the loop
        /* Iterator i declared and initialized within the for loop can't be accessed outside the loop body.
        It only exists within the loop. */
        std::cout<<"This is a test loop\ni value: "<< i <<std::endl;
    }

    for (unsigned int j = 0; j<=5; j++)
    {
        std::cout<<"This is loop number: "<<j<<std::endl;
    }

    //some syntactic sugar
    size_t k{};
    for ( ; k<=2;k++) { //we dont have to re-initialize k within the loop
        std::cout<<"the value of k is: "<<k<<std::endl;
    }
    // or
    k=0;
    for ( k ; k<=2;k++) { //we dont have to re-initialize k within the loop
        std::cout<<"the value of k is: "<<k<<std::endl;
    }

    // analysis of size of size_t
    std::cout<<"Size of size_t: "<<sizeof(size_t)<<" bytes"<<std::endl;

    return 0;
}
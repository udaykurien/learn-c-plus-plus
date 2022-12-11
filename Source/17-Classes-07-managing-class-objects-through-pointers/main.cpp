#include <iostream>
#include "constants.h" 
#include "cylinder_headers.h"

int main () {
    /*
    Managing class objects through pointers (21:30:49):
    - Needed when we are using dynamic memory allocation.
    */
   
    // Managing stack object directly
    // ------------------------------
    // Stack object : Dot (.) notation eg. c1.radius, c1.volume(), c1.set_height()
    Cylinder c1{10,2}; //Create cylinder stack object
    std::cout << "Calling class methods on object in stack: " << std::endl;
    // Dot operator to access member of class object in stack
    std::cout << "c1.volume(): " << c1.volume() << std::endl;

    // Managing stack object with pointers
    // -----------------------------------
    std::cout << std::endl;
    std::cout << "Calling class methods on pointer to object in stack: " << std::endl;
    Cylinder* p_c1 = &c1;
    std::cout << "(*p_c1).volume(): " << (*p_c1).volume() << std::endl;
    std::cout << "p_c1 -> volume(): " << p_c1 -> volume() << std::endl;
    
    // Managing a heap object with pointers
    // ------------------------------------
    // Heap object : . dereference (*) and dot (.) notation
    // Heap object : pointer access (->) notation
    std::cout << std::endl;
    Cylinder* p_c2 = new Cylinder(100,2); //Create object on heap and assign pointer to it
    std::cout << "Calling class methods on object in heap: " << std::endl;
    // Dereference and dot operators to access member of class object in heap
    std::cout << "(*p_c2).volume(): " << (*p_c2).volume() << std::endl;
    std::cout << "(*p_c2).get_radius(): " << (*p_c2).get_radius() << std::endl;
    // Pointer access notation to access member of class object in heap
    std::cout << "p_c2->volume(): " << p_c2->volume() << std::endl;
    std::cout << "p_c2->get_radius(): " << p_c2->get_radius() << std::endl;


    delete p_c2; // Release memory from heap

    return 0;
}

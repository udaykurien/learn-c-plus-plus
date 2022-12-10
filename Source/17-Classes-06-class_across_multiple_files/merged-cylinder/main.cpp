#include <iostream>
#include "constants.h" // good design to place constants in its own file. easier to manage. can easily track,add,del or modify constants.
#include "cylinder_header_and_definiton.h"

// Remeber:
// Pre-processer copies contents of files, named in #include, into this file
// Make sure to add include guards to avoid re-definition errors.

int main () {

    /*
    Classes across multiple files (21:10:09):
    Splitting the program across multiple files.

    Architecture:
    We want to split the cylinder program into multiple files
    - A header file for the constants (PI) : constants.h
    - A header file for cylinder class declaration / preview : cylinder.h
    - A file for cylinder class definition / implementation : cylinder.cpp
    (We could have alternatively combined both the declaration and definition of class cylinder into a single header (.h) file. But for the sake of exploring the ways classes can be split up in this tutorial, we'll use separate files for declarations and defintions.)  
    */

   Cylinder c1{10,10};
   std::cout << "c1.volume(): " << c1.volume() << std::endl;

    return 0;

}

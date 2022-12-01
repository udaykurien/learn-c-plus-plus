// To compile this program, include all the .cpp files (i.e main and function definitions), but leave out the function headers (.h files) in the compilation statement.
// eg. g++ main.cpp compare.cpp -o program.exe 
// We compile all the .cpp files because we need them in the binary form.
// We don't compile the header files because the preprocessor copies the contents of these files to the main file, where the include directive is given.
// Effectively, .h files sorta acts as an easy way to include function prototypes.
// If .h files didnt exist, we'd manually type in the function prototypes like we've been doing till now
//FYI - The names of the function declaraton and function prototype files don't have to be the same. In this example it is, but that is purely coincidental.
//FYI - Also the function definitions don't have to live in its own exclusive file. It can be present in any of the translational units, and the the linker will still find them.


#include <iostream>
#include "compare.h" //Include header file with declarations for max, min
                    // Pre-processor copies contents of compare.h over here
#include "operations.h"

//include convention
// #include "fname.h" - your own headers
// #inclde <name> - headers for standard libraries

int main() {
    /*
    Refer to initial notes.cpp for more information.
    */

   int max_num = max(134,56);
   std::cout << "max: " << max_num << std::endl;
   
   int min_num = min(134,56);
   std::cout << "min: " << min_num << std::endl;

   int result = incr_mult(4,5);
   std::cout << "incr_mult: " << result << std::endl;

   return 0;
}

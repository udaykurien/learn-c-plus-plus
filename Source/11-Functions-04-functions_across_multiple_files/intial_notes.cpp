#include <iostream>
int main() {

    /*
    Functions across multiple files, compilation re-visited (15:15:30):
    
    A more in-depth view of the compilation process:
    1. The source code is read by the compiler.
    2. The compiler converts it into a binary executable.
    3. The binary file is excuted instruction by instruction.

    Compiler what is happening under the hood?
    - Suppose the program is made of more than 1 source file.
    - Before these source files are compiled they pass through the pre-processing stage.
    - During the pre-processing stage the compiler:
        - Searches for the include statements, takes the the files menetioned in the include statements, and pastes that in place of the include statement.
        - For example #include<iostream> will be replaced by the contents of the iostream file.
        - So now our source file is present in an intermediate form in which all the contents of the files mentioned in the #include statement are included.
        - The technical term for these files are 'Translational Units'.
    - These translational units are then compiled, by the compiler, to generate what is known as an 'Object File'. The object file is a binary representation of the contents we have in the translational units.
    - Each translational unit will generate one object file. (eg. 20 translational u nits would yield 20 object files.)
    - The object files are then processed by what is known as the 'Linker'.
    - The function of the linker is to:
        - Stitch these object files together to generate one single binary file/executable.
        - This single binary is what is run/executed on the target operating system.

    Summary:
    Stages of compilation mode: -Pre-processing -Compilation -Linking 
    or -Pre-processing -Compilation to object files -Linking to single binary file

    It is important to know this as most real world programs are split into multiple files, and all these stages will be involved in converting the source code to a single executable.

    Exercise:
    WAP that contains 3 functions:
     -max
     -min
     -incr_mult
     Where max and min headers reside in one file (comparisons.h) and the incr_mult header resides in another file (operations.h). The definitions of these functions reside in the files - comparions.cpp and operations.cpp, respectively. The functions will then be called from the main function, in the main file - main.cpp. In the main file, these functions will be included using the #include statement.

     The purpose of the exercise to the understand the stages of compilation.

     Remember:
     When we start splitting functions across definitions and declarations remember the One Definition Rule.
     One Definition Rule: The same function implementation can not show up in the global namespace more than once.
     If function implementation is not unique within the same file we get a compiler error.
     If function implementation is not unique across multiple files we get a linker error.

     The function definition can live anywhere in the code. The linker is smart enough to parse your entire project/all your translational units and find the function definition.If a definition isn't found the linker returns a linker error (error type - undefined reference).
    */

   return 0;
}
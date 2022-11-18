#include <iostream>
// Double vs single quotes for char: https://stackoverflow.com/questions/3683602/single-quotes-vs-double-quotes-in-c-or-c
// 'a' - character a. doesnt contain null char. len('a') = 1
// "a" - string literal a, containing a and null character, \0. len("a") = 2

int main () {
    /*
    
    */

   // We declare and initialize char ararys in the same way we do numerical arrays
   char array_1[5];
   char message[] {'H','e','l','l','o'}; // null character not autofilled, so possible error in printing

   // We print out char arrays in the same way we print out numerical arrays
   std::cout << "Printing message without null char using a loop " << std::endl;
   for (auto letter : message) {
    std::cout << letter << std::endl;
   }
   std::cout << "size: " << std::size(message) << std::endl;

   std::cout << "Printing message with null char using a loop " << std::endl;
   char message_nullchar[] {'H','e','l','l','o','\0'}; 
   for (auto letter : message_nullchar) {
    std::cout << letter << std::endl;
   }
   std::cout << "size: " << std::size(message_nullchar) << std::endl;

   // Unilike numerical arrays, char arrays can also be printed out without a loop
   // Be aware that this only works properly with 'Proper C Strings'
   // A Proper C String is a string/char array that is terminated with the null character (\0)
   // The null character identifies, to C++, that the end of the string has been reached
   // If \0 is not there C++ might keep printing untill it comes across one, potentially resulting in garbage values being displayed
   std::cout << std::endl;
   std::cout << "Printing out character array without a loop (& without a null char termination): " << std::endl;
   std::cout << "cout << message: " << message << std::endl;

   std::cout << std::endl;
   std::cout << "Printing out character array without a loop (& with a null char termination): " << std::endl;
   std::cout << "cout << message_nullchar: " << message_nullchar << std::endl;

   // cout with auto null character terminated string
   std::cout << std::endl;
   std::cout << "cout with auto null character terminated string: " << std::endl;
   char message_1[20] ={'H','e','l','l','o'}; // null character autofilled in contrast to char message[5] {'H','e','l','l','o} or char message[] {'H','e','l','l','o} where the null char isnt autfilled because the compiler believes that you explicitly have stated that the size of the array is exactly 5 char long (Hello) and therefore there isn't a 6th position to add the null char to.
   std::cout  << message_1 << std::endl;
   std::cout << "Size of string (wihtout null char): " << std::size(message_1) << std::endl; 

   // cout with null character terminated string
   std::cout << std::endl;
   std::cout << "cout with manual null character terminated string: " << std::endl;
   char message_2[20] ={'H','e','l','l','o','\0'};
   std::cout  << message_2 << std::endl;
   std::cout << "Size of string (with nul char): " << std::size(message_2) << std::endl;

   // Char arrays can also be modified like numerical arrays
   std::cout << std:: endl;
   std::cout << "Modifying element 0 of 'Hello' (i.e. 'H') to 'a': " << std::endl;
   message[0] = 'a';
   for (auto letter : message) {
    std::cout << letter << std::endl;
   }

   // Literal c string
   std::cout << std::endl;
   std::cout << "Literal c strings: " << std::endl;
   char message_literal [] {"Hello World!"}; // In this case the compiler understands that you want the string 'Hello World!' to be broken up into a char array which is terminated with a null character.
                                    // This is equivalent to char message_literal [] {'H','e','l','l','o',' ','W','o','r','l','d','!','\0'}
                                    // This is in contrast to char message [] {'H','e','l','l','o',' ','W','o','r','l','d','!'} where a null charactes is not automatically added.
    for (auto letter : message_literal) {
        std::cout << letter << std::endl;
    }
    std::cout << "Size of char message_literal [] {'Hello World!'} (length of text, +1 for null char): " << std::size(message_literal) << std::endl;

    // Unline strings, numerical arrays must be looped through to see all its values
    std::cout << std::endl;
    std::cout << "Numbers arrays: " << std::endl;
    int numbers[] {1,2,3,4};
    std::cout << "Printing numbers array via loop: " << std::endl;
    for (auto value : numbers) {
        std::cout << value << std::endl;
    }
    std::cout <<"Printing numbers array directly returns a memory address, not the contents of the array: " << std::endl;
    std::cout << numbers << std::endl;


   return 0;
}
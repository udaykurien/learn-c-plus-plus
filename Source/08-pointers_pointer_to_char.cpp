#include <iostream>

int main() {
    /*
    Difference btween character and numeral pointers:
    cout << char_pointer will print out the character or the literal
    cout << *char_pointer will print out the character or the first element/char of the literal
    cout << num_pointer will print out the memory address that the pointer is pointing to
    cout << *num_pointer will print the value of that memory address
    
    */

//    int *p_int {};
//    int test  =22;
//    p_int = &test;
//    std::cout<< test << p_int<<std::endl;

   char *p_char_var {nullptr};
   char char_var {'A'};
   p_char_var = &char_var;
   std::cout << "The address contained in pointer p_char_var is: " << p_char_var << ". And the value contained in p_char_var: " << *p_char_var << std::endl;
   std::cout << std::endl;

    const char *message {"Hello World!"};
    std::cout << "message: " << message << std::endl;
    std::cout << "&message: " << &message << std::endl;
    std::cout << "*message: " << *message << std::endl;
   //char *p_message {"Hello World"}; 
   // some versioins of c++ will try to expand the above literal as an array of constant characters (const char)
   // in that case there will be a type mis-match between the char array type (const char) and the pointer type (char).
   // Because of this mismatch we'll get a compiler error
   // The compiler throws an error because pointers can be used to modify arrays
   // Since the compiler has expanded the literal as a constant character array, and associated the pointer to the first element (which is also const) of the constant char array
   // any type of modifications to this constant element (via the non-constant char pointer) must be prohibited.
   // to avoid the error, perhaps the pointer type (const char) and char array type (const char) should match.
   // Modifyign the pointer type to be a const char pointer will prevent us from accidentally trying to modify it, and this will satisfy the compiler.
   
   //std::cout << p_message << " , " << *p_message << std::endl;
   // p_message is a pointer, but cout << p_message will still print the literal
   // *p_message will print the content of the pointer ie. the first char in the literal.
   // Because p_message points at the first element of Hello World!, i.e. H, H will be printed when cout << *p_message is encountered.

   // *p_message = 'B'; will result in a compiler error as the literal 'Hello World!' is expanded into a constant char array ( by char *p_message {"Hello World"};) that can not be modified.

   // In the code below we avoid the hassle of constant character array expansion by manually associating the address of the 0th element of the literal with the pointer
   char *p_message_2;
   char message_2[] {"Hello World!"};
   p_message_2 = &message_2[0];
   std::cout << &p_message_2 << " , " << *p_message_2 << std::endl;
   *p_message_2 = 'M'; // This is acceptable as the pointer is pointing to a regular char and not a const char.
   std::cout << p_message_2 << " , " << *p_message_2 << std::endl;

    return 0;
}
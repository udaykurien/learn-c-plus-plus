#include <iostream>
#include <cstring>

int main() {
    /*
    c-string, concatenation and copying (13:41:46):
    */
   //Concatenation
   std::cout << std::endl;
   std::cout << "std::strcat: " << std::endl;

   char dest[50] = "Hello";
   char src[50] = "World!";
   std::strcat(dest,src);
   std::strcat(dest, "Goodbye World!");
   std::cout << "dest: " << dest << std::endl;

   /*The above is not good practice because you have to put in a lot of manual
   effort to track the size of the string and to ensure that the concatenations
   don't exceed the array size*/

   std::cout << std::endl;
   std::cout << "More std::strcat: " << std::endl;

   char *dest1 {new char[30]{'F','i','r','e','l','o','r','d','\0'}};
   char *source1 = new char[30]{',','T','h','e',' ','P','h','e','o','n','i','x',' ','K','i','n','g','\0'};
   std::cout << "std::strlen(dest1): " << std::strlen(dest1) << std::endl;
   std::cout << "std::strlen(source1)" << std::strlen(source1) << std::endl;
   std::cout << "Concatenating: " << std::endl;
   std::strcat(dest1,source1);
   std::cout << "std::strlen(dest1): " << std::strlen(dest1) << std::endl;
   std::cout << "dest1: " << dest1 << std::endl;

   /*std::Strncat : concatenates n characters from src to dest and 
   returns a pointer to the result string
   signature: char *strncat(char *dest, const char *src, std::size_t count);*/
   std::cout << std::endl;
   std::cout << "std::strncat: " << std::endl;
   char dest2[50] = {"Hello"};
   char source2[50] { " There is a bird on my window"};
   std::cout << "The concatenated string is: " << std::strncat(dest2,source2,6) << std::endl;

   /*std::strcpy - signature: char* strcpy(char* dest, const char* src);*/
   std::cout << std::endl;
   std::cout << "std::strcpy: " << std::endl;
   const char* source3 = "C++ is a multipurpose programming language.";
   char *dest3 = new char[std::strlen(source3)+1];
   std::strcpy(dest3,source3);

   std::cout << "sizeof(dest3): " << sizeof(dest3) << std::endl;
   std::cout << "std::strlen(dest3): " << std::strlen(dest3) << std::endl;
   std::cout << "dest3: " << dest3 << std::endl;

   /*std::strncpy: Copy n characters from source to destination
   signature: char *strncpy(char *dest, const char *src, std::size_t count);*/
   std::cout << std::endl;
   std::cout << "std::strncpy" <<std::endl;
   const char* source4 = "Hello";
   char dest4[] = {'a','b','c','d','e','f','\0'};
   std::cout << "dest4: " << dest4 << std::endl;
   std::cout << "Copying..." << std::endl;
   std::strncpy(dest4,source4,5);
   std::cout << "dest4: " << dest4 << std::endl;


   return 0;
   }
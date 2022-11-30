#include <iostream>
#include <cstring>

int main() {

    /*
    C-string manipulation (13:09:39):
    https://en.cppreference.com/w/cpp/header/cstring
    */

   //std::strlen : Find length of string
   const char message1 [] {"The sky is blue."};
   //Array decays into pointer when we use const char*
   const char* message2 {"The sky is blue."};

   //strlen ignores the null character
   std::cout << "std::strlen(message1): " << std::strlen(message1) << std::endl;
   //sizeof includes the nullcharacter
   std::cout << "sizeof(message1): " << sizeof(message1) << std::endl;
   //strlen still works with pointers/decayed arrays
   std::cout << "std::strlen(message2): " << std::strlen(message2) << std::endl;
   //sizeof prints size of pointer/decayed array
   std::cout << "sizeof(message2): " << sizeof(message2) << std::endl;

   /*
   std::strcmp - signature : int strcmp(const char *lhs, const char *rhs);
   Returns negative value if lhs appears before rhs in lexicographical order
   Zero if lhs and rhs compare equal
   Positive if lhs appears after rhs in lexicographical order
   */
  std::cout << std::endl;
  std::cout << "std::strcmp: " << std::endl;
  const char * string_data1 {"Alabama"};
  const char * string_data2 {"Blabama"};

  //Print out the comparison
  std::cout << "std::strcmp(" << string_data1 << "," << string_data2 << "): " << std::strcmp(string_data1,string_data2) << std::endl;

  string_data1 = "Alabama";
  string_data2 = "Alabamb";

  //Print out comparison
  std::cout << "std::strcmp(" << string_data1 << "," << string_data2 << "): " << std::strcmp(string_data1,string_data2) << std::endl;
  
  string_data1 = "Alacama";
  string_data2 = "Alabama";

  //Print out comparison
  std::cout << "std::strcmp(" << string_data1 << "," << string_data2 << "): " << std::strcmp(string_data1,string_data2) << std::endl;

  /*
  std::strncmp(const char *lhs, const char* rhs, std::size_t n);
  Compare n characters in the strings
  Returns negative value if n characters of lhs appears before n characters of rhs in lexicographical order
   Zero if n characters lhs and rhs compare equal
   Positive if n characters of lhs appears after n characters of rhs in lexicographical order
  */
   
   string_data1 = "Alacama";
   string_data2 = "Alabama";
   size_t n {3};
   //Print out comparison
   std::cout << std::endl;
   std::cout << "std:strncmp: " << std::endl;
   std::cout << "std::strncmp(" << string_data1 << "," << string_data2 << "," << n << "): " << std::strncmp(string_data1,string_data2,n) << std::endl;

   string_data1 = "Alacama";
   string_data2 = "Alabama";
   n=4;
   //Print out comparison
   std::cout << "std::strncmp(" << string_data1 << "," << string_data2 << "," << n << "): " << std::strncmp(string_data1,string_data2,n) << std::endl;

   string_data1 = "Alabama";
   string_data2 = "Amabama";
   n=3;
   //Print out comparison
   std::cout << "std::strncmp(" << string_data1 << "," << string_data2 << "," << n << "): " << std::strncmp(string_data1,string_data2,n) << std::endl;

   /*
   std::strchr - Find the first occurrence of a character in a string and returns a pointer to that. If the character isn't found it returns a null pointer.
   */
   const char *str {"tttTry not. Do, or do not. There is no try."};
   char target  = 'T';
   const char *result =str; //point result points to the same memory address as str
   std::cout << std::strchr(result,target) <<std::endl;;
   
   //WAP to count all occurrences of a letter in a string
   std::cout << std::endl;
   int iterations {};
   std::cout << *result << std::endl;
   while((result=std::strchr(result,target)) != nullptr) {
    std::cout << "Found '" << target << "' starting at '" << result << "'\n";
    ++result;
    ++iterations;
    std::cout << *result << std::endl;
   }
   std::cout << "iterations: " << iterations <<std::endl;
   if (result == nullptr) {
    std::cout << "The final value of result is a nullptr" << std::endl;
   } else {
    std::cout << "It is not nullptr" << std::endl;
   }

   /*
   std::strrchr - Find the last occurrence of a character in a string and return pointer to it. If the character is not present, return a nullptr.
   */
  std::cout << std::endl;
  std::cout << "std::strrchr: " << std::endl;
  char input[] = "/home/usr/hello.cpp";
  char *output;
  output = std::strrchr(input,'/');
  if (output){
    std::cout << output << std::endl;
    std::cout << output +1 << std::endl;
  }

   return 0;
}
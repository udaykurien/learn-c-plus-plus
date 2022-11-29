#include <iostream>

int main() {

    /*
    Character manipulation (12:46:27):
    - Check if char is alphanumeric
    - Check if char is alphabetic
    - Check if char is blank
    - Check if char is uppercase or lowercase
    - Check if char is digit
    - Turning a char to lowercase/uppercase using the std::tolower() and std::toupper() functions
    (en.cppreference.com)
    */

   //Check if character is alphanumeric - std::isalnum - 0:False, Non 0:True
   std::cout << std::endl;
   std::cout << "std::isalnum: " << std::endl;

   std::cout << "Is 'C' alphanumeric? : " << std::isalnum('C') << std::endl;
   std::cout << "Is '5' alphanumeric? : " << std::isalnum('5') << std::endl;
   std::cout << "Is '^' alphanumeric? : " << std::isalnum('^') << std::endl;

   //Using std::isalnum as a test condition
   char input_char {'*'};
   if(std::isalnum(input_char)){
    std::cout << input_char << " is alphanumeric." << std::endl;
   } else {
    std::cout << input_char << " is not alphanumeric." << std::endl;
   }

   //Check if character is alphabetic - std::isalpha - 0:False, Non 0:True
   std::cout << std::endl;
   std::cout << "Is 'C' alpha? : " << std::isalpha('C') << std::endl;
   std::cout << "Is '5' alpha? : " << std::isalpha('5') << std::endl;
   std::cout << "Is '^' alpha? : " << std::isalpha('^') << std::endl;

   //Check if character is blank - std::isblank - 0:False, Non 0:True
   std::cout << std::endl;
   std::cout << "Is 'C' blank? : " << std::isblank('C') << std::endl;
   std::cout << "Is ' ' blank? : " << std::isblank(' ') << std::endl;

   //WAP to count blanks in a string
   std::cout << std::endl;
   std::cout << "Counting number of blank spaces in a string." << std::endl;
   char message[] = "Hello there. How are you doing? The sun is shining.";
   size_t blank_count{0};
   for(size_t i{0}; i<std::size(message);i++) {
    if(std::isblank(message[i])){
        std::cout << i << " , ";
        blank_count++;
    }
   }
   std::cout << std::endl;
   std::cout << "Total number of blank characters: " << blank_count << std::endl;

   //WAP to count the number of upper and lowercase characters in a string - std::isupper, std::islower
   std::cout << std::endl;
   std::cout << "Counting upper and lower case characters in a string" << std::endl;
   char thought[] {"The C++ Programming Language is one of the most used on the Planet"};
   int lowercase_count = 0;
   int uppercase_count = 0;
   for (auto letter : thought){
    if (std::islower(letter)){
        ++lowercase_count;
    } else if (std::isupper(letter)) {
        ++uppercase_count;
    }  
   }
   std::cout << "The lower and upper case counts are: " << lowercase_count << " and " << uppercase_count << " ,respectively" << std::endl;

   //Check if character is alphabetic - std::isdigit - 0:False, Non 0:True
   std::cout << std::endl;
   std::cout << "Is 'C' digit? : " << std::isdigit('C') << std::endl;
   std::cout << "Is '5' digit? : " << std::isdigit('5') << std::endl;
   std::cout << "Is '^' digit? : " << std::isdigit('^') << std::endl;

   //Chaning string case using std::tolower() and std::toupper()
   std::cout << std::endl;

   //WAP to convert a string to (a)uppercase (in a new array) and (b)lowercase (in place)
   std::cout << "Changing to uppercase in a new array: " << std::endl;
   char input_string[] {"Home. The feeling of belonging"};
   char dest_string[std::size(input_string)];  
   for (size_t i{}; i<std::size(input_string);++i) {
    dest_string[i] = std::toupper(input_string[i]);
   }
   std::cout << "The converted string (in the new array is): " << dest_string << std::endl;

   std::cout << "Changing to lower case in place: " << std::endl;
   for (size_t i{}; i < std::size(dest_string); ++i) {
    dest_string[i] =  std::tolower(dest_string[i]);
   }
   std::cout << "The converted string (in the new array is): " << dest_string << std::endl;
   
   return 0;
}
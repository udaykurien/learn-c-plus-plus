#include <iostream>
#include <string>

int main() {

    /*
    Declaring and using std::string (14:03:39):
    std::string wraps on top of char arrays and makes it easire to work with strings
    */

   std::string full_name; //Empty string of type string
   std::string planet {"Earth. Where the sky is blue"}; //Initialise string literal
   std::string preferred_planet{planet}; //Initialize with other existing string
   std::string message{"Hello there",5}; //Initialize with part of a string literal. //Contains hello
   std::string weird_message(4,'e'); //Initialize with multiple copies of char //contains eeee
   std::string greeting{"Hello World"};
   std::string saying_hello{greeting,6,5}; //Initialize with part of an existing std::string starting at index 6, taking 5 characters. Will contain World.

   std::cout << "full_name: " << full_name << std::endl;
   std::cout << "planet: " << planet << std::endl;
   std::cout << "prefered_planet: " << preferred_planet << std::endl;
   std::cout << "message: " << message << std::endl;
   std::cout << "weird_message: " << weird_message << std::endl;
   std::cout << "greeting: " << greeting << std::endl;
   std::cout << "say hello: " << saying_hello << std::endl;

   //Changing std::string variable at runtime with larger/smaller values than it was initialized with it possible. The underlying character array is dynamically resized by the library.
   planet = "Earth. Where the sky is blue.Earth. Where the sky is blue.Earth. Where the sky is blue.Earth. Where the sky is blue.";
   std::cout << std::endl;
   std::cout << "planet: " << planet << std::endl;

   //How does this re-assignment actually work?
   std::cout << std::endl;
   const char * planet1 {"Earth. Where the sky is blue."}; //Initial assignment is a pointer to a memory location containing the start of the char aray
   std::cout << "planet1: " << planet1 << std::endl;
   planet1="Earth. Where the sky is blue.Earth. Where the sky is blue."; //Re-assignment is by pointing to new memory location containing the start of the new character array
   std::cout << "planet1: " << planet1 << std::endl;
   //One difference to note, is that when using std::string, after reassignment, the initial memory is returned to the OS
   //With simple pointers, the initial memory may not be returned to the OS


   return 0;
}
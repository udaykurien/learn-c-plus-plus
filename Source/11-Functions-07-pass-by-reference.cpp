#include <iostream>

void say_age(int &age);

int main() {

    /*
    Pass by refernce (15:57:50):
    Since references are just aliases of the original variables (ie different names for the same memory location), this method allows the function to modify the conetents in the memory locations of the arguments passed to it.
    */

   int age {23};

   std::cout << "age - before: " << age << std::endl;
   std::cout << "Address of age in main() - before: " << &age << std::endl;
   say_age(age); //Passing address of variable
   std::cout << "age - after: " << age << std::endl;
   std::cout << "Address of age in main() - after: " << &age << std::endl;
   return 0;
}

void say_age(int &age) { 
    ++age; 
    std::cout << "hello! You are " << age << " years old." << std::endl;
    std::cout << "Address of age in say_age(): " << &age << std::endl;
}
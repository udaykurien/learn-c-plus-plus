#include <iostream>

void say_age(int age);

int main() {

    /*
    Pass by value (15:42:32):

    */

   int age {23};

   std::cout << "age - before: " << age << std::endl;
   std::cout << "Address of age in main() - before: " << &age << std::endl;
   say_age(age); //Passing by value
   std::cout << "age - after: " << age << std::endl;
   std::cout << "Address of age in main() - after: " << &age << std::endl;

   return 0;
}

void say_age(int age) { //The parameter is a copy of the argument. Changes to it will not be reflected in the original arguments.
    ++age; //Changing the copy. Outside age not affected.
    std::cout << "hello! You are " << age << " years old." << std::endl;
    std::cout << "Address of age in say_age(): " << &age << std::endl;
}
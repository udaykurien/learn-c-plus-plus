#include<iostream>

void say_age(int *age);

int main(){

    /*
    Pass by pointer (15:50:32):
    Unlike pass by value, pass by pointer passes the acutal memory location to the function. Any modifications made to the contents of this memory location, while inside the functop, will persist when we return to main.
    */

   int age {23};

   std::cout << "age - before: " << age << std::endl;
   std::cout << "Address of age in main() - before: " << &age << std::endl;
   say_age(&age); //Passing address of variable
   std::cout << "age - after: " << age << std::endl;
   std::cout << "Address of age in main() - after: " << &age << std::endl;

   return 0;
}

void say_age(int *age) { 
    ++(*age);
    std::cout << "hello! You are " << *age << " years old." << std::endl;
    std::cout << "Address of age in say_age(): " << age << std::endl;
}
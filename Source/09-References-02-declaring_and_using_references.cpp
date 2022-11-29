#include <iostream>

int main() {

    /*
    Declaring and using references (12:12:01):
    Remember an alias is a reference variable
    Important:
    References must be initialized when they are declared.
    Declaration without initialization is illegal/will cause compiler error. 
    Synatx: int& alias; int & alias; int &alias;   
    */

   int int_val {45};
   double double_val {33.65};

   int& ref_1_to_int_val{int_val}; //Reference through initialization
   int& ref_2_to_int_val = int_val; //Reference through assignment
   double& ref_1_to_double_val{double_val};

   //Values of original variables and their references
   std::cout << "int_val: " << int_val << std::endl;
   std::cout << "ref_1_to_int_val: " << ref_1_to_int_val << std::endl;
   std::cout << "ref_2_to_int_val: " << ref_2_to_int_val << std::endl;
   std::cout << "double_val: " << double_val << std::endl;
   std::cout << "ref_1_to_double_val: " << ref_1_to_double_val << std::endl;

   std::cout << std::endl;

   //Memory addresses of original variables and their references
   std::cout << "&int_val: " << &int_val << std::endl;
   std::cout << "&ref_1_to_int_val: " << &ref_1_to_int_val << std::endl;
   std::cout << "&ref_2_to_int_val: " << &ref_2_to_int_val << std::endl;
   std::cout << "&double_val: " << &double_val << std::endl;
   std::cout << "&ref_1_to_double_val: " << &ref_1_to_double_val << std::endl;

   std::cout << std::endl;

   //Sizeof types, original variables and their references
   std::cout << "sizeof(int): " << sizeof(int) << std::endl;
   std::cout << "sizeof(int&): " << sizeof(int&) <<std::endl;
   std::cout << "sizeof(int_val): " << sizeof(int_val) << std::endl;
   std::cout << "sizeof(ref_1_to_int_val: " << sizeof(ref_1_to_int_val) << std::endl;
   std::cout << "sizeof(ref_2_to_int_val): " << sizeof(ref_2_to_int_val) << std::endl;
   std::cout << "sizeof(double): " << sizeof(double) << std::endl;
   std::cout << "sizeof(double&): " << sizeof(double&) <<std::endl;
   std::cout << "sizeof(double_val): " << sizeof(double_val) << std::endl;
   std::cout << "sizeof(ref_1_to_double_val): " << sizeof(ref_1_to_double_val) << std::endl;

   std::cout << std::endl;

   //Modifying value of a reference
   //Modifying the value of the referenced (original) varialbe is like modifying the value of a reference
   std::cout << "Modifying the values of a reference: " << std::endl;
   std::cout << "ref_1_to_int_val =55; " << std::endl;
   ref_1_to_int_val = 55;
   std::cout << "int_val: " << int_val << std::endl;
   std::cout << "ref_1_to_int_val: " << ref_1_to_int_val << std::endl;
   std::cout << "ref_2_to_int_val: " << ref_2_to_int_val << std::endl;
   std::cout << "&int_val: " << &int_val << std::endl;
   std::cout << "&ref_1_to_int_val: " << &ref_1_to_int_val << std::endl;
   std::cout << "&ref_2_to_int_val: " << &ref_2_to_int_val << std::endl;

   return 0;
}
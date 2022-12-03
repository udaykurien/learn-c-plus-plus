#include <iostream>

int main () {

    /*
    Capture lists:
    -------------------------------------------------------------
    auto func_name = [capture_list] (parameters) -> return_type{
        // function body
    };
    --------------------------------------------------------------
    Capture lists allow us to use variables from the scope outside the function, inside the function.
    If our capture list is empty, the lambda function will not have access to variables outside the scope of the function.
    How are capture lists different from parameters?
    */

   //Capture list example:
   double a{10}, b{20};
   auto func = [a,b](){
    std::cout << "a+b: " << a+b << std::endl;
   };
   func();
   //In the above function (func), if the capture list were empty, the lambda function would not have access to variables a and b. 

   //Capturing by value: what we have in the lambda function is a copy.
   //The capture list stores and saves (ie captures or copies) the last value of the variable preceeding the declaration of the capture function. Changes to this variable, anywhere after the lambda function, will not be reflected in the lambda function.
   std::cout << std::endl;
   std::cout << "Capture by value: " << std::endl;
   int c{40};
   c+=20;

   auto func2 = [c](){
    std::cout << "Inner value: " << c << ", &c: "<< &c << std::endl;
   };

   c+=20;
   for(size_t i{}; i<5; i++) {
    std::cout << "Outer value: " << c << ", &c: "<< &c << std::endl;
    func2();
    ++c;
   }

   //Capture by refernce: what we have in the lambda function is an alias
   //The capture list saves a refernce to the outside variable. Therefore the capture list and outside scope will be accessing the same memory location. Any changes made to this memory location will be reflected in, both, the lambda function and the outside scope.
   std::cout << std::endl;
   std::cout << "Capture by reference: " << std::endl;
   int d{40};
   d+=20;

   auto func3 = [&d](){
    // ++d;
    std::cout << "Inner value: " << d << ", &d: "<< &d << std::endl;
   };

   d+=20;
   for (size_t j=0; j<5;j++) {
    std::cout << "Outer value: " << d << ", &d: "<< &d << std::endl;
    func3();
    ++d;
   }

   return 0;
}
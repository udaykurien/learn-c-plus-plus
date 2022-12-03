#include <iostream>

int main() {

    /*
    Capture all in context (17:34:26):
    Capture every thing living outside the context of the lambda function
    -------------------------------------------------------------
    auto func_name = [capture_list] (parameters) -> return_type{
        // function body
    };
    --------------------------------------------------------------
    // To capture everything by value, set the capture list equal to '=':
    auto func_name = [=] (parameters) -> return_type{
        // function body
    };

    // To capture everything by reference, set the capture list equal to '&':
    auto func_name = [&] (parameters) -> return_type{
        // function body
    };
    */

   
   //Capture all by value
   std::cout << std::endl;
   std::cout << "Capture all by value: " << std::endl;
   int c{42}, d{54};
   double e{3.14}, f{22.7};
   
   auto func = [=](){
    std::cout << "Inner value (e): " << e << ", &e: " << &e << " | ";
    std::cout << "Inner value (d): " << d << ", &d: " << &d << std::endl;  
   };

   for (size_t i{}; i < 5; i++) {
    std::cout << "Outer value (e): " << e << ", &e: " << &e << " | ";
    std::cout << "Outer value (d): " << d << ", &d: " << &d << std::endl;
    func();
    ++e;
    ++d; 
   }

   //Capture all by reference
   std::cout << std::endl;
   std::cout << "Capture all by reference: " << std::endl;
   int j{42}, k{54};
   double l{3.14}, m{22.7};
   
   auto func2 = [&](){
    std::cout << "Inner value (k): " << k << ", &k: " << &k << " | ";
    std::cout << "Inner value (m): " << m << ", &m: " << &m << std::endl;  
   };

   for (size_t i{}; i < 5; i++) {
    std::cout << "Outer value (k): " << k << ", &k: " << &k << " | ";
    std::cout << "Outer value (m): " << m << ", &m: " << &m << std::endl;
    func2();
    ++k;
    ++m; 
   }

   return 0;
}
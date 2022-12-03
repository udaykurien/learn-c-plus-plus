#include <iostream>

int main () {

    /*
    Declaring and using lambda functions (16:49:39):
    Lambda function signature:
    -------------------------------------------------------
    [capture list] (parameters) -> return type {
        Function body
    };
    -------------------------------------------------------
    Parameters - The place we can pass arguments when we call the lambda function.
    Return type - Explicit declaration isn't required. Its type can be deduced by the compiler.
    Function body - Definition of the lambda function
    */

   //eg lambda function to print hello world
   // This function takes no arguments, so the paranthesis are empty
   [](){
    std::cout << "Hello World!" << std::endl;
   };

   //Assigning a variable name (func) to this lambda function
   auto func = [](){
    std::cout << "Hello World!" << std::endl;
   };
   //Calling the lambda function
   func();

   //Calling a lambda function directly after defintion, without giving it a name
   [](){
    std::cout << "Hello Mars!" << std::endl;
   }(); //The call is made by appending paranthesis before the semicolon.
   //The appended paranthesis are empty as this function does not take any arguments.

   //Example of a lambda function that takes parameters
   [](double a, double b){
    std::cout << "a+b: " << a+b << std::endl;
   }(21.8,28.3); //Calling the lambda function directly with arguments

   //Make the lambda function return something:
   auto result = [](double a, double b){
    return (a+b);
   }(21.8,28.3);
   std::cout << "Result: " << result << std::endl;

   //Putting a lambda function directly in a cout statement
   std::cout << "Result: " << [](double a, double b){
    return(a+b);
   }(12.1,15.7) << std::endl; //Notice that the semi-colon is shifted from the end of the function call (arguments in paranthesis), to the end of the entire command.

   //Explicitly specify return type (->type):
   //This forces the lambda function to return a specific type
   auto result2 = [](double a, double b)->int{
    return (a+b);
   }(12.1,15.7);
   std::cout << "Result2: " << result2 << std::endl;

   //Pass arguments into lambda function when calling it by name
   auto func2 = [](double a, double b) -> double{
    std::cout << "a: " << a << ", b: " << b << ", a+b: " << a+b << std::endl;
    return (a+b);
   };
   int ans = func2(10.5,11.6);
   func2(17,13);
   
   return 0;
}
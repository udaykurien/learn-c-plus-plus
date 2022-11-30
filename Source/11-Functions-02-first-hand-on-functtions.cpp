#include <iostream>

//example function
void say_hello(){
    //Function signature : say_hello (no params, so the function signature will not contain them)
    std::cout << "Hello World!" << std::endl;
    //no return as function is defined to be void return or we can return nothing as follows
    return ;
}

void enter_bar(unsigned int age){
    if (age >= 18) {
        std::cout << "You're old enough to enter the bar." << std::endl;
    } else{
        std::cout << "You're not old enough to enter the bar." << std::endl;
    }
}

int max(int a, int b){
    if (a>b)
        return a;
    else
        return b;
}

void increment_input (int a){
    std::cout << "Parameter before increment (inside the function): " << a << std::endl;
    ++a;
    std::cout << "Parameter after increment (inside the function): " << a << std::endl;
}

int luck_number (){
    return 99;
}

/*
int luck_number (){
    return 99;
}
*/ //Error becaus function signature (function name + params(number and type)) is a duplicate

int luck_number (int a){
    return 99;
}// Not an error be function signature (function name + params(number and type)) is not a duplicate

/*
int luck_number (int b){
    return 99;
}
*/ //Error because funtion signature (function name + params(number and type)) is a duplicate

int main() {

    /*
    First hand on functions (14:28:25):
    A function is a resuable piece of code that can take a number of optional inputs and produce some desirable output.
    
    Syntax:
    return_type function_name(param1,param2,...){
        //Operations
        return return_value;
    }

    Each function in C++ must be unique, otherwise C++ will have trouble determining which version of a function to use.
    Uniqueness of function is determined by the function signature.
    The function signature is a combinationi of function name + function parameters.

    Calling or using a function that contains a return statement:
    result_var = function_name (arg1,arg2);

    Calling a void function:
    function_name (arg1,arg2);

    Nomenclature:
    - When a function is called, you pass in arguments eg. ans = max(arg1,arg2)
    - When a function is defined, you define parameters eg. int max(param1,param2)
    - or arguments are parameters that are passed into the function at time of calling and parameters are the things that can be passed into the functiion, and they are defined during function declaration.

    Cautions:
    - Beware of implicit conversions when calling a function. eg. float to int
    - The parameters of a function are copies of the arguments passed to it. Modifying these parameters within the function will not change the actual variables/arguments that were passed to it.

    */
   say_hello();
   enter_bar(15);
   int ans = max(2,7);
   std::cout << "ans=max(num1,num2): " << ans << std::endl;
   int number = luck_number();
   std::cout << "number=lucky_number(): " << number << std::endl;

   //Otherways to call functions
   std::cout << std::endl;
   int a_value = 14, b_value = 10;
   int a{33}, b{41};
   
   std::cout << "Calling the enter_bar function: " << std::endl;
   enter_bar(22); //Function call

   int maximum_number {max(a_value,b_value)}; // Function call, can store the return value in a variable and use that later on.
   std::cout << "max(" << a_value << "," << b << "): " << max(a,b) << std::endl;

   std::cout << "Calling say_hello mehtod: " << std::endl;
   say_hello();

   //Implicit conversions can yeild unexpected results
   double val1 =33.56;
   double val2 = 33.13;

   int max_val = max(val1,val2); // val1 and val2 implicitly converted from double to int, because in declaration of max, its paramters are of type int
   std::cout << "max(33.56,33.13): " << max_val << std::endl; 

   //Parameters in functions are copies of the argument, modifying the parameter, doesn't change the original argument/variable
   std::cout << std::endl;
   int b2 =32;
   std::cout << "Argument before increment (outside the function): " << b2 << std::endl;
   increment_input(b2);
   std::cout << "Argument after increment (outside the function): " << b2 << std::endl;

   return 0;
}
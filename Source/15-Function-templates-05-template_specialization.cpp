#include <iostream>
#include <string>
#include <cstring>

//Function template
template <typename T> T maximum (T a, T b);
//Template specialization
template <>
const char* maximum <const char*> (const char* a, const char* b);

int main () {

    /*
    Template specialzation (18:48:56):
    - Feature to bypass the default mechanism of how function templates work.(Used when usual function template is not meeting our needs, eg. with pointers)
    - Usually the compiler generates a function instance from the function template, based on the function call.
    - However, when the compiler encounters a function call with argument types that matches a template specialization, it will preferentially use the template specialization, instead of generation a function instance from the usual function template.

    Syntax:
    //Function template
    template    <typename T>    T               maximum     (T a, T b);
    [keyword]   [auto-type]     [return-type]   [func-name] [parameters]

    //Template specializaton
    template    <>
    [keyword]   [angled-brackets]
    const char*     maximum     <const char*>   (const char* a, const char* b);
    [return-type]   [func-name] [argument-type] [parameters]

    [func-name] : should be same in function template & function specializaton
    [argument-type] : the specific argument type for which we want the compiler to use a specialized template. 
    */

    int a{10},b{23};
    double c{34.7}, d{23.4};
    std::string e{"hello"}, f{"world"};

    int max_int = maximum(a,b); //int type deduced
    double max_double = maximum(c,d); //double type deduced
    std::string max_str = maximum(e,f); //string type deduced (by default compare lexicographically)

    const char* g{"wild"}; //null terminated c-strings
    const char* h{"animal"};

    std::cout << "max(const char*): " << maximum(g,h) << std::endl;
    //With regular function template:
    //-------------------------------
    //This wont do what you expect.
    //This is because the compiler will create a function instance with pointer arguments from the function template. The function instance will then compare the contents of the pointer variable (memory addresses) rather than the data in the memory addresses, as the pointers aren't dereferenced within the function definition.

    //Template specializaton provides a way to avoid this:
    //----------------------------------------------------
    //With template specializtion  we specify a special function instance (function template prototype + definition), that is to be executed, if a certain type of argument, that matches the template prototype, is passed in.

    return 0;

}

//Function template
//Compiler makes function instance from this template for all types (excpet pointer type in this example)
//If we didn't have a specialized template, this function template would also be used for pointers. It would compare pointers directly rather than compare the data held within the memory the pointer points to.
template <typename T> T maximum(T a, T b){
    return (a>b)?a:b;
}

//Specialized template
//Compiler makes special function instance from this template for pointer type
template <>
const char* maximum <const char*> (const char* a, const char* b) {
    return (std::strcmp(a,b) > 0)?a:b; //strcmp compares the data (c strings) im the memory addresses pointed at by the char pointers.This doesnt compare pointers directly.
}
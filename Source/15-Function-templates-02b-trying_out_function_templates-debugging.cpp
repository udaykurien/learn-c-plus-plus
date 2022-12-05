#include <iostream>

template <typename T>
T maximum(T a, T b) {
    return (a>b)? a :b;
}

int main () {

    /*
    How to debug function templates?
    - Since the function templates are used to generate function instances (which is what is actually used), it can be hard to debug. The process of debugging (and allowing us to analyze the actual contents of the function instances) is described next.
    (1) In visual studio code insert a break point at the call to the function (auto result = maximum(x,y);)
    (2) Go to the run tab on the left hand side and use the debugging tools
    Look up how to setup a debugger in linux.
    */

   int x{7}, y{5};
   auto result = maximum(x,y);
   std::cout << "result: " << result << std::endl;

   //Function templates with pointers: DISASTER!!
   int *p_x {&x};
   int *p_y {&y};
   auto result2 = maximum(p_x,p_y);
   std::cout << "result: " << result2 << std::endl;
    std::cout << "*result: " << *result2 << std::endl;
    /*
    The effect that calling the maximum template on pointers is as follows:
    
    Template:
    template <typename T>
    T maximum(T a, T b) {
    return (a>b)? a :b;
}
    1) a and b parameters will become the type int pointers
    2) The body of the template will compare a and b and return the larger value.
    3) Since a and b contain the memory addresses they are pointing to (and not the values in those memory locations), comparison without dereferencing will return the larger memory address.
    4) So we end up comparing the memory address instead of the values held in those memory adresses.
    */
    
    
    return 0;

}

/*
Notes:
- Function templates are just blueprints, they're not real function declaration and definitions.
- Real function declarations are definitions, aka template instances are created when you call the function with arguments.
- If the template parameters are of the same tyep (T,T), the the arguments you call the function with must also match, otherwise you get a compiler error.
- Template instances won't always do what you want. A good example is whaen you call our maximum function with pointers. DISASTER!
- There are looks like cppinsights.io that can show you templalte instantiations. You can even use the debugger to infer that information from the activation record of a template function.
- The arguments passed to a function template must support the operations are are done in the body of the function.
*/

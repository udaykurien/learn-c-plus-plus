#include <iostream>
#include <concepts>
#include <type_traits>

    // Setting up concepts
    // --------------------    
    // Syntax 1
    template <typename T>
    concept MyIntegral = std::is_integral_v<T>;

    // Syntax 2
    template <typename T>
    concept Multipliable = requires (T a, T b) {
        a*b; // Just makes sure syntax is valid (does not check the value of a*b)
        // Over here we have just one contraint, but we could additional constraints if we wanted
    };

    // Syntax 3
    template <typename T>
    concept Incrementable = requires (T a) {
        // Concept with multiple constraints
        // The type accepted by/valid for this concept, is the type that must satisfy all of the following operations:
        a+=1;
        ++a;
        a++;
    };

    // Using concepts in function templates
    // ------------------------------------
    // Syntax 1 - function template using concept MyIntegral
    template <typename T>
    requires MyIntegral<T>  // We require the function call to satisfy our own concept
    T add_MyIntegral_1 (T a, T b) {
        return a+b;
    }

    // Syntax 2 - function template using concept MyIntegral
    template <MyIntegral T>
    T add_MyIntegral_2(T a, T b) {
        return a+b;
    }

    // Syntax 3 - function template using concept MyIntegral
    // MyIntegral auto add_3 (MyIntegral auto a, MyIntegral auto b) {
    // or
    auto add_MyIntegral_3 (MyIntegral auto a, MyIntegral auto b) {
        return a+b;
    }

    // Function template using concept Multipliable
    template <typename T>
    requires Multipliable<T>
    T add_Multipliable_1 (T a, T b){
        return a+b; //Works as multipliable data types are also additive
    }

    // Function template using concept Incrementable
    template <typename T>
    requires Incrementable<T>
    T add_Incrementable_1 (T a, T b){
        return a+b; //Works as incrementable data types are also additive
    }

int main () {

    /*
    Building your own concepts (19:25:33):
    - Till now we have been using concepts from the standard library that are built into the C++ program.
    - Now we will build our own concepts.

    Syntax 1: (does parameter type check)
    ---------
    template                    <typename T>
    [template declaration]      [Parameter to be constrained]
    concept     MyIntegral  =   std::is_integral_v<T>;
    [keyword]   [concept name]  [concept requirements]

    std::is_integral_v<T> is a type trait which specifies what works for the concept MyIntegral. This enforces the template parameter to be integral.
    Incidentally, this is how the c++ std::integral concept is built in the standard library (see previous lesson for implementation.)

    The concept is satisfied when the type trait is evaluate to true at compile time.

    Syntax 2: (does parameter syntax check)
    ---------
    template <typename T>
    concept Multipliable = requires (T a, T b) {
        a*b; // Syntax we want to make sure concept parameters satisfy (eg this will work for ints but not strings)
    };

    Syntax 3: (does parameter syntax check)
    ---------
    template <typename T>
    concept Incrementable = requires (T a) {
        a+=1;
        ++a;
        a++;
    };
    The body of the concept defines the type restriction. The type of the concept parameters must be incrementable. 
    Any template parameter using this concept must be incrementable, otherwise the concept will return a false during compile time and a function instance for that argument/parameter type will not be generated from the function template by the compiler.
    */

    
    //Example 1
    int x{6};
    int y{7};

    auto result1 = add_MyIntegral_1(x,y);
    /*
    - This command will tell the compiler to consult function template add_1.
    - The function template add_1, will tell the compiler to check if the argument types (in the function call), satisfy the type constraints in concept MyIntegral.
    - The compiler consults 'concept' MyIntegral.
    - Because the argument types satisfy the constraints laid out in the concept MyIntegral, the compiler will proceed to generate a function instance (of type int) from the function template add_1.
    - After generating the function instance the code will be compiled.
    */
    std::cout << "add_MyIntegral_1(x,y): " << result1 << std::endl;

    /*
    //Example 2
    double x2 {6.5};
    double y2 {7.3};
    auto result2= add_MyIntegral_1(x2,y2);
    // This call will fail as the argument types (double) will not satisfy the concept constraint, which requires the arguments to be of type integral.
    */

    //Example 3
    double x2 {6.5};
    double y2 {7.3};

    auto result3 = add_Multipliable_1(x2,y2);
    std::cout << "add_Multipliable_1(x2,y2): " << result3 << std::endl;

    /*
    //Example 4
    std::string x4 {"hello"};
    std::string y4 {"world"};
    auto result2= add_Multipliable_1(x4,y4);
    // This call will fail as the argument types (strings) will not satisfy the concept constraint, which requires the arguments to be of a type that is multipliable (eg. int, double etc).
    */

    //Example 5
    double x5 {10};
    double y5 {9};

    auto result5 = add_Incrementable_1(x5,y5);
    std::cout << "add_Incrementable_1(x5,y5): " << result5 << std::endl;

    /*
    //Example 6
    std::string x6 {"hello"};
    std::string y6 {"world"};
    auto result2= add_Incrementable_1(x6,y6);
    // This call will fail as the argument types (strings) will not satisfy the concept constraint, which requires the arguments to be of a type that is incrementable (eg. int etc).
    */   

    return 0;

}

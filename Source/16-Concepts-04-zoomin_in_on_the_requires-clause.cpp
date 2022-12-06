#include <iostream>
#include <concepts>
#include <string>

// Simple requirement : Concept syntactically valid, but expression not enforced
template <typename T>
concept TinyType = requires (T t){
    sizeof(T) <= 4; //Simple requirement: Only check syntax
    //ie the type that will be accepted by this concept is the type for which the expression sizeof(T) <= 4 can be evaluated. It doesn't matter if the expression evaluates to true or fales. 
    //As long as the type of the arguments is such that the expression sizeof(argument) <=4 is valid, it will be accpeted. The size of the type of the argument may be larger or smaller than 4, but that will not impact the concept.
    //IMP: This concept doesn't not enforce that the size of T <=4. For cases where we have to enforce that the size of T <= 4, look at the next example
};
TinyType auto add(TinyType auto a, TinyType auto b){
    return a+b;
}

// Nested requirement: Concept syntacticaclly valid, and expression is enforced
template <typename T>
concept TinyType2 = requires(T t) {
    // Argument is allowed only if both the following conditions are met:
    sizeof(T) <= 4; // Must yield valid syntax for the argument (T t).
    requires sizeof(T) <= 4; // Expression must be true for the argument (T t).
};
TinyType2 auto add2(TinyType2 auto a, TinyType2 auto b){
    return a+b;
}

// Compound requirement:
template <typename T>
concept Addable = requires (T a, T b) {
    //no except is optional
    {a+b} noexcept -> std::convertible_to<int>; //Compound requirement
    //{a+b} -> std::convertible_to<int>; //(alternate formulation without no exception)
    // Checks that a + b should be convertible to int
    //Checks if a+b is valid syntax, (doesn't throw exceptions (optional)), and the result of a+b must be convertible to int(optional)
};
Addable auto add3(Addable auto a, Addable auto b){
    return a+b;
}


int main () {

    /*
    requires clause: zooming in (19:42:48):
    The requires clause can take in four kinds of requirements:
    1. Simple requirements
    This is what we've seen so far.

    2. Nested requirements
    
    3. Compound requirements
    Allows us to more explicitly define the characteristics of the concept
    
    4. Type requirenments
    Advanced. Not covered in this course.
    */

    //Simple requirement tests
    //-------------------------
    std::cout << std::endl;
    char x1{67}, y1{56}; //4 bytes
    std::cout << "x1,y1-> char (4bytes) | add(x1,y1): " << add(x1,y1) << std::endl;

    double x2 {10.7} , y2{15.4}; //8bytes
    std::cout << "x2,y2-> double (8bytes) | add(x1,y1): " << add(x2,y2) << std::endl;
    // Works, because the expression "sizeof(T) <= 4;" in the concept definition is not evaluated, instead it is only used as a syntactic check. 

    //Nested requrement tests
    //-----------------------
    std::cout << std::endl;
    std::cout << "x1,y1-> char (4bytes) | add2(x1,y1): " << add2(x1,y1) << std::endl;
    //std::cout << "x2,y2-> double (8bytes) | add2(x1,y1): " << add2(x2,y2) << std::endl; -- Compiler error because concept additionally 'requires sizeof(T) <= 4;'. i.e. 'sizeof(T) <= 4;' must evaluate to true for the arguments to be accepted by the concept.

    //Compound requirement
    //--------------------
    std::cout << std::endl;
    std::cout << "x1,y1-> char (4bytes) | add3(x1,y1): " << add3(x1,y1) << std::endl;
    std::cout << "x2,y2-> double (8bytes) | add3(x1,y1): " << add3(x2,y2) << std::endl;
    // Both char and double are convertible to int

    std::string x3{"hello"}, y3{"world"};
    // std::cout << "x2,y2-> string) | add3(x3,y3): " << add3(x3,y3) << std::endl; //Compiler error as string is not convertible to int.

    //------------------------------------------------------------------------
    // Q) Why is the expression in a compound requirement evaluated, while the expression in a simple requirement is not evaluated? 
    //--------------------------------------------------------------------------

    return 0;

}

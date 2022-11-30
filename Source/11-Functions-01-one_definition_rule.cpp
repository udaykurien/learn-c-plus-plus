//redo this lesson after finishing lesson on classes
#include <iostream>

//Variable
double weight {};//Declaration and defintion
//double weight {};//re-declaration, definition -> compiler error
//Evern if we were to re-define weight globally, in another file, we'd get a linker error as it would not know which definition of double weight to go with

double add(double a, double b); //function declaration

struct Point { //First class definition - acceptable
    double m_x{};
    double m_y{};
};

int main (){

    /*
    One definition rule (14:12:50):
    Defintions can't appear more than once in the entire program or translation units.
    or
    We can't have more than one definition for free standing variables (variables in a given scope) or functions.
    Classes on the other hand can have multiple defintions in different translatonal units (linked files) but can not have more than one definition in the same translational unit (i.e. the same file).

    Look at one definition rule in relation to:
    - Free standing variables
    - Functions
    - Classes
    - Class member functions
    - Class static member variables
    */

   //One definition rule in context of variables:
   std::cout << weight << std::endl;
   double result = add(10,20);
   std::cout << result << std::endl;

   Point p1;
   std::cout << "p1.x: " << p1.m_x << ", p1.y: " << p1.m_y << std::endl;  

   return 0;
}

double add(double a, double b){ //function defintion (only definition)
    return a+b;
}
/*
double add(double a, double b){ //function defintion(second definition)
    return a+b;
}
*/ //compiler error as we are violating the one defintion rule
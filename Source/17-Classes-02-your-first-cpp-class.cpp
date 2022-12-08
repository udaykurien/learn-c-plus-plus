#include <iostream>

const double PI {3.145};

// Defining Cylinder Class with public members
class Cylinder {
    public:
        double volume() {
            return PI * base_radius * base_radius * height;
        } 
    public: //Unnecessary (as public keyword used above). Repeated just for visual consistency
        double base_radius {1.0};
        double height {1.0};
};

// Defining Cylinder Class with private members
class Cylinder2 {
    public:
        double volume() {
            return PI * base_radius * base_radius * height;
        } 
    private:
        double base_radius {1.0};
        double height {1.0};
};

int main () {

    /*
    Your first cpp class (20:16:34):
    eg. Make a class/blueprint (eg. Person) for objects (eg. People).
    
    - In this lesson we will make a class that represents cylinders.
    - A cylinder has 2 defining aspects, its height (h) and its radius (r).
    - The class for cylinder must contain these 2 features.
    - The class should also provide a way to calculate the area of the cylinder. (A = pi.r.r.h)

    // Explanation of some syntax
    // --------------------------
    class <class_name> {
        <member accessibility>
            <member variables to represent class properties>
        <member accessibility>
            <behaviour/functions that operate on/with properties>
    };
    
    
    class Cylinder {            // Class name 
    public:                     // Member accessibility 
        double radius {1.0};    // Class property/Member variable with initialization
        double height {1.0};    // Class property/Member variable with initialization
    public:                                     // Member accessibility
        double volume() {                       // Behaviour/function
            return 3.14*radius*radius*height;   // Function definition
        } 
    };

    <member accessibility> - public : member variables/functions directly 
                                      accessible to code outside class.
                             private : member variables/functions inaccessible to  
                                       code outside class.
    
    By default, members of a class are private. To make members accessible/usable outside the class definition the have to be preceeded by the public keyword.
    
    Generally, its is bad practice to have public member variables. To prevent accidental changes to them make sure that they are private. If you need to modify member variables, do it through class functions instead of direct access.
    */

    // Creating cylinder object with Cylinder class (member variables are public)
    Cylinder c1;

    // Properties of object c1
    std::cout << "Properties of cylinder object c1: " << std::endl;
    std::cout << "c1 height: " << c1.height << std::endl;
    std::cout << "c1.base_radius: "  << c1.base_radius << std::endl;
    std::cout << "c1.volume():" << c1.volume() << std::endl;
    std::cout << std::endl;

    // Creating another cylinder object
    Cylinder c2;
    
    // Changeing the attributes of c2 from its default r=1, h=1
    c2.base_radius = 3.0; //Dot notation
    c2.height = 2;

    // Properties of object c2
    std::cout << "Properties of cylinder object c2: " << std::endl;
    std::cout << "c2 height: " << c2.height << std::endl;
    std::cout << "c2.base_radius: "  << c2.base_radius << std::endl;
    std::cout << "c2.volume():" << c2.volume() << std::endl;
    std::cout << std::endl;

    // Creating cylinder object with class Cylinder2 (member variables are private)
    Cylinder2 c3;
    /*
    std::cout << "c3.base_radius: "  << c3.base_radius << std::endl;
    c3.height = 2;
    */ // error as member variables are private in class Cylinder2

    return 0;

}

/*
Summary:
- Class member variables can either be raw stack variables or pointers.
- Members can't be references. (because references can never be uninitialized - review previous lesson in references)
- Classes have functions (methods) that let them do things.
- Class methods have access to member variables, regardless of whether they are public or private.
- Private members of classes (variables and functions) aren't accessible from the outside of the calss definition.
*/

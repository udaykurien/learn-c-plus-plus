#include <iostream>

const double PI = 3.14;

class Cylinder {
    private:
        // Member variables
        double radius {1}; // Initialzing stops default/empty constructor from assigning junk value to member variable.
        double height; // Un-initialized. Default/empty constructor will cause height to have a junk value.
    public:
        // Constructors
        Cylinder() = default;
        Cylinder(double radius_param, double height_param){
            radius = radius_param;
            height = height_param;
        }
        // Getters
        double get_radius(){
            return radius; // pass by value, returning a copy
        }
        double get_height(){
            return height;
        }
        // Setters
        void set_radius(double radius_param){ // pass by value, creating a copy
            radius = radius_param;
        }
        void set_height(double height_param){
            height = height_param;
        }
        // Other methods
        double volume(){
            return PI * radius * radius * height;
        }
};

int main () {

    /*
    Setters and getters (20:59:43):
    - When member variables are private, they can't be directly accessed outside the class.
    - To overcome this limitation, we use getters and setters to read and modify member variables.
    - Getters and setters (like constructors) must reside in the public scope of a class, so that they can be accessed externally.
    - The benifit of using getters and setters (as opposed to direct access of member variables within a public scope) is that they restrict the ways in which the member variables can be accessed and modified. This limits accidental changes (associated with direct access) to the member variables. Consequently, this protects the program from faulty behaviour caused by unintentional modifications to member variables.
    */

   Cylinder c1{2,3};

   // Get member variables:
   std::cout << std::endl;
   std::cout << "Read member variables with get_radius(): " << std::endl;
   std::cout << "c1.get_radius(): " << c1.get_radius() << std::endl;
   std::cout << "c1.get_height(): " << c1.get_height() << std::endl;
   std::cout << "c1.volume(): " << c1.volume() << std::endl;
   // std::cout << "c1.radius: " << c1.radius << std::endl; // Compiler error - radius is private

   // Modify member variables
   std::cout << std::endl;
   std::cout << "Set member variables with set_radius(): " << std::endl;
   c1.set_height(5.7);
   c1.set_radius(9.2);
   // c1.radius = 5.7; // Compiler error - radius is private
   std::cout << "c1.get_radius(): " << c1.get_radius() << std::endl;
   std::cout << "c1.get_height(): " << c1.get_height() << std::endl;
   std::cout << "c1.volume(): " << c1.volume() << std::endl;

   // Default constructor and junk values
   std::cout << std::endl;
   std::cout << "Default constructor and junk values: " << std::endl;
   Cylinder c2; // or Cylinder c2{};
   std::cout << "c2.get_radius(): " << c2.get_radius() << std::endl;
   std::cout << "c2.get_height()): " << c2.get_height() << std::endl;
   std::cout << "c2.volume()): " << c2.volume() << std::endl;


    return 0;

}

#include <iostream>
#include<string>

// Members of 'class' are private by default.
class Dog{
    std::string m_name{"None"};
};

// Members of struct are public by default.
struct Cat{
    std::string m_name;
};

// Granular access control
class Dog2 {
    public:
        std::string m_name {"None"};
};

class Cat2{
    public:
        Cat2();
        Cat2(const std::string& name_param){
            m_name = name_param;
        }
    private:
        std::string m_name {"None"};
};

// Example application of structures
struct Point{
    // All member public by default
    double m_x, m_y;
};

void print_point (Point pt_param){
    std::cout << "x-coordinate: " << pt_param.m_x << std::endl;
    std::cout << "y-coordinate: " << pt_param.m_y << std::endl;
}

int main () {

    /*
    Struct (22:33:33):
    - Another keyword we can use to create classes in C++ programs.
    - Unlike 'class' (whose members are private by default), 'struct' members are public by default.
    - Granular access control is done with the 'public' and 'private' keywords, as we've seen before.
    - Q) When do we use strcut?
        1. When we want classes that contain only public members. (eg struct point, which gives us direct control of the x and y coordinates)
    */

   // Examples with default access parameters
   Dog woofy1; // Class object with default access properties
   //woofy1.m_name = "Ruff"; //error as member variable private by default
   //std::cout <<  woofy1.m_name << std::endl;

   Cat meowy1; // Struct object with default access properties
   meowy1.m_name = "Socks"; // runs, as member variable public by default
   std::cout << meowy1.m_name << std::endl;

   
   
   // Examples with modified access paramters
   Dog2 woofy2; // Class object with modified access properties
   woofy2.m_name = "Fluffy"; //runs as member variable made public
   std::cout <<  woofy2.m_name << std::endl;

   Cat2 meowy2{"Mittens"}; // Struct object with modified access properties
   //meowy2.m_name = "Mittens"; // error, as member variable made private
   //std::cout << meowy2.m_name << std::endl;
   

   // Use case for structs
   Point p1;
   p1.m_x=5.2;
   p1.m_y=10.5;
   print_point(p1);
   
   --p1.m_x;
   ++p1.m_y;
   print_point(p1);

    return 0;
}

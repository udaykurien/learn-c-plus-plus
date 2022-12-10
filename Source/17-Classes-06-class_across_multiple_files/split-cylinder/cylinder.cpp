#include "cylinder_headers_only.h"

/*
Implementation of functions contained in cylinder class
Syntax:
function_return_type class_name::class_function_name (parameter_list) {
    <class_function_definition>
}

Note:
:: -> scope resolution operator.
Use:
double Cylinder::get_radius(){
    return radius; 
}
Cylinder::get_radius -> Tells the compiler that the function get_radius lives in the scope of the Cylinder class.

Warning:
Make sure a function isn't double defined. - The same function can not be simultaneously defined in both the header (.h) and function definition (.cpp) files. The compiler won't know which one to select causing an error. Make sure each function is defined in only one place.
*/

Cylinder::Cylinder(double radius_param, double height_param){
    radius = radius_param;
    height = height_param;
}

double Cylinder::get_radius(){
    return radius; 
}

double Cylinder::get_height(){
    return height;
}

double Cylinder::volume(){
    return PI * radius * radius * height;
}

void Cylinder::set_radius(double radius_param){
    radius = radius_param;
}

void Cylinder::set_height(double height_param){
    height = height_param;
}
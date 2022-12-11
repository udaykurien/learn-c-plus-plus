#include "cylinder_headers.h"

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
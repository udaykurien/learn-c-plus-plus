#ifndef CYLINDER_H
#define CYLINDER_H

#include "constants.h" 

class Cylinder {
    private:
        double radius;
        double height;
    public:
        // Constructors
        Cylinder() = default;
        Cylinder(double radius_param, double height_param);
        // Getters
        double get_radius();
        double get_height();
        // Setters
        void set_radius(double radius_param);
        void set_height(double height_param);
        //Other functions
        double volume();
};

#endif
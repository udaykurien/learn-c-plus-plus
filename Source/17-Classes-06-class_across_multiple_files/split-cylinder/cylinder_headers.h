#ifndef CYLINDER_H //include guard
#define CYLINDER_H

// #include "constants.h" // Include this here or in main.cpp, but don't double include it (without an include guard) as that will cause a compiler error (re-definition of PI)
// To avoid the redefinition of PI with multiple #include "constants.h" statements, use an include guard in constants.h (see constants.h)

#include "constants.h" //becacuse of include guard in constant.h, this statment can be added to all of the source files without fearing that the preprocesser will include the contents of constants.h more than once in the final source file.

// eg. contents of constant.h will be added to this file
// contents of this file (cylinder.h) will be added to main.cpp
// if main contains another #include "constant.h", the include guard will ensure that the contents of constant.h will not be adeed to main.cpp a second time
// alternatively, if this file (cylinder.h) did NOT contain #include "constants.h", then the include guard would permit main.cpp to add the contents of constants.h to it.

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
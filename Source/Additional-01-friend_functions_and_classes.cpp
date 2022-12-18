#include <iostream>

class ShapeSquare{
    private:
        double length;
        double perimeter;
        double area;
    public:
        ShapeSquare() = default;    // default constructor
        void set_members (double length_param) {    // other function
            length = length_param;
            perimeter = 4*length_param;
            area = length_param*length_param;
        }
    // How can we access the class' private members from the outside?
    // 1. Put them in the public scope.
    // 2. Define getters in the public scope.
    // 3. Use friendship functions (they have access to all private and public members of a class).

    // friendship function declaration occurs within class
    friend void ShapeSquarePrint (ShapeSquare);
};

// friendship function definition (can also be placed after main):
void ShapeSquarePrint(ShapeSquare shp){
    std::cout << "[length,perimeter,area] : [" << shp.length << "," << shp.perimeter << "," << shp.area << "]" << std::endl;
}
    
int main () {

    /*
    Friend functions:

    */
    ShapeSquare square1;
    square1.set_members(3);
    /*
    Compiler error because member variables of ShapeSquare are private:
    std::cout << square1.length << " " << square1.perimeter << " " << square1.area;
    */

   // Calling friend function
   ShapeSquarePrint(square1);

    return 0;

}

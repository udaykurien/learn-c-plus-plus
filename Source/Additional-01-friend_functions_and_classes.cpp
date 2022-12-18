// reference : https://www.youtube.com/watch?v=KXDzBglp83M

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
    // 4. Use friendship class (similar to friendship function).

    // friendship function declaration occurs within class
    friend void ShapeSquarePrint (ShapeSquare);

    // friend class
    friend class AllShapes;
};

// friendship function definition occurs globally (can placed before/after main):
// Because it is a friend function of ShapeSquare, it has access to its private members.
void ShapeSquarePrint(ShapeSquare shp){
    std::cout << "Inside Friend Function ShapeSquarePrint: " << std::endl;
    std::cout << "[length,perimeter,area] : [" << shp.length << "," << shp.perimeter << "," << shp.area << "]" << std::endl;
}

// friend class (has access to all members of ShapeSquare)
class AllShapes{
    public:
        void AllShapesPrint(ShapeSquare sq){
            std::cout << "Inside Function AllShapesPrint Inside Friend Class AllShapes" << std::endl;
            std::cout << "[length,perimeter,area] : [" << sq.length << "," << sq.perimeter << "," << sq.area << "]" << std::endl;
        }
};
    
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

    std::cout << std::endl;

    AllShapes square2; // friend class object
    square2.AllShapesPrint(square1); // call friend class method (AllShapesPrint in AllShapes), via friend class object (square2 object of type AllShapes), but with parent class object (square1 object of type ShapeSquare) as argument. 

    /*
    Note:
    - Friendship is not mutual. Just because AllShapes can access all the members of ShapeSquare, it doesn't mean that ShapeSquare has access to all members of AllShape.
    - Friendship is not inherited. i.e. if a base class has a friend function, that friend function will not, by default, be a friend of classes derived from that base class.
    - Friend functions are often used for operator overloading.
    */

    return 0;

}

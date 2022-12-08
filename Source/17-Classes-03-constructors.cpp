#include <iostream>

const double PI = 3.145;

// Class
class Cylinder1 {
    // Properties
    private:
        double radius {1.0};
        double height {1.0};

    // Behaviours
    public:
        // Constructor method (notice that, unlike other functions/methods, the prototype of a constructor does not contain a return type)
        // This constructor doesn't use parameters. The terminology for this is DEFAULT CONSTRUCTOR.
        Cylinder1(){
            radius = 2.0;
            height = 2.0;
        };
        
        // Another constructor. This uses parameters. Arguments are passed by value into this constructor.
        Cylinder1(double radius_param, double height_param){
            radius = radius_param;
            height = height_param;
        };

        // From the above 2 constructors, the constructor that the compiler chooses will depend on how the class object is created. If the object is created without radius and height arguments, the first implementation of the constructor (ie. no parameters) is used. If the object is created with arguments the second implementattion of the constructor (i.e. the implementation with parameters) is used. CONSTRUCTOR OVERLOADING(?)

        // Constructors must be in public scope or compiler will fail to build object.
        
        // Normal class function/method with return type defined in prototype
        double volume(){
            return PI * radius * radius * height;
        }

        // If you don't explicitly specify constructors, the compiler will add its own default constructor which is empty. This is called an empty constructor. The compiler generated constructor will look exactly like the following:
        /*
        Cylinder() {

        }
        */
       // Manually adding this code your class, replicates exactly what the compiler would do in absence of developer defined constructors.
       // The properties of an empty constructor are:
       // 1. No parameters
       // 2. No definition
       // 3. Just a name and brackets
       // Note: this constructor doesnt do anything

};

/*
 Class defintion without comments for readability:

 class Cylinder1 {
    private:
        double radius {1.0};
        double height {1.0};
    public:
        Cylinder1(){
            radius = 2.0;
            height = 2.0;
        };
        Cylinder1(double radius_param, double height_param){
            radius = radius_param;
            height = height_param;
        };
        double volume(){
            return PI * radius * radius * height;
        }
    };

        
*/

int main () {

    /*
    Constructors (20:38:03):
    Constructors are a special kind of class function/method that is called when an instance of a class is created. It has the following characteristics:
    - No return type.
    - Same name as the class.
    - Can have parameters. Can also have an empty parameter list.
    - Usually used to initialize member variables of a class.
    */

   Cylinder1 c1; //object declared without arguments will use the default constructor. In this case the default constructor specifies the values of the member properties (heigh and radius).
   std::cout << "Volume of <Cylinder1 c1;> =  " << c1.volume() << std::endl;

   Cylinder1 c2(5.2,7); // object declared with arguments will use the matching constructor. In this case the values of the member properties (radius and height) are provided by the user in main (5.2,7).
   std::cout << "Volume of <Cylinder1 c2(5.2,7);> = " << c2.volume() << std::endl;


    return 0;

}

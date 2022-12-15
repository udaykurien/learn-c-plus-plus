#include <iostream>
#include <string>

class wrapper{
    public:
        void do_something(){
        }

        void print_info(){
            std::cout << "var1: " << m_var1 << std::endl;
            std::cout << "var2: " << m_var2 << std::endl;
            std::cout << "name: " << m_name << std::endl;
        }
    private:
        int m_var1{}; // 4 bytes
        int m_var2{}; // 4 bytes
        std::string m_name {"Lorem ipsum dolor sit amet"};
        // Internal representation of string  is a class which stores its data as const char pointers -> It counts the size of the pointer, but that is not ncessrily the size of the object the pointer is referrring to.
};

class Dog{
    public:
        Dog() =  default; // Doesnt impact object size (as its a function)
        void print_legs(){ // Doesnt impact object size (as its a function)
            std::cout << leg_count << std::endl;
        }
    private:
        size_t leg_count; // 8 bytes
        size_t arm_count; // 8 bytes
        int* p_age; // pointer to int - 8 bytes
        std::string name1; //std::string -> class that stores string as a const char pointer
        std::string name2{"Hello World. My length doesnt effect my size as I am just a pointer.!!!"};
};

int main () {

    /*
    Size of class objects (22:42:38):

    By C++ standards:
    Size of class = sum of size of all member variables
    (other code/functions is not included in size calculation)

    Why are functions not included in size calculations?
    - Functions are associated with the class itself, rather than with each object individually.

    Sometimes the size of the class may not be exactly equal to the sum of its member variables. Why is this?
    - This is because of the phoenomenon of boundary alignment.
    Boundary alignment is consequence of compiler actions when it encounters member variables of different types.
        - Member variables that are 4 bytes in size are stored in memory addresses that are multiples of 4.
        - This may cause gaps in memory (unused memory) if we have member variables that are of different types (eg. a collection of member variables that are either 2 or 4 bytes). (This happens because the member variables of size 4 bytes must be aligned with memory locations that are multiples of 4)
        - The gaps in memory cause the object to have a larger size than what we would expect from just the summation of the member variables sizes.

        Memory Loc  1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
        Variable    b   b   *   a   a   a   a   b   b   *   *   a   a   a  a

        Varable and size: a-4 bytes, b-2 bytes, *-unused
        Total size of member variables - 12 bytes
        Total unused spaces - 3 bytes (due to memory alignment)
        Total size of object - 15 bytes 
    */

    std::cout << "Sizes of common types: " << std::endl;
    std::cout << "sizeof(size_t): " << sizeof(size_t) << std::endl;
    std::cout << "sizeof(int): " << sizeof(int) << std::endl;
    std::cout << "sizeof(int*): " << sizeof(int*) << std::endl;
    std::cout << "sizeof(std::string): " << sizeof(std::string) << std::endl;
    std::cout << std::endl;    

    std::cout << "Size of class objects: " << std::endl;
    Dog woofy1;
    std::cout << "Theoretical size calculation: " << std::endl;
    std::cout << "(size_t) + (size_t) + (int*) + (std::string) + (std::string) = " << sizeof(size_t) + sizeof(size_t) + sizeof(int*) + sizeof(std::string) + sizeof(std::string) << std::endl;

    std::cout << "Actual measured size: " << std::endl;
    std::cout << "sizeof(woofy1): " << sizeof(woofy1) << std::endl;

    return 0;

}

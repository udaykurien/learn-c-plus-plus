#include <iostream>
#include <string_view>

// Class and headers
class Dog{
    public:
        //Constructors
        Dog() = default;
        Dog(std::string_view name_param, std::string_view breed_param, int age_param);
        //Destructors
        ~Dog(); //Destructed MUST contain an empty parameter list
    private:
        std::string name;
        std::string breed;
        int * p_age{nullptr};
};

// Class header defintions
// Constructor
Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param) {
    name = name_param;
    breed = breed_param;
    p_age = new int; // create new int location in heap and assign pointer to it
    *p_age = age_param; // enter value of age_param into memory location referenced by p_age
    std::cout << " > Dog constructor called for dog object - " << name << std::endl;
}
// Destructor
Dog::~Dog(){
    delete p_age;
    std::cout << " > Destructor called for dog object - " << name << std::endl;
}

// Function that uses dog object
// (To illustrate object destruction on function termination)
void some_func(){
    std::cout << "First line of some_func." << std::endl;
    Dog my_dog("Socks", "Huskie",5);
    std::cout << "Last line of some_func." << std::endl;
}

void some_func_2(Dog dog_param){
    std::cout << "First line of some_func_2." << std::endl;
    
    std::cout << "Last line of some_func_2." << std::endl;
}

void some_func_3(){
    std::cout << "First line of some_func_3." << std::endl;
    Dog* p_dog = new Dog("Laika", "unknown", 5); // create new dog object on heap
    //Dog object on heap must be explicitly deleted to prevent memory leaks
    //If its not deleted, the pointer to the heap address will be forever lost when some_func_3 exists, and it will become impossible to find and delte the dog object.
    //Unless we explicitly delete the dog object, the destructor isn't called
    delete p_dog;// deletes heap object and calls for object destructor to be run
    std::cout << "Last line of some_func_3." << std::endl;
}

// Main function
int main() {
    /*
    Notes:
    - Constructor called when we create a dog object.
    - Destructor called just before main function ends.
    - All stack objects destroyed when end of main is reached.
    */
    std::cout << "Creating dog object julie." << std::endl;
    Dog my_dog("Julie", "stray", 14);
    std::cout << "Creating dog object Fluffy." << std::endl;
    Dog your_dog("Fluffy", "Pomerenian", 14);

    std::cout << std::endl;
    std::cout << "Call function (some_func) to create dog object socks." << std::endl;
    some_func();
    std::cout << "After termination of some_func." << std::endl;

    std::cout << std::endl;
    std::cout << "Call function (some_func_2) with dog object Fluffy" << std::endl;
    some_func_2(your_dog); //becareful. pass by value causes the memory adress of pointer p_age to be copied, instead of the value referenced by p_age. This can cause errors.
    // Also note, we now have 2 dog objects. One in main() and one in some_func_2(). Both these dog objects point to the same thing. When some_func_2 is exited, the destructor is called. When main exits, the destructor is again called on the same object. But since that object was already destroyed when some_func_2 exited, there will be no object left to destroy and we'll have errors. (Remember don't delete pointers twice)
    std::cout << "After termination of some_func_2." << std::endl;

    std::cout << std::endl;
    std::cout << "Calling some_func_3: " << std::endl;
    some_func_3();
    std::cout << "After termination of some_func_3." << std::endl;

    std::cout << std::endl;
    std::cout << "Penultimate line in termination of main. Destructor will automatically be called just after this line." << std::endl;
    return 0;
}

/*
Final thoughts:
- A destructor is a special method that is called when an object dies.
- It is called when the scope of a function, in which the object exists, is terminated.
- It is called when the pointer to an object declared in the heap is explicitly deleted using the delete keyword.
- It is also called when an object is passed by value to a function
- And when a local object is returned from a function (for some compilers)

*/

/*
 OUTPUT:
 Creating dog object julie.
 > Dog constructor called for dog object - Julie
Creating dog object Fluffy.
 > Dog constructor called for dog object - Fluffy

Call function (some_func) to create dog object socks.
First line of some_func.
 > Dog constructor called for dog object - Socks
Last line of some_func.
 > Destructor called for dog object - Socks
After termination of some_func.

Call function (some_func_2) with dog object Fluffy
First line of some_func_2.
Last line of some_func_2.
 > Destructor called for dog object - Fluffy
After termination of some_func_2.

Calling some_func_3: 
First line of some_func_3.
 > Dog constructor called for dog object - Laika
 > Destructor called for dog object - Laika
Last line of some_func_3.
After termination of some_func_3.

Penultimate line in termination of main. Destructor will automatically be called just after this line.
free(): double free detected in tcache 2
[1]    96830 IOT instruction (core dumped)  ./destructors_full_lesson.o

*/
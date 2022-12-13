#include <iostream>
#include <string_view>

// Class and headers
class Dog{
    public:
        //Constructors
        Dog() = default;
        Dog(std::string_view name_param, std::string_view breed_param, int age_param);
        //Destructors
        ~Dog();
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
    p_age = new int; //
    *p_age = age_param; 
    std::cout << " > Constructor called for dog object - " << name << std::endl;
}
// Destructor
Dog::~Dog(){
    delete p_age;
    std::cout << " > Destructor called for dog object - " << name << std::endl;
}
int main () {

    /*
    Class constructor and destructor call order (22:07:47):
    Lets have a look at the call order of constructors and destructors.
    - Suppose we make 3 objects: obj1, obj2 and obj3.
    - The consructors are called in sequence of creationg of each object
      ie. obj1.constructor(), obj2.constructor(), obj3.constructor()
    - When we are exiting the scope, or the pogram, then the object destructors are called
    - But the object destructors are called in the reverse order of the object constructors i.e. the last object to be constructed is the first object to be destroyed. The reason for this lies in C++'s compiler's behaviour. (The chances that other object are dependent on previous objects are lower for objects created later, than earlier. Objects created first, are used by the program for a longer time and thus theres a higher chance that it is dependencies of something else. Removing these objects before objects that were created later can lead to errors (?) : Re watch- 22:09:55 onwards
    */

    std::cout << "Class objects destroyed in reverse order of creation: " << std::endl;
    Dog obj1 {"Doggy1", "Huskie", 5};
    Dog obj2 {"Doggy2", "Huskie", 3};
    Dog obj3 {"Doggy3", "Huskie", 2};
    Dog obj4 {"Doggy4", "Huskie", 7};

    return 0;

}

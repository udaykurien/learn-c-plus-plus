#include<string>

class Dog {
    public:
        Dog(); // default constructor
        Dog(std::string name_param, std::string breed_param, int age_param); // constructor
        ~Dog(); // Destructor declared. Destructor can also be defined here

    private:
        std::string dog_name;
        std::string dog_breed;
        int dog_age;
};
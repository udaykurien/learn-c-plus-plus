#include "dog.h"

Dog::Dog(){
    dog_name = "None";
    dog_breed = "None";
    int *dog_age = new int;
    *dog_age =0;
}

Dog::Dog(std::string name_param, std::string breed_param, int age_param){
    dog_name = name_param;
    dog_breed = breed_param;
    int *dog_age = new int;
    *dog_age = age_param;
}

Dog::~Dog(){
    delete dog_age;
    std_cout << "Dog destrctor alled for " << dog_name << std::endl; 
}
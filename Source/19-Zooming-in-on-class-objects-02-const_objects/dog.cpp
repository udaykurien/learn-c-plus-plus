#include "dog.h"

// Setters
Dog::Dog(std::string_view name_param, std::string_view breed_param, unsigned int age_param){
    m_name = name_param;
    this->m_breed = breed_param;
    (*this).m_age = age_param;
}

// Getters
std::string_view Dog::get_name(){
    return m_name;
}
std::string_view Dog::get_breed(){
    return m_breed;
}
unsigned int Dog::get_age(){
    return m_age;
}

// Setters
void Dog::set_name(std::string_view name_param){
    m_name = name_param;
}
void Dog::set_breed(std::string_view breed_param){
    m_breed = breed_param;
}
void Dog::set_age(unsigned int age_param){
    m_age = age_param;
}

// Utility functions
void Dog::print_info(){
    std::cout << "Dog Info at Memory Address (" << this << "):" << std::endl;
    std::cout << "[ name : " << this->m_name << ", breed : " << this->m_breed
    << ", age : " << this->m_age <<" ]" << std::endl;
}


#include <iostream>
#include <string>
#include <string_view>

class Person; // Forward declaration of parent class
class Player; // Forward declaration of inheritted class



// Class Declarations/Headers
// --------------------------
// Parent class - Person
class Person
{
    // String output operator
    friend std::ostream& operator << (std::ostream& out, const Person& person);
    public:
        Person();
        Person(std::string& first_name_param, std::string& last_name_param);
        // ~Person();
        // Getters
        std::string get_first_name();
        std::string get_last_name();
    private:
        std::string first_name{"Mysterious"};
        std::string last_name{"Person"};
};

// Inherited class - Player
class Player : public Person {  //Publicaly derive from the person class
    // Because Player is publically derived fromm Person, we can not directly access first_name, last_name (from Person) in Player. This will cause a compiler error.
    // We can only access Person's public members directly from Player.
    friend std::ostream& operator<<(std::ostream& out, Player& player);
    public:
        Player() = default;
        Player(std::string_view game_param);
        // ~Player();
    private:
    std::string m_game{"None"};
};

// Class Definitions
// -----------------
// Person Class Definitions
Person::Person(){
}

Person::Person(std::string& first_name_param, std::string& last_name_param){
    first_name = first_name_param;
    last_name = last_name_param;
}

std::ostream& operator << (std::ostream& out, const Person& person){
    out << "Person[" << person.first_name << " " << person.last_name << "]";
    return out;
}

std::string Person::get_first_name(){
    return first_name;
}

std::string Person::get_last_name(){
    return last_name;
}

// Player Class Definitions
Player::Player(std::string_view game_param){
    m_game = game_param;
}

std::ostream& operator << (std::ostream& out, Player& player){
    out << "Player : [ game : " << player.m_game 
    << " names : " << player.get_first_name() << " " 
    << player.get_last_name() << "]";

    return out;
}


int main () {

    /*
    Your first try on inheritance (22:56:02):
    Reminder of inheritance:
                    Class person               |
                     ___|___                   | INHERITANCE TREE
                 ___/       \___               | (from Person to Engineer & Doctor)
             ___/               \___           |
            /                       \         \|/
        Class Engineer          Class Doctor   '

    Classes Engineer and Doctor are new classes, but they inherit the methods and member variables of the Parent Class Person.

    Assignment for this lectures:
    1. Set up a base/parent class - Person, containing last_name, first_name.
    2. Set up an inherited class - Player, that inherits from Person, but also adds member variable m_game.

    Parent Class          Inherited Class
    [PERSON]       ->     [PLAYER]
    --------              --------
    <last_name>           [PERSON]
    <first_name>          <m_game>

    Notes:
    - With public inheritance, derived classes can access and use public members of the base class, but the derived class can't directly access private members.
    - The same also applies to friends of the derived class. They hae access to private members of derived class, but don't have access to the base class.
    
    */
   Player p1("baskeball");
   std::cout << p1.get_first_name() << " " 
   << p1.get_last_name() << std::endl;

   std::cout << std::endl;

   std::cout << "p1: " << p1 << std::endl;

//    std::cout << "player: " << p1 << std::endl;

    return 0;

}

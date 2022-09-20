#include <iostream> //for io
#include <string> //for string

int main()
{
    int num1;
    int age;
    std::string name; 
    std::string full_name;
    
   
    std::cout<<"Enter a number: "<<std::endl; // Output to console
    
    std::cin>>num1; // Input from user
   
   
    std::cout<<"The number you entered is: "<<num1<<std::endl;     // Output to console
    std::cerr <<"Something went wrong!\n"; // Send error to console
    std::clog <<"This is a log message.\n"; // Send log to console
    

    // Chaining input and output
    std::cout<<"Enter age and name (space or enter separated): "<<std::endl;
    std::cin >> age >> name; // Space separated first and last name causes error
    std::cout << "Hi, " << name << ". You are " << age << " years old." << std::endl;


    std::cout<<"Enter full name:\n";
    std::cin.ignore(); // flush input stream so that white spaces are cleared
    std::getline(std::cin,full_name);
    std::cout<<"Your full name is: "<<full_name<<std::endl;
}
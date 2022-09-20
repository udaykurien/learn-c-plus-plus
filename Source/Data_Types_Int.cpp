#include <iostream>

int main()
{
    // TYPE int
    // -----------------------------------------------------
    /*
    1 byte = 8 bits
    Int: 4 bytes, stores whole number
    max(Unisgned int) = 2^(4*8) = 2^32
    max(signed int) = 2^(32-1) =2^31 {1 bit used to represent sign }
    */

    int elephant_count; // Declare variable of type int 
    std::cout<<"elephant_count: "<<elephant_count<<std::endl;
    // Declaration without initialization will retain garbage value in memory location

    int baby_elephant_count {}; //Initialize variable to 0
    std::cout<<"baby_elephant_count: " <<baby_elephant_count<<std::endl;

    // Different ways of initialization
    int dog_count {10}; // Initialize variable to 10 (curly braces: braced initialization)
    std::cout<<"dog_count: "<<dog_count <<std::endl;
    int cat_count = 15; // Initialize variable to 15 (equal to sign: assignment initialization)
    std::cout<<"cat_count: "<<cat_count <<std::endl;
    int snake_count(15); //Initialize snake count to 15 (parantheses : functional initialization)
    std::cout<<"snake_count: "<<snake_count <<std::endl;
    int domesticated_animats {dog_count + cat_count}; // Initialize variable via expression
    std::cout<<"domesticated_animas: "<<domesticated_animats <<std::endl;

    // int lossy_init {2.9}; -> warning or error
    int truncation_init (2.9); // Truncates fractional part
    std::cout<<"truncation_init: "<<truncation_init <<std::endl;
    int truncation_init_2 = 2.9; // Truncates fractional part
    std::cout<<"truncation_init_2: "<<truncation_init_2 <<std::endl;

    // QUERY FUNCTION sizeof
    // ------------------------------------------------------
    int size_snake_count = sizeof(snake_count); // returns size (not value) of variable
    std::cout << "Size of snake_count: "<< size_snake_count<< " bytes" << std::endl;
    std::cout << "Size of int: " << sizeof(int) << " bytes." << std::endl;

    // Positive and Negative integers
    // ------------------------------------------------------
    int value1 {10};
    std::cout << "value1: " << value1 << std::endl;
    int value2 {-300};
    std::cout << "value2: " << value2 << std::endl;
    

    // Modifiers for integer (int) types
    // ------------------------------------------------------
    // signed, unsigned -> modifies int to indicate only positive (unsigned) or both posive and negative (signed)numbers
    unsigned int value1_unsigned {20};
    std::cout << "value1_unsigned: " << value1_unsigned << std::endl;
    signed int value1_signed {-200};
    std::cout << "value1_signed: " << value1_signed << std::endl;
    signed int value2_signed {200};
    std::cout << "value2_signed: " << value2_signed << std::endl;
    // short int -> 2 bytes
    // long int -> 4 or 8 byes
    // long long int -> 8 bytes
    unsigned long long int unsigned_long_long_int {1234};
    signed short int signed_short_int {-1234};
    short int short_int {1234};
    long long_var {1234};
    short short_var {1234};
    long long long_long {888};
    std::cout << sizeof(unsigned long long int) << std::endl;
    std::cout << sizeof(unsigned long long) << std::endl;


    return 0;
}
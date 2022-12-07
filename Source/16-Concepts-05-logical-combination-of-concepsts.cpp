#include <iostream>
#include <concepts>
#include <string>

// 'Nested Concept' (studied in previous lesson)
//----------------------------------------------
template <typename T>
concept TinyType = requires(T t) {
    sizeof(T) <= 4;
    requires sizeof(T) <= 4;
};

// 'Function Template' with logical combination of concepts 
//----------------------------------------------------------
template <typename T>
//T func(T t) requires std::integral<T> || std::floating_point<T>
//T func(T t) requires std::integral<T> && TinyType<T> // ( NOTE: this statement does same thing as next line)
T func01(T t) requires std::integral<T> && requires(T t) {
                                                        sizeof(T) <= 4;
                                                        requires sizeof(T) <= 4;
                                                        } //Same as prev, but uses TinyTYpe definition instead of keyword
{ // Function template defintion
    std::cout << "value: " << t << std::endl;
    return (2*t);
}

// Clearly formatted examples of function templates with logical combinations
// ---------------------------------------------------------------------------
/*
(1) The template paramater is an interal or type
------------------------------------------------
template <typename T>
T func(T t) requires std::integral<T> || std::floating_point<T>
{
    std::cout << "value: " << t << std::endl;
    return (2*t);
}

(2) The template paramater is an integral and TinyType type
-------------------------------------------------------------
template <typename T>
T func03(T t) requires std::integral<T> && TinyType<T>
{
    std::cout << "value: " << t << std::endl;
    return (2*t);
}

(3) The template paramater is an integral and TinyType type
------------------------------------------------------------
template <typename T>
T func01(T t) requires std::integral<T> && requires(T t) {
                                                        sizeof(T) <= 4;
                                                        requires sizeof(T) <= 4;
                                                        } 
{ 
    std::cout << "value: " << t << std::endl;
    return (2*t);
}

-------------------------------------------------------------
Note: (2) and (3) are express the same thing as long as the concept of TinyType is defined as follows:

template <typename T>
concept TinyType = requires(T t) {
    sizeof(T) <= 4;
    requires sizeof(T) <= 4;
};

In (3), the concept is specified in-place instead of explicitly as in the case of (2).
*/

// Practical examples of function templates using logical combinations
// --------------------------------------------------------------------
// (1)
template <typename T>
requires std::integral<T> || std::floating_point<T>
// Argument only accepted if its int or float
T add01 (T a, T b) {
    return a+b;
}

//(2)
template <typename T>
requires std::integral<T> && TinyType<T> //Args must be BOTH int and TinyType
T add02 (T a, T b) {
    return a+b;
}

//(3)
template <typename T>
requires std::integral<T> && requires(T t) {
    sizeof(T) <= 4;
    requires sizeof(T) <= 4;
}
T add03 (T a, T b) { 
    return a+b;
} // Same as (2), but tinytype defined in place

// Main
//-------
int main () {

    /*
    Logical combination of concepts (19:59:55):
    Concepts can be combined using the and (&&) and or (||) operators
    */

    int x_int_1{3},y_int_1{4};
    long int x_lng_1{5}, y_lng_1{7};
    double x_dbl_1{7.2}, y_dbl_1{5.6};
    std::string x_str_1 {"Hello"}, y_str_1 {"World"};
    
    //add01 - template <typename T> requires std::integral<T> || std::floating_point<T>
    //------------------------------------------------------------
    auto result1 = add01(x_int_1, y_int_1); // Passes because both parameters are int or float
    auto result2 = add01(x_dbl_1, y_dbl_1); // Passes because both parameters are int or float
    // auto result3 = add01(x_int_1,y_dbl_1); // Fails because in function template both parameters must be of only one type - int or float
    // auto result4 = add01(x_str_1, y_str_1) // Fails because parameters in function template must either be int or float. String isn't accepted

    //add02 -template <typename T> requires std::integral<T> && TinyType<T>
    //----------------------------------------------------------------------
    auto result5 = add02(x_int_1, y_int_1); // Passes because both parameters are int, and int = 4 bytes
    // auto result6 = add02(x_lng_1, y_lng_1); // Fails because both parameters are long int, and long int = 8 bytes. This violates TinyType concept/requirement.

    // std::cout << func03(x_int_1) << std::endl;

    return 0;

}

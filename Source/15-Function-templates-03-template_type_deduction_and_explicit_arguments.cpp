#include <iostream>
#include <string>

template <typename T> T maximum(T a, T b);

int main () {

    /*
    Template type deduction and explicit arguments (18:19:57):
    
    Template type deduction:
    The mechanism by which the compiler deduces the parameter and return types of the actual function that is built from the abstract template.
    */

    int a{10}, b{23};
    double c{34.7}, d{23.4};
    std::string e{"hello"}, f{"world"};

    auto max1 = maximum(a,b); //int type deduced. All T placeholders will be assigned type int, and a function instance (int maximum(int a, int b);) will be created.
    auto max2 = maximum(c,d); //double type deduced, and corresponding function instance is created. (double maximum(double c, double d);)
    auto max3 = maximum(e,f); //string type deduced, and corresponding function instance is created. (std::string maximum (std::string a, std::string b))

    // Automatic template type deductions are problematic when it comes to handling arguments of different types. To overcome this we can manually specify the type 'T' as shown below.
    
    auto max4 = maximum<double>(c,d);
    /* 
    Explicitly say that we want to call double instance of the function.
    (or forces the compiler to set the template argument type to double)
    If an instance isn't already there it will be created.
    double maximum(double e, double f);
    */

    auto max5 = maximum<double>(a,c);
    /*
    Works even is parameters are of different types.
    There is an implicit conversiono from int to double for 'a'.
    double maximum(double a, double c);
    */

    // maximum<double>(a,e);
    /*
    Error: can't convert std::string to double.
    */


    return 0;

}

template <typename T>
T maximum(T a, T b) {
    return (a > b)? a:b;
}

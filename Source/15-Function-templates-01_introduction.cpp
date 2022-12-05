#include <iostream>

int main () {

    /*
    Function templates (17:40:11):
    These are a mechnaism that we have to set up blue prints for functions and to have a point of control to generate the function. The compiler will handle generation of the function, when it encounters the function call.

    This is inteded to help/streamline function overloads.

    Consider the following function overloads:
    -----------------------------------------------------------------
    (1)
    int max(int a, int b) {
        return (a>b)? a:b;
    }

    (2)
    double max (double a, double b) {
        return (a>b)?a:b;
    }

    (3)
    std::string_view max(std::string_view a, std::string_view b) {
        return (a>b)? a:b;
    }
    ----------------------------------------------------------------------
    Each of these functions have different signatures, but are essentially performing the same task (returning the larger of 2 inputs). -> the body of all these functions are essentially the same, resulting in a lot of coding redundancy.

    To avoid this redundancy in written source code we use function templates.

    Syntax for function blueprint:
    --------------------------------
    template <typename T>
    T maximum(T a, T b) {
        return (a>b) ? a:b;
    }
    --------------------------------
    The compiler will use this blueprint to generate an actual function when it encounters a function call.
    */

    return 0;

}

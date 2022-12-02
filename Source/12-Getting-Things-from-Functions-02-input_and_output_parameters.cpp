#include <iostream>
#include <string>

/*
- In each of the following void functions, the third parameter is a modifiable reference.
- The idea over here is to set up the functions in a way such that changes made inside a function are visible/persist outside the function, even when a return statement is not used.
- One way to do this is to set up the function parameters as references to the arguments. By doing this we directly modify the contents of the memory locations of the arguments within the function (as opposed to creating copies of the arguments as we've seen in the case of pass by value).
- We can also achieve this with the use of pointers. (eg. The third void function written below)
*/

void max_str(const std::string& input1, const std::string input2, std::string& output){
    // The input parameters have the const modifier attached to them just as a security step so that we don't accidentally change them. If we need to change input1 and input2, then we can remove the const.
    if (input1 > input2) {
        output = input1;
    } else {
        output = input2;
    }
}

void max_int(int input1, int input2, int& output) {
    // The inputs are not references here. They are copies. Because we are dealing with small and fundamental variables (eg. int, double etc), the process of making copies of them is inexpensive. If we were dealing with large arrays, where the cost of making copies is higher, then its preferable to use references or pointers to avoid the cost of copyinig.
    if (input1 > input2){
        output = input1;
    } else {
        output = input2;
    }
}

void max_double(double input1, double input2, double* output) {
    //This function uses pointers instead of references to directly manipulate output.
    if (input1>input2) {
        *output = input1;
    } else {
        *output = input2;
    }
}

int main() {
    /*
    Input and Output parameters (16:04:02):
    - Output parameters should be passed in such a way that you can modify the arguments from inside the function. Options are passing by reference or by pointer. References are preferred in C++.

    - Input parameters shouldn't be modifiable from inside a function. The function only needs to get input (read) from the arguments. You enforce modification restrictions with the const keyword. The options we have to do this are : by passing by const reference, by passing pointer to const, or ever by passing const pointer to const.
    */

   std::string out_str, string1{"Alabama"}, string2{"Bellevue"};
   max_str(string1,string2,out_str);
   std::cout << "max_str: " << out_str << std::endl;

   int out_int, in1{45}, in2{23};
   max_int(in1, in2, out_int);
   std::cout << "max_int: " << out_int << std::endl;

   double out_dbl, dbl_in1 {17.9}, dbl_in2 {27.95};
   max_double(dbl_in1,dbl_in2,&out_dbl);
   std::cout << "max_double: " << out_dbl << std::endl;

   return 0;
}
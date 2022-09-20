#include <iostream>

int main() {
    /*
    Declaration:
    <type> <array_name>[<number of elements>];
    eg. int scores[10];
    - Arrays are 0 indexed
    */

   // Declaration of array
   int scores[10];
   std::cout << "Size of array: " << sizeof(scores)/sizeof(int) <<std::endl; // Calculating the number of elements in the array

   // Reading array elements
   std::cout << "The 1st element of the array (scores[0]) is: " << scores[0] << std::endl; // Will print garbage value because the array hasn't been initialized
   std::cout << "The 10th element of the array (scores[9]) is: " << scores[9] << std::endl; // Will print garbage value because the arra8y hasn't been initialized
   
   // Reading an out of bound value
   std::cout<<std::endl;
   std::cout << "Reading out of bound value" << std::endl;
   std::cout << "Reading value outside the array boundary (scores[15]): " << scores[15] << std::endl; // Even though 15 is outside the boundaries of the array (size 10), C++ will permit this operation.
   // This will always return a garbage value. Modifying an out of bound memory location may effect the functioning of another program that is actuallly using that memory locaation.

    //Read all the elements of an array via looping
    std::cout << std::endl;
    std::cout << "Using a for loop to read all the elements of the array: " << std::endl;
    for (size_t i {0}; i< (sizeof(scores)/sizeof(int)); i++) {
        std::cout << "Element/Loop number: " << i << " , Element value: " << scores[i] << std::endl;
    }

    // Assigning data to the array:
    scores[0] = 0;
    scores[1] = 1;
    scores[9] = 9;
    
    std::cout << std::endl;
    std::cout << "Assigned values score[0]=0,score[1]=1 and score[9]=9 to the array. Printing out the new array: " << std::endl;
    for (size_t i {0}; i< (sizeof(scores)/sizeof(int)); i++) {
        std::cout << "Element/Loop number: " << i << " , Element value: " << scores[i] << std::endl;
    }

    // Assigning a value to an out of bound element:
    // These commands will run, but they're dangerous as they are modifying memory elements not associated with your program.
    std::cout << std:: endl;
    scores[15] = 15;
    std::cout << "Value of out of bound element scores[15] assigned to 15. Printing this value out: " << scores[15] <<std::endl;

    // Manually writing data into arrays using a loop
    std::cout << std::endl;
    std::cout << "Manually entering and printing the elements of an array via a loop." << std::endl;
    for (size_t i=0; i<10; i++) {
        scores[i] = i*3;
        std::cout << "Value of scores[" << i << "] is: " << scores[i] << std::endl;
    }

    // Declaring and initializing array at the same time
    std::cout << std::endl;
    std::cout << "Single step initialization and declaration of array: " << std::endl;
    double salaries[5] {12.7,7.5,13.2,8.1,9.3};
    for (size_t i {0}; i <5; i++) {
        std::cout << "Value of salaries[" << i <<"] is: " << salaries[i] << std::endl;
    }
    

    std::cout << std::endl;
    std::cout << "Initalizing only some of the elements of an array: " << std::endl;
    int families[5] {3,7,8}; // When initializing an array we can leave out elements. In this case only the first 3 elements are intialized, the rest will automatically be initialized to 0.
    // This can be modded into a quick way to initialize and entire array to 0 e.g. int scores[100] {0};
    for (size_t i {0}; i < 5; i++) {
        std::cout << "families[" << i <<"]: " << families[i] << std::endl;
    }
    // Initializing an array to 0
    // Initializing part of the array to any value (in this case initializing the first element of the array to 0) will automatically initialize the rest of the array elements to 0.
    int test_array[100] {0};

    std::cout<<std::endl;
    // If we initialize and array during declaration, we can ommit the size of the array - the compiler will deduce the size from the number of elements used to initialize the array
    int cats[] {6,5,4};
    std::cout << "Number of elements in cats (int cats[] {6,5,4}: " << sizeof(cats)/sizeof(int) <<std::endl;

    // Using range based loops to access values of an arrays (syntactically clearer)
    std::cout << std::endl;
    std::cout << "Getting values with a range based for loop: " << std::endl;
    int fruits[] {3,7,2,5,3,8,9};
    for (auto value : fruits) { // A range based for loop
        std::cout << "Value: " << value << std::endl;
    }

    // Setting a constant array, (elements can't be modified after initialization - like tuples in python)
    const int const_array[] {1,2,3,4,5};

    // Performing operatings on an array:
    std::cout << std::endl;
    double cost[] {2.2,3.5,7.8,9.9,10.4,6.7,3.5,9.1};
    double sum = 0;
    for (double element : cost) {
        sum = sum+element;
    }
    std::cout << "The sum of elements in array cost is: " << sum <<std::endl;

   return 0;
}
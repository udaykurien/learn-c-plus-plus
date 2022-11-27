#include <iostream>
int main() {
    /*
    Null Pointer Safety (11:38:04)
    Measures that you take to ensure that pointers contain valid memory addresses.
    If the pointer doesn't have a valid address then it shouldnt be used
    */

   //Compact form of if statement
   // 0, nullptr, false are equivalent
   // Non-0, non-nullptr, true are equivalent
   // We can directly use these instead of an expression that yiels a boolean
   // eg.
   if (-54.2){ //-54.2 is non-0, therefore the 'if' interprets it as 'true'
    std::cout << "Yes" << std::endl;
   } else {
    std::cout << "No" << std::endl;
   }

   //Verbose nullptr check
   int *p_num {}; // braced initialization
   if (!(p_num == nullptr)){
    std::cout << "p_num points to a VALID memory address: " << p_num << std::endl;
   } else{
    std::cout << "p_num points to an INVALID address" << std::endl;
   }

   //Compact version
   //A pointer can implicitly be converted to a boolean which can be interpreted by the if statement
   if (p_num){
    std::cout << "p_num points to a VALID memory address: " << p_num << std::endl;
   } else{
    std::cout << "p_num points to an INVALID address" << std::endl;
   }

   //Note: calling delete on a nullptr is ok, but calling delete on an already deleted pointer will cause undefined behaviour i.e. you can safely call delete on a nullpointer but not an empty pointer
   int* p_num1 {};
//    delete p_num1; //ok
//    delete p_num1; //double delete not ok
    // in the above example make sure that you follow the delete with an assignation to a null pointer, when you write actual code

    //Also no need to overdo things like use an if, because if you've properly followed the conventioins of creating pointers, the pointer will either contain a valid address or a nullpointer, and its perfectly safe to use the delete operation on either of these.  The only time the delete operator is unsafe, is when the pointer is empty, and this usually happens when you forget to reassign the pointer to a nullpointer after a deletion somewhere earlier in the code.
    if(p_num1){
        delete p_num1;
        p_num = nullptr;
    }

    int* p_num2 {};
    //Compact deletion and reasign to nullptr(????)
    delete p_num2;
    nullptr;

   return 0;
}
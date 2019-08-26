// Pointers store address of variables or a memory location.

// General syntax
// datatype *var_name;

// To access address of a variable to a pointer, we use the unary operator & (ampersand)

// One more operator is unary * (Asterisk) which is used for two things :
// To declare a pointer variable: When a pointer variable is declared in C/C++, there must a * before its name.
// To access the value stored in the address we use the unary operator (*) that returns the value of the variable located at the address specified by its operand.


/* Test Function Pointers (TestFunctionPointer.cpp) */
#include <iostream>
using namespace std;

int arithmetic(int, int, int (*)(int, int));
    // Take 3 arguments, 2 int's and a function pointer
    //   int (*)(int, int), which takes two int's and return an int
int add(int, int);
int sub(int, int);

int add(int n1, int n2) { return n1 + n2; }
int sub(int n1, int n2) { return n1 - n2; }

int arithmetic(int n1, int n2, int (*operation) (int, int)) {
   return (*operation)(n1, n2);
}

int main() {
   int number1 = 5, number2 = 6;

   // add
   cout << arithmetic(number1, number2, add) << endl;
   // subtract
   cout << arithmetic(number1, number2, sub) << endl;
}

/*
    Play around with the ordering of where the functions are

    Remember: the compiler reads top down, so if you call a function
    it has yet to have seen, it will be big mad. 
    
    Things to mess around with:
    Try having the declarations and definitions in the same location. 
    Try having no declarations.
    See if you can initialize an integer "num" and call it in menu().
*/

// LIBRARIES
#include <iostream>
#include <string>
using namespace std;

// ===============

// FUNCTION DECLARATIONS
void math();
int add(int x, int y);
int multiply(int a, int b);

// ===============

// MAIN DRIVER
int main() {

    math();

    return 0;
}

// ===============

// FUNCTION DEFINITIONS
void math() {

    cout << "x = 5, y = 6" << endl;
    cout << "x + y = " << add(5, 6) << endl << endl;

    cout << "a = 10, b = 20" << endl;
    cout << "a * b = " << multiply(10, 20) << endl << endl;
}

int add(int x, int y) {
    int result = x + y;
    return result;
}

int multiply(int a, int b) {
    int result = a * b;
    return result;
}
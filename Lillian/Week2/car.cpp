/*
    HOW TO COMPILE AND RUN THIS PROGRAM:
    1. Open a terminal or command prompt.
    2. Navigate to the directory where this file is located.
    3. Compile the program using a C++ compiler that supports C++20. For example, if you're using g++, you can run:
        g++ car.cpp -o car
    4. Run the compiled program:
        ./car   (on Unix/Linux/Mac)
*/


// ======================================= LIBRARIES
#include <iostream>
#include <string>
using namespace std;

// ======================================= CLASS DEFINITION(S)
class Car {
    public:     
        // Make sure to have the public access specifier here,
        // otherwise the class members will be private by default and you won't be able to access them.
        string make;
        string model;
        int year;
        string color;
};  // NOTE: we have to have a semicolon at the end of a class definition, otherwise it will throw an error

// ======================================= FUNCTION DECLARATION(S)
string set_car(Car myCar);

// ======================================= MAIN FUNCTION
int main() {
    Car myCar;

    cout << "==== CAR INFO ====" << endl;
    cout << set_car(myCar) << endl;         

    // Yes! We can pass a class object to a function! (as long as the function is set up to accept it)
    // and yes, we can also return a string from a function and print it to the console in one line like this!

    return 0;
}

// ======================================= FUNCTION DEFINITION(S)
string set_car(Car myCar) {
    cout << "Enter the make of your car: > ";
    cin >> myCar.make;

    cout << "Enter the model of your car: > ";
    cin >> myCar.model;

    cout << "Enter the year of your car: > ";
    cin >> myCar.year;

    cout << "Enter the color of your car: > ";
    cin >> myCar.color;

    return "\nYour car is a " + to_string(myCar.year) + " " + myCar.color + " " + myCar.make + " " + myCar.model;
}
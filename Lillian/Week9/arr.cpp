#include <iostream>
// #include <string>
#include <cctype>   // used specifically for character classification functions like isalpha, isdigit, etc.
using namespace std;

int main() {

    char hello[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    // null-terminated character array to represent a C-style string

    char world[5] = {'W', 'o', 'r', 'l', 'd'};
    // character array without a null terminator, not a proper C-style string

    /*
        the null terminator ( '\0' ) indicates the end of the string in memory
        without it, functions that expect a C-style string may read past the end of the array, 
        leading to undefined behavior.

        apparently I said the computer handles the null terminator automatically?
        ignore that, I was clearly hallucinating. 
        maybe I thought C-style strings would be kinder in C++ or something.
        they are not.
    */

    int numbers[5] = {1, 2, 3, 4, 5};   // an array of integers
    int otherNumbers[10];

    // NOTE: YOUR ARRAYS ALWAYS START AT INDEX 0

    for ( int i = 0; i < 10; i++ ) {
        otherNumbers[i] = i + 1;   // initialize the array with values 1 to 10
    }

    // ------------------------------ INTEGER ARRAY PRINTING

    cout << "\nOther numbers:\n";
    for ( int j = 0; j < 10; j++ ) {
        cout << j << ": " << otherNumbers[j] << endl;   // print the array values
    }

    cout << "\nNumbers:\n";
    for ( int j = 0; j < 5; j++ ) {
        cout << j << ": " << numbers[j] << endl;   // print the array values
    }
    cout << endl;

    // ------------------------------ CHARACTER ARRAY PRINTING

    cout << hello << endl;
    cout << world << endl;   // this may not print correctly because list is not null-terminated

    cout << "\nCharacters in hello array:\n";
    for (int k = 0; k < 5; k++) {
        cout << k << ": " << hello[k] << endl;
    }

    cout << "\nCharacters in world array:\n";
    for (int k = 0; k < 5; k++) {
        cout << k << ": " << world[k] << endl;
    }

    cout << "\nCharacters in hello array (EXTENDED):\n";
    for (int k = 0; k < 7; k++) {
        cout << k << ": " << hello[k] << endl;
    }

    cout << "\nCharacters in world array (EXTENDED):\n";
    for (int k = 0; k < 7; k++) {
        cout << k << ": " << world[k] << endl;
    }   // NOTE: try commenting out the properly defined hello array and observe the behavior
        //       also try defining list BEFORE hello
        //       things get funky weird don't they? Reason is memory stuff that I won't get into here
    
    /*
        also apparently you don't need to use a different index variable for each loop
        you can reuse the same index variable in different loops without any issues.

        AS LONG AS the loops are not within each other (i.e., not nested).
        that then messes with scope stuff

        BAD CODE EXAMPLE:
        for (int i = 0; i < 10; i++) {
            for (int i = 0; i < 5; i++) {
                cout << i << endl;
            }
        }
    */

    // ------------------------------ USER INPUT FOR CHARACTER ARRAYS

    cout << "\nEnter your name (NO SPACES):\n> ";
    char name[50];
    cin >> name;   // read the input into the character array
    cout << "Hello, " << name << "!" << endl;

    cout << "\nEnter your full name (WITH SPACES):\n> ";
    char fullName[50];
    cin >> fullName;
    cout << "Hello, " << fullName << "! (BAD OUTPUT)" << endl;
    // Observe how the input behaves differently when using cin with and without spaces!!

    return 0;
}
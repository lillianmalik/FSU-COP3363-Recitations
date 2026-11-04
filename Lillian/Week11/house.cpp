#include <iostream>
#include <string>
using namespace std;

void print_houses(int &houseA, int &houseB);
void print_note(int &stickynote, string &location);

int main() {
    // HOUSE ADDRESS EXAMPLE

    /*
         /\             /\
        /  \           /  \
        |50|           |20|
    123 main st    456 main st

    stickynote -> address
    *stickynote = some value inside

    */

    int houseA = 50;        // &houseA = 123 main street
    int houseB = 20;        // &houseB = 456 main street
    string A_addr = "123 main st";
    string B_addr = "456 main st";

    string sticky_location;
    int *stickynote;        // points to a value at a specific address

    // * indicates that this variable (stickynote) is an address
    // so when setting the value at that address...
    // we use * to say "hey go there and change whatever is at address (stickynote)"

    // & is to reference the address of a NON-address variable
    // so houseA and houseB are regular integers, and we use & to reference their locations in memory
    // we use it so we don't make and modify copies of a variable instead of the ACTUAL variable

    bool quit = false;
    char choice;

    print_houses(houseA, houseB);

    do {
        cout << "What house do we want to modify? ('A' or 'B'): ";
        cin >> choice;
        switch(choice) {
            case 'A':
            case 'a':
                stickynote = &houseA;           // point at address
                sticky_location = A_addr;       // just for pretty purposes
            break;
            case 'B':
            case 'b':
                stickynote = &houseB;           // point at address
                sticky_location = B_addr;       // just for pretty purposes
            break;
            default:
                cout << "invalid option. exiting the program." << endl;
                quit = true;
                continue;       // here's how to exit a loop's current run prematurely
                // it skips everything else to check the while condition
                // since we just set it to true, we exit the loop
            break;
        }

        cout << "what would you like the change the value inside the house to? (two digit int please)\n> ";
        int value;
        cin >> value;

        *stickynote = value;    // change value INSIDE house

        print_houses(houseA, houseB);
        print_note(*stickynote, sticky_location);
        // NOTE that I'm passing *stickynote instead of regular stickynote
        // my question for you is to figure out WHY I do it this way.
        // hint: mess around with this program, remove *'s add &'s, see what happens!

        cout << "want to go again? ('Y' or 'N')\n> ";
        cin >> choice;
        switch(choice) {
            case 'Y':
            case 'y':
                quit = false;
            break;
            case 'N':
            case 'n':
                quit = true;
            break;
            default:
                cout << "invalid option. looping again regardless." << endl;
            break;

        }
    } while(!quit);

    cout << "\nRAW VALUES:\n-----\nhouseA = " << houseA << "\n&houseA = " << &houseA << "\n-----\nhouseB = " << houseB;
    cout << "\n&houseB = " << &houseB << "\n-----\nstickynote = " << stickynote << "\n&stickynote = " << &stickynote;
    cout << "\n*stickynote = " << *stickynote << endl << endl;

    return 0;
}

void print_houses(int &houseA, int &houseB) {
    cout << "\n    /\\             /\\ \n   /  \\           /  \\ \n   |";
    cout << houseA << "|           |" << houseB << "|\n123 main st    456 main st\n\n";
}

void print_note(int &stickynote, string &location) {
    cout << "stickynote -> " << location << endl;
    cout << "*stickynote = " << stickynote << endl << endl;
}
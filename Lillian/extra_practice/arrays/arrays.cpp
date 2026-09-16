/*
    Hi guys!!

    This program is to help understand arrays and how to use them in C++.
    We will be using the <cctype> library to help us.
    The <cctype> library is a C++ standard library that provides functions for 
    character classification and manipulation.

    This program simulates a line in which characters/strings can be inserted by the user.
    the user can insert the characters where ever they want, and can
    remove characters from the line as well. The user can also view the line at any time.

    Main operations are:
    - Insert a character at a specific position in the line
    - Remove a character from a specific position in the line
    - Serve a character from the front of the line
    - View the current line
    - Identify the spot of a specific character in the line

    It's excessively long because there are notes sprinkled throughout, as well as
    some areas which I would like for you guys to attempt to improve upon, so be sure
    to read the comments carefully! :)
*/

#include "header.hpp"

int lineCount;  // a global variable needs only be declared in ONE .cpp file

int main() {
    
    bool exit = false;

    string userInput;
    char chosenChar;

    const int MAXLENGTH = 15;   // Let's cap our line at 15 so we don't overwhelm ourselves
    char line[MAXLENGTH];

    int spot;
    
    lineCount = 0;  // lineCount is a global variable, initialized here

    // LOOP TYPE 1: The do-while loop
    do {
    /*
        A do-while loop runs the contents once, then checks the condition 
        (the exit boolean) at the end.
        
        Versus a while loop checks the condition at the beginning, and if it is false, 
        it will not run the contents of the loop
    */
    
        menu();     // display the menu options to the user every time the loop runs
        /*
            ===== Menu Options =====
            1. Insert a character at a specific position in the line
            2. Remove a character from a specific position in the line
            3. Serve a character from the front of the line
            4. View the current line
            5. Identify the spot of a specific character in the line
            6. Exit
        */
       /*
            Here's a few practice questions, how would you
            1. add a "clear screen" option to the menu? (hint: research the system() function)
            2. what about an option to "clear the line" and remove all characters from it?
            3. or an option to "sort the line" in alphabetical order? (difficult)
       */
        cout << "User Selection (1-6): > ";
        cin >> userInput;  // get the user's input for the menu option

        int choice = stoi(userInput);

        switch(choice) {
            case 1: // Insert

                if (lineCount < MAXLENGTH) {
                    cout << "Enter the character you want to insert: ";
                    cin >> chosenChar;  // get the character the user wants to insert

                    cout << "Enter the position you want to insert the character at (0-" << lineCount << "): ";
                    cin >> spot;        // get the position the user wants to insert the character at

                    if (spot > lineCount) {
                        spot = lineCount;   
                        /*
                            We don't want to have memory problems, so we default to
                            the end of the array if the user picks something too big
                            
                            [0 ,  1,   2,    3]
                            [a], [b], [c], [\0]
                            say we have a linecount of 3 (a, b, and c)
                            if we were to select 5, that would be out of bounds 
                            (which would cause a segmentation fault, i.e. a "core dumped" error)

                            [0 ,  1,   2,    3]     4,   5]
                            [a], [b], [c], [\0]    [ ], [ ]
                            4 and 5 are outside of our memory scope, and will return garbage data
                            when fetched. so make sure that you're keeping track of where you are.

                            we want to replace that end of array indicator (the null terminator \0)
                            with our new value, and extend it once
                        */
                    } else if (spot < 0) {
                        spot = 0;
                    }

                    // check if the line is full
                    if (spot >= MAXLENGTH) {
                        cout << "That spot is out of bounds." << endl;
                    
                    // check to see if the new customer is already in line
                    } else if (spotInLine(line, lineCount, chosenChar) != -1) {
                        // spotInLine is a function defined in util.cpp

                        cout << chosenChar << " is already in line." << endl;
                    
                    // if these conditions are cleared, add to the line!
                    } else {
                        insert_char(line, lineCount, spot, chosenChar);
                        // this is a function defined in util.cpp
                    }
                } else {
                    cout << "The line is full." << endl;
                }

                break;  // indicates the end of the case
            case 2: // Remove

                cout << "Enter the character you want to remove: ";
                cin >> chosenChar;

                if (spot <= lineCount && spot >= 0) {
                    // make sure to add guard rails so the user doesn't break it!

                    if (spotInLine(line, lineCount, chosenChar) == -1) {
                        cout << chosenChar << " is not in line.\n";
                    } else {
                        // find the spot of the user input
                        spot = spotInLine(line, lineCount, chosenChar);

                        leave_line(line, lineCount, spot);
                    }
                }

                break;
            case 3: // Serve
                if(lineCount != 0) {
                    serve_line(line, lineCount);
                } else {
                    cout << "The line is empty.\n";
                }
                break;
            case 4: // View
                if(lineCount != 0) {
                    cout << "There are " << lineCount << " customers in line." << endl;
                    printLine(line, lineCount);
                } else {
                    cout << "The line is empty.\n";
                }
                break;
            case 5: // Identify
                if(lineCount != 0) {
                    cout << "Enter the character that you want to ID: ";
                    cin >> chosenChar;

                    if(spotInLine(line, lineCount, chosenChar) != -1) {
                        cout << chosenChar << " is in slot ";
                        cout << spotInLine(line, lineCount, chosenChar) << endl;
                    } else {
                        cout << chosenChar << " is not in line." << endl;
                    }

                } else {
                    cout << "The line is empty.\n";
                }
                break;
            case 6: // Quit
                cout << "Exiting the program..." << endl;
                exit = true;    // set out exit boolean to true, which will break the loop
                break;
            default:
                cout << "Invalid selection, Please Try Again!" << endl;
                break;
        }

    } while(!exit); // while exit is false, keep looping

    return 0;
}
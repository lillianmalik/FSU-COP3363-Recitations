#include <iostream>
#include <string>
using namespace std;

int main() {

    // for-loop examples
    // for ( start; end; increment by ) {...}

    cout << "i += 2 block:" << endl;
    for ( int i = 0; i < 11; i += 2 ) {
        // when will this loop's contents be called?
        cout << i << endl;
    }

    cout << "\nif (j == 3) continue block:" << endl;
    for ( int j = 0; j < 6; j++ ) {
        if (j == 3) {
            continue;
        }

        cout << j << endl;
    }

    // while versus do-while loop examples:

    /*
        "while x, keep doing y"     -> while(x) { y }
        "do a while b is still c"   -> do { a } while( b == c );
    */

    bool trueorfalse = false;

    cout << "\nOur condition is FALSE, while(x) block:" << endl;
    while(trueorfalse) {
        // will not run since our conditional variable is false
        // meanwhile it expects said variable to be true

        cout << "\n\tfirst while loop called" << endl;
    }

    cout << "\nOur condition is still FALSE, while(!x) block:" << endl;
    while(!trueorfalse) {
        trueorfalse = true;
        cout << "\n\tsecond while loop called" << endl;
    }

    int counter = 0;

    cout << "\nOur condition is now TRUE, while(x) block:" << endl;
    while(trueorfalse) {
        // will run because our second while loop
        // modified our conditional
        counter++;
        cout << "\n\tthird while loop called" << endl;

        if (counter == 5) {
            break;
        }
    }

    cout << "\nOur condition is still TRUE, do { ... } while(!x) block:" << endl;
    do {
        // will always run once, until it checks the conditional variable
        // here we set our condition to "while false" but because we
        // set our variable to true, it will only run one time

        cout << "\n\tfirst do-while loop called" << endl;

    } while(!trueorfalse);  // also note that our do-while loops need a semicolon at the end!


    // if-else statement examples:

    /*
        PRACTICE QUESTION!!
        these are BAD examples of if-statements, why?
        how would you fix it?
    */

    // which statement(s) will actually be seen on the terminal/console?
    // try executing the code to see if you're right :)
    if (trueorfalse) {
        cout << "\n(1) an if(x) statement..." << endl;
    } else if (trueorfalse == true) {
        cout << "\n(2) is the same as an if(x == true) statement..." << endl;
    } else if (trueorfalse == 1) {
        cout << "\n(3) and so is an if(x == 1) statement." << endl;
    } else {
        // i.e. if trueorfalse == false
        cout << "\n(4) should our condition not be met, we use an else";
        cout << " to be our default" << endl;
    }

    // what about this if-else statement?
    if (!trueorfalse)
        cout << "\n(5) an if(!x) statement..." << endl;
    else
        cout << "\n(6) is the same as an if(x == false) statement..." << endl;
        cout << "\n(7) and so is an if(x == 0) statement." << endl;

    string input;
    do {
        int option = 0;

        cout << "\ninput one of the following:" << endl;
        cout << "- \"first\"\n- \"second\"\n- \"third\"\n- \"quit\"" << endl;
        /*
            some characters (like "") conflict with how c++ works
            in this case, adding a '\' before them allows us to still print
            them to the screen! :)        
        */

        cin >> input;

        if (input == "first") {
            option = 1;
        } else if (input == "second") {
            option = 2;
        } else if (input == "third") {
            option = 3;
        } else if (input == "quit") {
            option = 4;
        }

        /*
            PRACTICE QUESTION!!!
            how would you make it so where if the user enters "quit", it also prints
            the same message as first, second, and third, but BEFORE letting
            the user know we're exitting the loop?
        
            so desired output:
                user input: "quit" -> option number: 4
                exiting the do-while loop...
        */

        switch(option) {
            case 1: // without the break between cases, it effectively acts as an
            case 2: // "or" condition. all cases will execute the code until they
            case 3: // hit a "break"
                cout << "\nuser input: \"" << input << "\" -> option number: " << option << endl;
                break;
            case 4:
                cout << "\nexiting the do-while loop..." << endl;
                break;
            default:
                cout << "\nBAD ENTRY, PLEASE TRY AGAIN!" << endl;
                break;
        }
    } while(input != "quit");
    

    return 0;
}
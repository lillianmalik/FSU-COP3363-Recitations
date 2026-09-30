#include <iostream>
#include <string>
using namespace std;

int main() {

    int x,y,z;
    char a,b,c;
    bool value;

    // cin & if-else
    cout << "\n== PART 1 ==" << endl;
    cout << "Input 2 int values: y z\n> ";
    cin >> y >> z;

    x = 15;

    if (x > y || x > z) {
        // enters when at least one of the variables is greater than 15
        cout << "x (15) is greater than y AND/OR z" << endl;
    } else {
        // enters when BOTH variables are greater than or equal to 15
        cout << "x (15) is less than (or equal to!!) y AND z" << endl;
    }

    cout << "\n== PART 2 ==" << endl;
    cout << "** note: on some compilers entering a non-number will result in an infinite torture loop." << endl;
    cout << "         to exit, hit cntrl + c\n" << endl;
    cout << "Enter a boolean value (bad practice):\n> ";
    cin >> value;

    cout << "User entered: " << value << endl;
    cout << "Anything other than an integer value is treated as false/invalid" << endl;
    cout << "0 = false, and any other number = true" << endl;

    cout << "\n== PART 3 ==" << endl;

    bool input; // note: defaults to false if left uninitialized
    do {
        cout << "\nThis is a do-while loop" << endl;
        cout << "It will run once, before checking the" <<
                " condition\nvariable to see if it should run again\n";
        cout << "Would you like to run this loop again? (y/n):\n> ";
        cin >> a;

        if (a == 'y' || a == 'Y') {
            input = true;
        } else if (a == 'n' || a == 'N') {
            input = false;
        } else {
            cout << "Invalid input. Defaulting to false (uninitialized)." << endl;
            cout << "Note: entering a string rather than a single char value "
                    "may result in weird user-interface errors." << endl;
            cout << "i.e., things might look wonky" << endl;
        }

    } while (input);

    input = true;

    cout << "\n== PART 4 ==" << endl;
    while (input) {
        cout << "\nThis is a while loop" << endl;

        // note that this is a valid cout statement, but that we have to enclose both in double quotes ""
        cout << "The boolean value has been forcibly set to true "
            "so that it will run\n";
        
        bool choice = true;
        do {
            cout << "\nIt has what is called a \"nested\" do-while loop inside of it" << endl;
            cout << "With a localized boolean variable called \"choice\"" << endl;
            cout << "We can only use this variable inside of our while loop" << endl;

            cout << "Would you like to run this internal do-while loop again? (y/n):\n> ";
            cin >> b;

            if (b == 'y' || b == 'Y') {
                choice = true;
            } else if (b == 'n' || b == 'N') {
                choice = false;
            } else {
                cout << "Invalid input. Defaulting to false (uninitialized)." << endl;
            }
        } while(choice);

        cout << "\nDo you also want to quit the while loop the do-while loop was nested inside?";
        cout << " (y/n):\n> ";
        cin >> c;

        if (c == 'y' || c == 'Y') {
            input = false;  // user WANTS to quit -> while loop only runs when input = true
        } else if (c == 'n' || c == 'N') {
            input = true;
        } else {
            cout << "Invalid input. Defaulting to false (uninitialized)." << endl;
        }
    }

    cout << "\n== PART 5 ==" << endl;
    cout << "Next up, is how to escape from an infinite torture loop." << endl;
    cout << "We will be using a switch statement with a menu to keep things organized" << endl;
    cout << "** remember, to abort ship hit cntrl + c **" << endl;

    bool quit = false;
    do {
        cout << "\n---- MENU ----\n"; 
        cout << "a. print \"hello\"\n";
        cout << "b. print \"world\"\n";
        cout << "c. print \"hello world\"\n";
        cout << "d. a mysterious fourth option...\n";
        cout << "e. quit for extra notes\n";
        cout << "> ";

        char menu_choice;
        cin >> menu_choice;

        switch(menu_choice) {
            case 'a':   // if (menu_choice == a OR A)
            case 'A':
                cout << "hello" << endl;
                break;
            case 'b':   // else if (menu_choice == b OR B)
            case 'B':
                cout << "world" << endl;
                break;
            case 'c':   // else if (menu_choice == c OR C)
            case 'C':
                cout << "hello world" << endl;
                break;
            case 'd':   // else if (menu_choice == d OR D)
            case 'D':

                cout << "\nThe program wants an integer" << endl;
                cout << "...But what if we input a character?" << endl;

                cout << "Enter a letter or symbol of your choice (non-number) "
                        "or 1 to go back to the menu:\n> ";
                int break_it;
                cin >> break_it;

                if (break_it == 1) {
                    cout << "uh oh" << endl;
                } else {
                    cout << "what will happen?" << endl;
                }
                break;
            case 'e':
            case 'E':
                quit = true;
                cout << "Exiting the do-while switch-case example..." << endl;
                break;
            default:    // else
                cout << "Invalid option, please try again." << endl;
                break;
        }
    } while(!quit);

    cout << "\n=== FINAL NOTES ===" << endl;
    cout << "\nIn terminal..." << endl;
    cout << "Cntrl + C => Stop running the program executable" << endl;
    cout << "Cntrl + D => Kill terminal" << endl;
    cout << "\nIn code file..." << endl;
    cout << "Cntrl + S => Save changes made to your program code" << endl;
    cout << "Cntrl + C => Copy" << endl;
    cout << "Cntrl + V => Paste" << endl;
    cout << "Cntrl + Z => Undo" << endl;
    cout << "Cntrl + Y => Redo" << endl;
    cout << "\nCntrl + / => Comment out selected text" << endl;
    cout << "Cntrl + Shift + ` => New terminal" << endl;
    cout << "\nShift + Tab => Move line of code to the left" << endl;
    cout << "Tab => Move line of code to the right" << endl;
    
    return 0;
}
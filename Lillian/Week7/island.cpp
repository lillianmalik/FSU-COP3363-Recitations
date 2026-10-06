/*

    Here we have edited the original Hello Kitty Island Adventure program
    from Week6 to have functions inside. There are some small differences compared
    to the versions we went over in-class, see if you can find them! :)

*/

#include <iostream>     // iostream
#include <cstdlib>      // rand() & srand()
#include <ctime>        // seed randomness
#include <string>       // no char arrays (I always add this, just in case)
using namespace std;


void menu () {
    cout << "a. go fishing!! ><(((o> " << endl;
    cout << "b. go see keroppi (o.o)" << endl;
    cout << "c. go to the tikki hut B-)" << endl;
    cout << "d. quit" << endl;
    cout << "> ";
}

bool fishing() {
    int attempts = 0;
    bool caught_smth = false;
    int fish;

    srand(time(0));

    while (!caught_smth) {
        attempts++;

        cout << "\nRound " << attempts << "... FIGHT!" << endl;
        int what_did_you_catch = rand() % 4;

        switch(what_did_you_catch) {
            case 0:
                cout << "You caught a soggy boot :(" << endl;
                cout << "You keep it to throw away later (Hello Kitty does NOT litter)" << endl;
                break;
            case 1:
                cout << "You caught a sandwich!" << endl;
                cout << "... you ate it." << endl;
                cout << "it was soggy :(" << endl;
                break;
            case 2:
                cout << "You caught a ... necklace?" << endl;
                cout << "Wonder who it belongs to..." << endl;
                break;
            case 3:
                cout << "YOU CAUGHT SOMETHING!!" << endl;
                cout << "...what is it?" << endl;

                cout << "\nit's...." << endl;
                fish = rand() % 2;
                
                if (fish == 0) {
                    cout << "A SHARK!" << endl;
                    cout << "{ YOU DIED }" << endl;
                    return true;
                } else if (fish == 1) {
                    cout << "A PUFFERFISH!" << endl;
                    cout << "Aw... can't eat that, maybe next time!\n" << endl;
                } else {
                    cout << "Something went wrong when generating your fish...\n" << endl;
                }
                
                caught_smth = true;
                break;
            default:
                cout << "Something went wrong when fishing...\n" << endl;
                break;
        }
    }
    return false;
}

int main () {

    /*
        GOALS:

        we want a menu
        where one of the options is to go fishing
        or do other stuff
        or quit the program
        

        if we go fishing
            we want to continue until we catch a fish
                1/4 chance we catch a fish
                    but if we catch a shark, we die
    */


    cout << "~~~ WELCOME TO HELLO KITTY ISLAND ADVENTURE! =(^o.o*^)= ~~~" << endl;

    bool quit = false;

    do {

        menu();

        char input;
        cin >> input;

        switch(input) {
            case 'a':
            case 'A':
                // call fishing function
                // returns: whether the user died by shark or not
                quit = fishing();
                break;
            case 'b':
            case 'B':
                // note: added \n for pretty output
                cout << "\nnot implemented yet\n" << endl;
                break;
            case 'c':
            case 'C':
                cout << "\nnot implemented yet\n" << endl;
                break;
            case 'd':
            case 'D':
                quit = true;
                break;
            default:
                cout << "WRONG ANSWER! Try again!" << endl;
                break;
        }
    } while (!quit);
    return 0;
}
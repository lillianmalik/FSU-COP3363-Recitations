#include <iostream>     // iostream
#include <cstdlib>      // rand() & srand()
#include <ctime>        // seed randomness
#include <string>       // no char arrays (I always add this, just in case)
using namespace std;

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
    int attempts;       
    bool caught_smth;
    int fish;

    do {
        cout << "a. go fishing!! ><(((o> " << endl;
        cout << "b. go see keroppi (o.o)" << endl;
        cout << "c. go to the tikki hut B-)" << endl;
        cout << "d. quit" << endl;
        cout << "> ";

        char input;
        cin >> input;

        switch(input) {
            case 'a':
            case 'A':
                attempts = 0;           // want it to reset every fishing session
                                        // but if you want to track the number of times
                                        // ever fished, initialize at declaration :)
                caught_smth = false;    // initialize at the beginning of each session

                srand(time(0));
                // time: at line execution
                // seed: if we seed it with the same time, it will give us the same random number in the same order
                // think minecraft world seeds

                while (!caught_smth) {
                    attempts++;

                    cout << "Round " << attempts << "... FIGHT!" << endl;
                    int what_did_you_catch = rand() % 4;

                    switch(what_did_you_catch) {
                        case 0:
                            cout << "You caught a soggy boot :(" << endl;
                            cout << "You keep it to throw away later (Hello Kitty does NOT litter)\n" << endl;
                            break;
                        case 1:
                            cout << "You caught a sandwich!" << endl;
                            cout << "... you ate it." << endl;
                            cout << "it was soggy :(\n" << endl;
                            break;
                        case 2:
                            cout << "You caught a ... necklace?" << endl;
                            cout << "Wonder who it belongs to...\n" << endl;
                            break;
                        case 3:
                            cout << "YOU CAUGHT SOMETHING!!" << endl;
                            cout << "...what is it?\n" << endl;

                            cout << "it's...." << endl;
                            fish = rand() % 2;
                            
                            if (fish == 0) {
                                cout << "A SHARK!" << endl;
                                cout << "{ YOU DIED }" << endl;
                                quit = true;
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
                break;
            case 'b':
            case 'B':
                cout << "not implemented yet" << endl;
                break;
            case 'c':
            case 'C':
                cout << "not implemented yet" << endl;
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
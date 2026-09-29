#include <iostream>     // iostream

#include <cstdlib>      // rand() & srand()
#include <ctime>        // seed randomness

#include <string>       // no char arrays and also for your catch
using namespace std;

int main() {

    // uncomment different options to test! :)

    srand(time(0)); // allows for true randomness
    // srand() // MUST be initialized
    // srand(3) // minecraft seed of 3


    // ----
    int num = rand() % 4;   // between 0 and 3
    cout << num << endl;

    num = rand() % 4;
    cout << num << endl;

    // ----
    num = rand() % 2;   // between 0 and 1
    cout << num << endl;

    num = rand() % 2;
    cout << num << endl;

    // ----
    num = time(0);
    cout << num << endl;

    num = time(0);
    cout << num << endl;

    return 0;
}
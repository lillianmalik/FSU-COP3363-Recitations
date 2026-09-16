#include "header.hpp"

void menu() {
    cout << "\n===== Menu Options =====\n";
    cout << "1. Insert a character at a specific position in the line\n";
    cout << "2. Remove a character from a specific position in the line\n";
    cout << "3. Serve a character from the front of the line\n";
    cout << "4. View the current line\n";
    cout << "5. Identify the spot of a specific character in the line\n";
    cout << "6. Exit\n" << endl;
}

void insert_char(char arr[], int size, int spot, char chosenChar) {
    int head = size - 1;
    int tail = size;

    // [a], [b], [c], [d], [\0]
    // lineCount = 4
    // head = 3 (d)         remember, arrays START at 0
    // tail = 4 (\0)

    while(tail >= spot && head >= spot) {
        // copies the customer and pushes it back one slot

        /* VISUAL EXAMPLE:
            Let's say we want to cut in front of c (position 2)

            1. our initial array:
            [a], [b], [c], [d], [\0]

            2. duplicate d 
            [a], [b], [c], [d], [d], [\0] 
            (in C++ it automatically adds a null terminator)

            3. duplicate c
            [a], [b], [c], [c], [d], [\0]

            4. place new character
            [a], [b], [X], [c], [d], [\0]
        */
        arr[tail] = arr[head];
        head--;
        tail--;
    }
    // 4. [a], [b], [chosenChar], [c], [d], [\0]
    arr[spot] = chosenChar;
    lineCount++; // increment the line count after inserting a character
}

void leave_line(char arr[], int size, int spot) {
    for(int i = spot; i < size; i++) {
        arr[i] = arr[i + 1];
    }
    /* VISUAL EXAMPLE:
        Let's say we want to remove c (position 2)
        1. 
        [a], [b], [c], [d], [\0]

        2. duplicate d over c
        [a], [b], [d], [d], [\0]

        3. replace the last d with a null terminator
        [a], [b], [d], [\0], [\0]

        4. the program will automatically ignore the second null terminator
        [a], [b], [d], [\0]
    */
    lineCount--;    // decrement the line count after removing
}

void serve_line(char arr[], int size) {
    /*
        serving a character is effectively just removing them from
        slot 0 of the array, so instead of writing the
        same function, we can just do this:
    */
    leave_line(arr, size, 0);
}

int spotInLine(char arr[], int size, char chosenChar) {
    int spot = -1;

    for ( int i = 0; i < size; i++ ) {
        if(arr[i] == chosenChar) {
            spot = i;
        }
    }

    return spot;
}

void printLine(char arr[], int size) {
    cout << "\n--Current Line--\n";
    if (size == 0) {
        cout << "The Line is Empty." << endl;
    } else {
        cout << "Spot -- Customer" << endl;
        cout << "----------------" << endl;
        for (int i = 0; i < size; i++) {
            if (i < 10) {   // For console UI formatting purposes
                cout << "  " << i << "  --  " << arr[i] << endl;
            } else {
                cout << "  " << i << " --  " << arr[i] << endl;
            }
            /*
                Here's a good practice question, how would you refine this for loop
                using any standard libraries and methods at your disposal?
                goal: remove the if-else statement and merge it into one
                hint: think about the number of digits affecting the output (1 versus 10)
            */
        }
        cout << endl;
    }
}
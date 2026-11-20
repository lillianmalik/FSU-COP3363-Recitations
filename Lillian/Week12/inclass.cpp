#include <iostream>
#include <string>
#include <cctype>   // isspace()
using namespace std;

void change_it(string &sentence);
void change_copy(string sentence);

void change_weird(string *sentence);

// now pass it the funky way (&*x)
void change_funky(string *&sentence);
void change_null(string *&sentence);

int main() {
    string user_input;
    int test;

    cout << "Input a number for our cin.ignore() example: ";
    cin >> test;
    cin.ignore(); // ignore the newline character left in the buffer after reading the number
    // note: try messing around with cin.ignore() to see how it affects the input buffer
    //       for example, try removing cin.ignore() or adding a number of characters to ignore

    cout << "Input a sentence:\n> ";
    getline(cin, user_input);

    cout << "\nYou entered: \"" << user_input << "\"" << endl;
    
    cout << "\nIs the sentence empty? ";
    if (user_input.empty()) {
        cout << "Yes" << endl;
        return 0;
    } else {
        // is it spaces all the way through?
        bool all_spaces = true;
        for (int i = 0; i < user_input.length(); i++) {
            if (!isspace(user_input[i])) {
                all_spaces = false;
                break;
            }
        }

        if (all_spaces) {
            cout << "Yes" << endl;
            return 0;
        }

        cout << "No" << endl;
    }

    cout << "Length of the sentence: " << user_input.length() << endl;
    cout << "\nMemory address of the sentence: " << &user_input << endl;
    cout << "Capacity of the sentence: " << user_input.capacity() << endl;
    cout << "Size of the sentence: " << sizeof(user_input) << endl;

    cout << "\nFirst character of the sentence: " << user_input[0] << endl;
    cout << "Last character of the sentence: " << user_input[user_input.length() - 1] << endl;
    // remember, \0 marks the end of the string, not just c-strings

    cout << "\nHow many words are in the sentence? ";

    int count = 0;
    bool in_word = false;
    for (int i = 0; i < user_input.length(); i++) {
        if (isspace(user_input[i])) {
            in_word = false;
        } else if (!in_word) {  // if we AREN'T in a space slot, AND we were not already in a word
            count++;
            in_word = true;
        }
    }
    cout << count << endl;

    // now let's use pointers to modify the sentence in a function
    // what happens if we don't pass by reference?
    change_copy(user_input);
    cout << "\nPass by value sentence: " << user_input << endl;

    change_it(user_input);
    cout << "Pass by reference sentence: " << user_input << endl;

    // let's make a more complicated function

    string *my_ptr = &user_input;
    cout << "\nMemory address of the pointer: " << my_ptr << endl;
    cout << "Value pointed to by the pointer: " << *my_ptr << endl;
    cout << "Length of the sentence via pointer: " << my_ptr->length() << endl;
    cout << "Capacity of the sentence via pointer: " << my_ptr->capacity() << endl;
    cout << "Size of the sentence via pointer: " << sizeof(*my_ptr) << endl;
    cout << "\nFirst character of the sentence via pointer: " << (*my_ptr)[0] << endl;
    cout << "Last character of the sentence via pointer: " << (*my_ptr)[my_ptr->length() - 1] << endl;
    cout << "How many words are in the sentence via pointer? ";
    int count_via_ptr = 0;
    bool in_word_via_ptr = false;
    for (int i = 0; i < my_ptr->length(); i++) {
        if (isspace((*my_ptr)[i])) {
            in_word_via_ptr = false;
        } else if (!in_word_via_ptr) {
            count_via_ptr++;
            in_word_via_ptr = true;
        }
    }
    cout << count_via_ptr << endl;

    cout << "\nPass by pointer sentence: ";
    change_weird(my_ptr);   // changes the value it points to
    cout << *my_ptr << endl;

    cout << "\nPass by pointer to pointer sentence: ";
    change_funky(my_ptr);   // changes the value it points to
    cout << *my_ptr << endl;

    cout << "Modifying the pointer itself: ";
    change_null(my_ptr);    // changes the pointer itself to null
    cout << "Pointer is now: " << my_ptr << endl;

    /*
        use cases for pass by pointer to pointer:
        - to modify the pointer itself, not just the value it points to
        - to pass a pointer to a function and want the function to be able to change the pointer's target
        - to allocate memory inside the function and want the caller to have access to it
        
        use cases for pass by pointer:
        - to modify the value pointed to by the pointer, but not the pointer itself
        - to pass a large object to a function without copying it
        - to pass a pointer that can be null
        - to pass an array to a function and want the function to be able to modify its elements
        - to pass a pointer to a function and want the function to be able to modify the object it points to

        differences between the two:
        - pointer to pointer allows the function to modify the pointer itself, while pass by pointer only allows modification of the value pointed to
        - pointer to pointer is useful when you need to allocate memory inside the function and want the caller to have access to it
        - just pointer is simpler and more common when you only need to modify the object pointed to by the pointer
    */

    return 0;
}

void change_it(string &sentence) {  // pass by reference
    sentence = "Modified sentence";
}

void change_copy(string sentence) {  // pass by value
    sentence = "Super mega modified sentence";
}

void change_weird(string *sentence) {  // pass by pointer
    *sentence = "Weird modified sentence";
}

void change_funky(string *&sentence) {  // pass by pointer to pointer
    *sentence = "Funky modified sentence";
}

void change_null(string *&sentence) {  // pass by pointer to pointer and set to null
    sentence = nullptr;
}
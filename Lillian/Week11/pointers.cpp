#include <iostream>
#include <cctype>
#include <string>
using namespace std;

void proper_name(string &name);
void modify_copy_ex(string name);       // without the & symbol

int main() {
    string name;
    string *name_ptr;   // for the indirect example
    name_ptr = &name;

    cout << "\nwhat's your name? > ";
    getline(cin, name);
    cout << "input: " << name << endl;

    // proper pass-by-reference example
    proper_name(name);
    cout << "proper name: " << name << endl;

    // copy example
    modify_copy_ex(name);
    cout << "unmodified original in main: " << name << endl;

    // indirect example (usage for '->' operator)
    cout << "indirect ex (length): " << name_ptr->length() << endl;

    cout << endl;   // for pretty purposes
    return 0;
}

void proper_name(string &name) {
    int space_spot = name.find(' ');    // only finds the first ' ' character
    // we can use . because we are given the direct object (via &)
    
    name[0] = toupper(name[0]);
    name[space_spot + 1] = toupper(name[space_spot + 1]);
}

void modify_copy_ex(string name) {
    for (int i = 0; i < name.length(); i++) {
        // here we can use . because we are directly given the copy of the obj
    
        name[i] = toupper(name[i]);
    }
    cout << "copy: " << name << endl;
}
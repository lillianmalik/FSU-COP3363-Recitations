// this is to help demonstrate dynamic memory allocation
// how to use it and when
#include <iostream>
using namespace std;
void print_house(int &house);

int main() {
    // first let's start with something simple before our house example
        
    // so whereas before we would have something like int *ptr = &x;
    // where x = 42 or something, we don't use a placeholder variable like x
    // and instead use new to access memory directly on the heap

    int *ptr = new int; // dynamically allocate an integer
    *ptr = 42;          // assign a value to the allocated memory
    cout << "\nValue pointed to by ptr: " << *ptr << endl;
    cout << "Memory address of ptr: " << ptr << endl;
    delete ptr;         // free the allocated memory
    ptr = nullptr;      // set the pointer to nullptr to avoid dangling pointer
    
    cout << "\nPointer after deletion: " << ptr << endl;
    // note: we HAVE to delete the memory we allocated with new to avoid memory leaks
    //       and we HAVE to set the pointer to nullptr after deletion to avoid dangling pointers

    // now let's move on to a more complex example with an array of integers
    int *houses = new int[5]; // dynamically allocate an array of 5 integers
    
    // two ways to assign values to this:
    houses[0] = 10;
    houses[1] = 20;
    *(houses + 2) = 30; // assign a value to the third element using pointer arithmetic
    *(houses + 3) = 40; // fourth
    *(houses + 4) = 50; // fifth

    // houses' address is the same as the first element's address:
    cout << "\nMemory address of houses: " << houses << endl;
    cout << "Memory address of houses[0] / *(houses + 0): " << &houses[0] << endl;
    cout << "Memory address of houses[1] / *(houses + 1): " << &houses[1] << endl;
    cout << "Memory address of houses[4] / *(houses + 4): " << &houses[4] << endl;
    // note: addresses are incremented by 4 because each integer takes 4 bytes of memory
    //       not super important for you to know, but if you were curious, that's why!
    
    // now let's print each house using a loop
    for (int i = 0; i < 5; i++) {
        print_house(houses[i]);
    }

    delete[] houses;    // free the allocated memory for the array
    houses = nullptr;   // set the pointer to nullptr to avoid dangling pointer
    cout << "\nPointer after deletion: " << houses << endl;
    // notice how we use delete[] for arrays and delete for single elements
}

void print_house(int &house) {
    cout << "\n    /\\ \n   /  \\ \n   |";
    cout << house << "|\n";
}
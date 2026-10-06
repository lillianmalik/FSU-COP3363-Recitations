/*
    THIS IS AN EXAMPLE ON HOW I WOULD LIKE YOUR ASSIGNMENTS
    STRUCTURED (i.e. pretty points)

    For comments:
        - use them please
        - add a header comment so I can grade easier (pls)
        
        notes: 
              it's unlikely I'll deduct points unless you
              commit what I call a "visual war crime."
              
              please spare my eyes, if you don't have
              a single comment explaining something in
              your code then something is wrong.

              ASSUME THE USER (and reader) IS AN IDIOT!!

              once you progress into the next coding class(es)
              then you won't need as many comments, but I would 
              like to be able to give partial credit.

              seeing your thought process will be beneficial
              for both me AND you (future you).
*/


/*
    Lillian Malik
    LAM22G
    Assignment X
    Due: 10/6/26
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Add comments where you made an explicit choice to do it a certain way
    // i.e. if you were asked to cout a value 15 times, you can do it these ways:

    // no need to explain for for loops or if-else statements

    // rule of thumb is:
    // if it's not immediately obvious why you did something
        // add a comment
    
    // tip: talk through your code out loud
    for(int i = 0; i < 15; i++) {
        cout << i + 1 << ". a value" << endl;
    }

    cout << endl;   // for space between loops on output

    // why a do-while loop?
    int count = 0;          // why start at 0?
    do {
        count++;
        cout << count << ". a value" << endl;
    } while(count < 15);    // why < 15?

    cout << endl;   // for space between loops on output

    // why a while loop?
    count = 0;              // why start at 0?
    while(count < 15) {     // why < 15?
        count++;
        cout << count << ". a value" << endl;
    }

    return 0;
}
#include "header.hpp"

/*
    This is your function definitions file, your program usually will have either several of these for 
    organizational purposes, or if the program is small enough, none.
    
    All of your header file and definition file contents could potentially be inside one singular .cpp file.
*/

void problem_1() {
    cout << "\n==== PROBLEM 1 ====" << endl;    // two examples of how to use a newline (\n and endl)

    int num;
    float x_val = 9876543210;
    /*
        float is the same as double, unless you're worried about memory limits
        float is 4 bytes, double is 8 bytes, long double is 16 bytes (on most systems)
        (long is a keyword used to extend the size of a number, but it is not a data type on its own)
    */
    
    cout << "Enter an integer: > ";
    cin >> num;

    cout << "\nThe hexadecimal version of that value is: " << hex << num << endl;
    
    double result = (x_val / num) * 18;

    cout << fixed << setprecision(3) << "The result of x_val / num * 18 is: " << result << endl;
    /*
        note how I inserted the string in a different place here
        in reality it doesn't matter the order of the output, 
        but it is good to be consistent with your formatting
        for readability and maintainability of your code.

        "It's a fixed value accurate to 3 decimal places" 
        reads better than 
        "Accurate to 3 decimal places, it's a fixed value"
    */
}

void problem_2() {
    cout << "\n==== PROBLEM 2 ====" << endl;

    double num1, num2;      // you can initialize and set multiple variables of the same type on the same line

    cout << "Enter two numbers separated by a space: > ";
    cin >> num1 >> num2;    // you can also input multiple values on the same line

    int val;
    cin >> oct >> val;

    cout << scientific << "The scientific notation of the product of our numbers is: " << num1*num2 << endl;
    // we don't have to have a placeholder value, but it is nice to have (see problem 1's result variable)
}

void problem_3() {
    cout << "\n==== PROBLEM 3 ====" << endl;

    int a;
    double b;

    cout << "Enter an integer and a double separated by a space: > ";
    cin >> a >> b;

    const int NUM = 150;
    /*  Some notes on the const keyword:

        "const" means that NUM cannot be changed after it is initialized.
        It also HAS to be initialized when it is declared, otherwise it will throw an error.

        If we wanted the user to input a value that's constant, we could use the const keyword 
        in the function parameter list, like this:

            void myFunction(const int x) {
                // x cannot be changed in this function
            }
        
        or use a temp variable like this:

            int temp;
            cin >> temp;
            const int x = temp;

        also: constants are usually written in all caps to distinguish them from 
              regular variables, but this is not required.
    */
    cout << "The hexadecimal version of " << NUM << " is: " << hex << NUM << endl;

    cout << "The scientific notation of (b-a)*NUM is: " << scientific << (b-a)*NUM << endl;
}

void problem_4() {
    cout << "\n==== PROBLEM 4 ====" << endl;

    const float K = 25.14;
    cout << "The fixed value of K/3 accurate to 3 decimal places is: " << fixed << setprecision(3) << K/3.0 << endl;

    int var1, var2;

    cout << "Enter two hexadecimal values separated by a space: (ex: 0x1A, 0x2B, etc.) > ";
    cin >> hex >> var1 >> var2;

    cout << "The octal version of the product of those two values is: " << oct << var1*var2 << endl;
}

void problem_5() {
    cout << "\n==== PROBLEM 5 ====" << endl;

    int x;
    float y;

    cout << "Enter an integer and a float separated by a space: > ";
    
    cin >> dec >> x;
    cin >> y;

    const int TOTAL = 19;

    cout << "The hexadecimal version of x * TOTAL is: " << hex << x*TOTAL << endl;
    cout << "The fixed version of (x + y) / TOTAL accurate to 3 decimal places is: " << fixed << setprecision(3) << (x + y) / TOTAL << endl;

    /*
        Note that spaces don't affect the output of the program, but they do affect the readability of your code.  
        It is good practice to have spaces around operators and after commas.

        Also note that we are not explicitly changing TOTAL, which is why we are able to use it in the calculations.
        We are temporarily changing the value of x and y, but not TOTAL, which is a constant.    
    */
}

/*
some notes on decimal versus binary versus octal versus hexadecimal:

    NOTE: THESE ARE NOT EXPLICITLY NECESSECARY TO KNOW RIGHT NOW !!! BUT
    SINCE WE WERE ASKED TO USE THEM IT'D BE NICE IF Y'ALL HAVE AT LEAST
    SEEN THEM BEFORE

    Decimal:        base 10,    uses digits 0-9
    Binary:         base 2,     uses digits 0-1
    Octal:          base 8,     uses digits 0-7
    Hexadecimal:    base 16,    uses digits 0-9 and letters A-F

    Here's the converstion table for the first 16 numbers in decimal, binary, octal, and hexadecimal:
    Decimal     Binary      Octal       Hexadecimal
    0           0000        0           0
    1           0001        1           1
    2           0010        2           2
    3           0011        3           3
    4           0100        4           4
    5           0101        5           5
    6           0110        6           6
    7           0111        7           7
    8           1000        10          8
    9           1001        11          9
    10          1010        12          A
    11          1011        13          B
    12          1100        14          C
    13          1101        15          D
    14          1110        16          E
    15          1111        17          F
    16          1000        20          10
    ...

    For octals, think about splitting the binary number into groups of 3 bits
    so 1000 -> 001 000 -> 10 in octal

    For hexadecimals, think about splitting the binary number into groups of 4 bits
    you'll notice a pattern in the conversion table above
    there's not really a good way to remember hexadecimal outside of memorizing the pattern

    AGAIN !! THIS IS NOT NECESSARY TO KNOW RIGHT NOW, BUT IT IS GOOD TO HAVE SEEN IT BEFORE !!
    DO NOT SPEND YOUR TIME MEMORIZING THIS YOU WONT NEED IT UNTIL CDA3100 !!!
*/

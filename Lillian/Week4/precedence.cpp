#include <iostream>
using namespace std;

int main() {

    cout << "=== PROBLEM 1 ===" << endl;

    int a1,b1,c1,d1;

    cout << "a1 b1 (int)" << endl;
    cin >> a1 >> b1;

    b1 *= a1--;
    // preferred:
    // b *= a;
    // a--;
    cout << a1 << endl << b1 << endl;


    cout << "c1 d1 (int)" << endl;
    cin >> c1 >> d1;

    if (d1 > (a1 + b1 + c1)) {
        cout << "d1 (" << d1 << ") is greater than the sum: " << (a1+b1+c1) << endl;
    } else {
        cout << "The sum of a1 + b1 + c1 (" << (a1+b1+c1) << ") is greater than d1 (" << d1 << ")" << endl;
    }

    float result1 = static_cast<float>(a1 + b1) / (c1 + d1);
    // note: remember that either the numerator OR the denominator can be cast, NOT both
    
    cout << "result1 = " << result1 << endl;




    cout << "\n=== PROBLEM 2 ===" << endl;

    int a2,b2,c2,d2;
    cout << "a2 b2 (int)" << endl;
    cin >> a2 >> b2;

    b2 += a2--;
    // preferred:
    // b *= a;
    // a--;
    cout << a2 << endl << b2 << endl;


    float x1;
    cout << "x1 (float)" << endl;
    cin >> x1;

    if ( ( static_cast<float>(b2)/a2 ) < x1 ) {
        cout << "x1 (" << x1 << ") is greater than b2/a2 (" << static_cast<float>(b2)/a2 << ")" << endl;
    } else {
        cout << "The value b2/a2 (" << static_cast<float>(b2)/a2 << ") is greater than x1" << endl;
    }




    cout << "\n=== PROBLEM 3 ===" << endl;

    int a3,b3,c3,d3;
    cout << "a3 b3 (int)" << endl;
    cin >> a3 >> b3;

    b3 -= a3++;
    // preferred:
    // b -= a;
    // a++;
    cout << a3 << endl << b3 << endl;


    cout << "c3 d3 (int)" << endl;
    cin >> c3 >> d3;

    if ((b3 + c3) == (a3 - d3)) {
        cout << "They are equal (" << (b3 + c3) << " = " << (a3 - d3) << ")" << endl;
    } else {
        cout << "They are not equal (" << (b3 + c3) << " != " << (a3 - d3) << ")" << endl;
    }

    float result2 = static_cast<float>(d3 - b3) / (c3 + a3);
    // note: remember that either the numerator OR the denominator can be cast, NOT both

    cout << "result2 = " << result2 << endl;




    cout << "\n=== PROBLEM 4 ===" << endl;

    float x2, y1;

    cout << "x2 y1 (float)" << endl;
    cin >> x2 >> y1;

    x2 /= y1--;
    // preferred:
    // x2 /= y;
    // y--;
    cout << x2 << endl << y1 << endl << endl;

    char char1;
    cout << "char1" << endl;
    cin >> char1;

    if (char1 == 'M') {
        x2 *= 3;
        y1 *= 5;

        cout << "c1 = M" << endl;
        cout << "x2 -> " << x2 << endl;
        cout << "y1 -> " << y1 << endl;
    } else {
        x2 -= 10;
        y1 -= 12;

        cout << "c1 != M" << endl;
        cout << "x2 -> " << x2 << endl;
        cout << "y1 -> " << y1 << endl;
    }

    cout << "int of (x2 + 9) / y1 = " << static_cast<int>(x2 + 9) / y1 << endl;


    cout << "\n=== PROBLEM 5 ===" << endl;

    float x3, y2;
    cout << "x3 y2 (float)" << endl;
    cin >> x3 >> y2;

    x3 *= y2++;

    cout << x3 << endl << y2 << endl << endl;

    char char2;
    cout << "char2" << endl;
    cin >> char2;

    if (char2 == 'D') {
        x3 /= 3;
        y2 /= 5;

        cout << "c2 = D" << endl;
        cout << "x3 /= 3 -> " << x3 << endl;
        cout << "y2 /= 5 -> " << y2 << endl;
    } else {
        x3 += 10;
        y2 += 12;

        cout << "c2 != D" << endl;
        cout << "x3 += 10 -> " << x3 << endl;
        cout << "y2 += 12 -> " << y2 << endl;
    }

    cout << "int of (y2 - 12.5) * x3 = " << static_cast<int>(y2 - 12.5) * x3 << endl;
    



    cout << "\n=== EXTRA EXAMPLE ===" << endl;

    cout << "Pre-fix versus Post-fix" << endl;

    int var1, var2;
    cout << "x y (int)" << endl;
    cin >> var1 >> var2;

    int var3, var4;     // placeholder variables
    var3 = var1;
    var4 = var2;

    var2 = ++var1;

    cout << "\ny = ++x :\nx = " << var1 << "\ny = " << var2 << endl;

    var4 = var3++;

    cout << "\ny = x++ :\nx = " << var3 << "\ny = " << var4 << endl;

    cout << "\nif we have p = 0..." << endl;
    int p1 = 0;
    int p2 = 0;

    cout << "\n!(p++) -> " << !(p1++) << " and new p = " << p1 << endl;
    cout << "It applied the not symbol (to !0 = 1), then incremented p (to 0++ = 1)" << endl;

    cout << "\n!(++p) -> " << !(++p2) << " and new p = " << p2 << endl;
    cout << "It incremented p (to p = 1), then applied the not symbol (to !p = 0)" << endl;

    p1 = 0;
    p2 = 0;

    cout << "\nThis is the same as:" << endl;
    cout << "!p++ -> " << !p1++ << " and new p = " << p1 << endl;
    cout << "!++p -> " << !++p2 << " and new p = " << p2 << endl;

    /*
        Okay so this section is confusing, and the reason is that the word "precedence"
        is used interchangeably depending on who you're talking to or what textbook you're reading
        
        In essence:
        Precedence does not mean "what happens first in time" 
        Precedence only means "who gets to grab the variable first"

        It is entirely about grammar and grouping (like invisible parentheses), not the timing of the math.
        Which is messed up isn't it?

        So while the "precedence" of p in !p++ is higher
        it just means that p is grabbed first
        NOT that p gets modified first.

        Which, is a nightmare to explain, and is why it's called "post" fix
        So, you can reasonably assume we WONT be testing you on this,
        since it's a collectively hated concept.
        (It's me, I hate it) -LM

        So for the "Pre and post increment operators have the same precedence" Question,
        The answer is STILL false, because ++p and p++ are grabbed at different times
        & therefore the logic is ALSO applied at different times

        Just because they are both ++, does NOT mean they have the same precedence
        Sure, maybe in terms of PEMDAS, the addition/subtraction tier, but not here.
    */
    return 0;
}
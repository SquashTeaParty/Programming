#include <iostream>
#include <string>
#include "complex/complex.hpp"
#include "log/log.hpp"

using namespace std;

// Tmp func

int main() {
    log("Info", "Start");

    Complex z1(1, 1);
    Complex z2(4, 3);

    cout << "\tz1 = "; z1.Show(); cout << "\n";
    cout << "\tz2 = "; z2.Show(); cout << "\n";
    
    // Sum
        Complex z3 = z2 + z1;

        cout << "\tz3 = z2 + z1 = "; z3.Show(); cout << "\n";
    
    // Multiplication
        Complex z4 = z1 * z2;

        cout << "\tz4 = z1 * z2 = "; z4.Show(); cout << "\n";


    // std is Friend
        Complex z5(-1, -1);

        cout << "\t";
        cin >> z5;
        cout << "\t" << z5;

        cout << "\tz5 = "; z5.Show(); cout << "\n";

    // Increment
        Complex z6 = z5;        // equal

        cout << "\t++z6 = " << ++z6;

        z6++;
        cout << "\tz6++ = "; z6.Show(); cout << "\n";

        z6+=z5;
        cout << "\tz6 += z5 = "; z6.Show(); cout << "\n";

    // Comparasion
        Complex z7 = z5 - z1;   // sub

        cout << "\tz7 = z5 - z1 = "; z7.Show(); cout << "\n\t";
        
        cout << "|z7| = " << z7.Modulo();

        if(z7 > z2) cout << " > "; else
        if(z2 > z7) cout << " < ";
        else cout << " = ";

        cout << "|z2| = " << z2.Modulo() << "\n";


    log("Info", "End");

    return 0;
}
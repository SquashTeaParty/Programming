#include <iostream>
#include <string>
#include "complex/complex.hpp"
#include "log/log.hpp"

using namespace std;

// Tmp func

int main() {
    log("Info", "Start");

    Complex z1(1, -1);
    Complex z2(4, 3);

    cout << "\tz1 = " << z1 << "\n";
    cout << "\tz2 = " << z2 << "\n";
    
    // Sum
        Complex z3 = z2 + z1;

        cout << "\tz3 = z2 + z1 = " << z3 << "\n";
    
    // Multiplication
        Complex z4 = z1 * z2;

        cout << "\tz4 = z1 * z2 = " << z4 << "\n";


    // std is Friend
        Complex z5(-1, -1);

        cout << "\t";
        cin >> z5;

        cout << "\tz5 = " << z5 << "\n";

    // Increment
        Complex z6 = z5;

        cout << "\t++z6 => z6 = " << ++z6 << "\n";

        z6++;
        cout << "\tz6++ => z6 = " << z6 << "\n";

        z6--;
        cout << "\tz6-- => z6 = " << z6 << "\n";

        cout << "\t--z6 => z6 = " << --z6 << "\n";

        z6+=z5;
        cout << "\tz6 += z5 => z6 = "<< z6 << "\n";

    // Comparasion
        Complex z7 = z5 / z1;

        cout << "\tz7 = z5 / z1 = " << z7 << "\n\t";
        
        cout << "|z7| = " << z7.Modulo();

        if(z7 == z2) cout << " == "; else
        if(z7 != z2) {
            if(z7 > z2) cout << " > "; else
            if(z7 < z2) cout << " < ";
        }

        cout << "|z2| = " << z2.Modulo() << "\n";


    log("Info", "End");

    return 0;
}
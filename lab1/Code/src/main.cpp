#include "structure.hpp"
#include <iostream>

using namespace std;

int main()
{
    Complex A, B, C;

    A = InputComplex("C1");
    B = InputComplex("C2");

    OutputComplex(A, "A");
    OutputComplex(A, "B");
    
    C = SumComplex(A, B);
    cout << "\nA + B = ";
    OutputComplex(C, "C");

    return 0;
}
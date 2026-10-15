#include <iostream>
#include "structure.hpp"
#include <string>

using namespace std;

Complex SumComplex(Complex C1, Complex C2)
{
    Complex res;

    res.re = C1.re + C2.re;
    res.im = C1.im + C2.im;

    return res;
}

Complex InputComplex (string name)
{
    Complex C;
    cout << "Enter " << name << ":\n";
    cout << "\treal part re= ";
    cin >> C.re;
    cout << "\tImaginary part im= ";
    cin >> C.im;

    cout << "\n\n";

    return C;
}

void OutputComplex(Complex C, string name)
{
    cout << name << " = (" << C.im << ") i + (" << C.re << ")\n";
}
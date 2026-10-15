#include <string>

using namespace std;

struct Complex
{
    int im;
    int re;
};

Complex SumComplex(Complex C1, Complex C2);
Complex InputComplex(string name);
void OutputComplex(Complex C, string name);
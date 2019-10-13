//============================================================================
// Name         : Main.cpp
// Description  : Complex Numbers Main in C++, Ansi-style
//============================================================================
#include "ComplexNumbers.h"

using namespace complexnumbersblock;

int main()
{
    ComplexNumbers c1(3, 4);
    ComplexNumbers c2(2, 3);
    ComplexNumbers c3 = c1 + c2;
    cout << c1 << endl;
    cout << c1 + c2 + c3<< endl;
    ComplexNumbers c4(4, 2);
    ComplexNumbers c5 = c4 + 7;
    cout << c5 << endl;
    ComplexNumbers c6(1, 7);
    cout << 3.2 + c6 << endl;
    return 0;
}
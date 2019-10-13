//============================================================================
// Name         : Main.cpp
// Description  : Complex Numbers Main in C++, Ansi-style
//============================================================================
#include "ComplexNumbers.h"

using namespace complexnumbersblock;

int main()
{
    ComplexNumbers c1(2, 3);
    ComplexNumbers c4(c1);
    ComplexNumbers c2 = c1;
    ComplexNumbers c3 = c2;
    cout << c1 << ": " << c3 << ": " << c4 << endl;
    return 0;
}
//============================================================================
// Name         : Main.cpp
// Description  : Complex Numbers Main in C++, Ansi-style
//============================================================================
#include "ComplexNumbers.h"

using namespace complexnumbersblock;

int main()
{
    ComplexNumbers c1(3, 4);
    ComplexNumbers c2(3, 4);

    if (c1 == c2)
    {
        cout << "Equals" << endl;
    } else {
        cout << "Not equals" << endl;
    }

    if (c1 != c2)
    {
        cout << "Not Equals" << endl;
    } else {
        cout << "Equals" << endl;
    }
    return 0;
}
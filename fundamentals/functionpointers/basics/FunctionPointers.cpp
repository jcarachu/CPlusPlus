//============================================================================
// Name         : FunctionPointers.cpp
// Description  : Function Pointers in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;

void test1()
{
    cout << "Hello" << endl;
}

void test2(int value)
{
    cout << "Hello " << value << endl;
}

int main()
{
    test1();

    void (*pTest1)();
    pTest1 = &test1;
    (*pTest1)();

    void (*pTest2)();
    pTest2 = test1;
    pTest2();

    void (*pTest3)() = test1;
    pTest3();

    void (*pTest4)(int) = test2;
    pTest4(5);

    return 0;
}
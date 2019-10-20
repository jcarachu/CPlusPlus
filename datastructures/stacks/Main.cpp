//============================================================================
// Name         : Main.cpp
// Description  : Main in C++, Ansi-style
//============================================================================
#include "StackLinkedEx.h"
using namespace std;

int main ()
{
    StackLinked<int> stack(5);
    stack.push(5);
    stack.push(4);
    stack.push(3);
    stack.push(2);
    stack.push(1);

    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    
    return 0;
}
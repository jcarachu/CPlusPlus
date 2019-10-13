//============================================================================
// Name         : TypeInference.cpp
// Description  : Template Type Inference in C++, Ansi-style
//============================================================================
#include "TypeInference.h"

void print(int value)
{
    cout << "Non-template version: " << value << endl;
}
int main()
{
    print<string>("string");
    print<int>(5);
    print("Hi there");
    print<>(6);
    show<double>();
    return 0;
}
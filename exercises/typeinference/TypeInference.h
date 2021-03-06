//============================================================================
// Name         : TypeInference.cpp
// Description  : Template Type Inference in C++, Ansi-style
//============================================================================
#ifndef TEMPLATE_CLASSES_H_
#define TEMPLATE_CLASSES_H_
#include <iostream>
using namespace std;

template<class T>
void print(T n)
{
    cout << "Template version: " << n << endl;
}

template<class T>
void show()
{
    cout << T() << endl;
}
#endif
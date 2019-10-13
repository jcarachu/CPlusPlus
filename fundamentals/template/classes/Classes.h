//============================================================================
// Name         : Classes.cpp
// Description  : Template Classes in C++, Ansi-style
//============================================================================
#ifndef TEMPLATE_CLASSES_H_
#define TEMPLATE_CLASSES_H_
#include <iostream>
using namespace std;

template<class T>
class Test {
    private:
        T obj;
    
    public:
        Test(T obj)
        {
            this-> obj = obj;
        }

        void print()
        {
            cout << obj << endl;
        }
};

#endif
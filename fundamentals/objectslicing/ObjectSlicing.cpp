//============================================================================
// Name         : ObjectSlicing.cpp
// Description  : Object Slicing with Function Pointers in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;

class Parent {
    private:
        int one;

    public:
        Parent():
        one(0){}

        Parent(const Parent &other):
        one(0)
        {
            cout << "Copy Parent" << endl;
        }

        virtual void print()
        {
            cout << "parent" << endl;
        }

        virtual ~Parent() {}
};

class Child: public Parent {
    private:
        int two;

    public:
        Child():
        two(0) {}

        void print()
        {
            cout << "child" << endl;
        }
};

int main()
{
    Child c1;
    Parent &p1 = c1;
    p1.print();

    // Object slicing: Upcasting
    Parent p2 = Child();
    p2.print();
    return 0;
}
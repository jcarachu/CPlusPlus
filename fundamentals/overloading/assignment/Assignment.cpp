//============================================================================
// Name         : Assignment.cpp
// Description  : Assignment Overloading in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;

class Test {
    private:
        int id;
        string name;
    
    public:
        Test():
        id(0), name("") {}

        Test(int id, string name):
        id(id), name(name) {}

        Test(const Test &other)
        {
            cout << "Copy constructor running" << endl;
            id = other.id;
            name = other.name;
        }

        void print()
        {
            cout << id << ": " << name << flush;
        }

        const Test &operator=(const Test &other)
        {
            cout << "Assignment running" << endl;
            id = other.id;
            name = other.name;

            return *this;
        }
};

int main()
{
    Test test1(10, "Mike");
    test1.print();

    Test test2(20, "Bob");
    test2 = test1;
    test2.print();

    Test test3;
    test3 = test2 = test1;
    test3.operator=(test2);
    cout << "Print test3: " << flush;
    test3.print();
    cout << endl;
    
    Test test4 = test1;
    test4.print();
    cout << endl;

    return 0;
}
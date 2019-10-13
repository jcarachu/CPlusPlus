//============================================================================
// Name         : Insertion.cpp
// Description  : Overloading the Insertion Operator in C++, Ansi-style
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

        const Test &operator=(const Test &other)
        {
            cout << "Assignment running" << endl;
            id = other.id;
            name = other.name;

            return *this;
        }

        friend ostream &operator<<(ostream &out, const Test &test) 
        {
            out << test.id << ": " << test.name;
            return out;
        }
};


int main()
{
    Test test1(10, "Mike");
    Test test2(20, "Bob");
    cout << test1 << endl;
    cout << test2 << endl;
    int value = 1 + (2 + 5);
    return 0;
}
//============================================================================
// Name         : Stacks.cpp
// Description  : Stacks in C++, Ansi-style
//============================================================================
#include <iostream>
#include <stack>
using namespace std;

class Test {
    private:
        string name;
    
    public:
        Test(string name)
        : name(name) {}
    
        ~Test() 
        {
            //cout << "Object destroyed" << endl;
        }

        void print()
        {
            cout << name << endl;
        }
};

int main()
{
    // LIFO 
    stack<Test> teststack;
    int count = 0;
    teststack.push(Test("Mike"));
    teststack.push(Test("John"));
    teststack.push(Test("Sue"));

    cout << "+++++ Iteration " << count++ << " +++++" << endl;
    Test &test1 = teststack.top();
    test1.print();

    teststack.pop();
    Test &test2 = teststack.top();
    test2.print();

    cout << "+++++ Iteration " << count++ << " +++++" << endl;
    while(teststack.size() > 0)
    {
        Test &test2 = teststack.top();
        test2.print();
        teststack.pop();
    }

    return 0;
}
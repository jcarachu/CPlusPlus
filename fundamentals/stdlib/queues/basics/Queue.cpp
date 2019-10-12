//============================================================================
// Name         : Queue.cpp
// Description  : Queue in C++, Ansi-style
//============================================================================
#include <iostream>
#include <queue>
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
    // FIFO
    queue<Test> testqueue;
    int count = 0; 
    testqueue.push(Test("Mike"));
    testqueue.push(Test("John"));
    testqueue.push(Test("Sue"));

    cout << "+++++ Iteration " << count++ << " +++++" << endl;
    Test &test1 = testqueue.front();
    test1.print();

    testqueue.pop();
    Test &test2 = testqueue.front();
    test2.print();

    cout << "+++++ Iteration " << count++ << " +++++" << endl;
    testqueue.back().print();
    
    cout << "+++++ Iteration " << count++ << " +++++" << endl;
    while(testqueue.size() > 0)
    {
        Test &test2 = testqueue.front();
        test2.print();
        testqueue.pop();
    }

    return 0;
}
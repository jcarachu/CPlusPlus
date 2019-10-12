//============================================================================
// Name         : Maps.cpp
// Description  : Maps in C++, Ansi-style
//============================================================================
#include <iostream>
#include <set>
using namespace std;

class Test {
    int id;
    string name;

    public:
        Test(int id, string name)
        : id(id), name(name) {}

        Test()
        : id(0), name("") {}

        void print() const
        {
            cout << id << ": " << name << endl;
        }  

        bool operator<(const Test &other) const
        {
            return name < other.name;
        }

};

int main ()
{
    set<int> numbers;
    int count = 0;
    numbers.insert(50);
    numbers.insert(10);
    numbers.insert(30);
    numbers.insert(30);
    numbers.insert(20);

    cout << "+++++ Iteration " << count++ << "+++++" << endl;
    for (set<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
    {
        cout << *it << endl;
    }

    set<int>::iterator itfind = numbers.find(30);

    if(itfind != numbers.end())
        cout << "Found" << *itfind << endl;
    
    if (numbers.count(30))
        cout << "Number found." << endl;

    set<Test> tests;
    tests.insert(Test(10, "Mike"));
    tests.insert(Test(30, "Joe"));
    tests.insert(Test(333, "Joe"));
    tests.insert(Test(20, "Sue"));

    cout << "+++++ Iteration " << count++ << "+++++" << endl;
    for (set<Test>::iterator it = tests.begin(); it != tests.end(); it++)
    {
        it->print();
    }

    return 0;
}
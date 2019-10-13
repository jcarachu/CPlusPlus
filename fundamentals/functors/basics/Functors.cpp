//============================================================================
// Name         : Functors.cpp
// Description  : Functors in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;

struct Test {
    virtual bool operator()(string &text)=0;

    virtual ~Test(){};
}; 

struct MatchTest: Test {
    virtual bool operator()(string &text)
    {
        return text == "lion";
    }
};

void check(string text, Test &test)
{
    if (test(text))
    {
        cout << "Test matches!" << endl;
    } else
    {
        cout << "No match." << endl;
    }
    
}

int main()
{
    MatchTest pred;
    string value = "lion";
    cout << pred(value) << endl;
    MatchTest m;
    check(value, m);
    return 0;
}
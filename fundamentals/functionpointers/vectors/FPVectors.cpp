//============================================================================
// Name         : FPVectors.cpp
// Description  : Function Pointers with vectors in C++, Ansi-style
//============================================================================
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool match(string test)
{
    return test.size() == 3;
}

int countstrings(vector<string> &texts, bool (*match)(string test))
{
    int tally = 0;
    for (int i = 0; i < texts.size(); i++)
    {
        if (match(texts[i]))
        {
            tally++;
        }
    }
    return tally;
}

int main()
{
    vector<string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("two");
    texts.push_back("four");
    texts.push_back("two");
    texts.push_back("three");

    cout << match("one") << endl;
    cout << match("oned") << endl;
    cout << count_if(texts.begin(), texts.end(), match) << endl;
    cout << countstrings(texts, match) << endl;
    return 0;
}
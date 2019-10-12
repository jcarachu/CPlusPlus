//============================================================================
// Name         : Parse.cpp
// Description  : Parse text in C++, Ansi-style
//============================================================================
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string filename = "Stats.txt";
    ifstream input;

    input.open(filename);
    if (!input.is_open())
    {
        return 1;
    }

    while (input)
    {
        string line;
        string population;
        getline(input, line, ':');
        getline(input, population, '\n');
        if (!input)
            break;
        
        cout << "'" << line << "'" << " -- " << population << "'" << endl;
    }

    input.close();
    return 0;
}
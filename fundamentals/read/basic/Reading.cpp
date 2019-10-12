//============================================================================
// Name         : Reading.cpp
// Description  : Writing to Files in C++, Ansi-style
//============================================================================
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string infilename = "Test.txt";
    ifstream infile;
    infile.open(infilename);
    if (infile.is_open())
    {
        string line;
        while (infile)
        {
            getline(infile, line);
            cout << line << endl;
        }

        infile.close();
    } else {
        cout << "Cannot open file: " << infilename << endl;
    }

    return 0;
}
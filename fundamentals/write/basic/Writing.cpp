//============================================================================
// Name         : Writing.cpp
// Description  : Writing to Files in C++, Ansi-style
//============================================================================
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // ofstream outfile;
    fstream outfile;
    string outputfilename = "text.txt";

    outfile.open(outputfilename, ios::out);
    if (outfile.is_open())
    {
        outfile << "Hello there" << endl;
        outfile << 123 << endl;
        outfile.close();
    } else {
        cout << "Could not create file: " << outputfilename << endl;
    }

    return 0;

}
//============================================================================
// Name         : Binary.cpp
// Description  : Binary to struct in C++, Ansi-style
//============================================================================
#include <iostream>
#include <fstream>
using namespace std;

#pragma pack(push, 1)
struct Person {
    char name[50];
    int age;
    double height;
};
#pragma pack(pop)

int main()
{
    Person someone = {"Frodo", 220, 0.8};
    string filename = "Test.bin";

    ///// Write Binary File /////
    ofstream outputfile;
    outputfile.open(filename,ios::binary);
    if (outputfile.is_open())
    {
        outputfile.write(reinterpret_cast<char *>(&someone), sizeof(Person));
        outputfile.close();
    } else {
        cout << "Could not create file " + filename << endl;
    }

    ///// Read Binary File /////
    Person someonelse = {};
    ifstream inputfile;
    inputfile.open(filename,ios::binary);
    if (inputfile.is_open())
    {
        inputfile.read(reinterpret_cast<char *>(&someonelse), sizeof(Person));
        inputfile.close();
    } else {
        cout << "Could not create file " + filename << endl;
    }

    cout << someonelse.name << ", " << someonelse.age << ", " << someonelse.height << endl;

    return 0;
}
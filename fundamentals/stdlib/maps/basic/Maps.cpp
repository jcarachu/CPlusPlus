//============================================================================
// Name         : Maps.cpp
// Description  : Maps in C++, Ansi-style
//============================================================================
#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> ages;
    ages["Mike"] = 40;
    ages["Raj"] = 20;
    ages["Vicky"] = 30;
    ages["Mike"] = 70; // Valid, but OVERWRITES original values

    pair<string, int> addtomap("Peter",100);
    ages.insert(addtomap);
    ages.insert(pair<string, int> ("Joe", 50));
    ages.insert(make_pair("Victor", 90));
    cout << ages["Raj"] << endl;
    cout << ages["Sue"] << endl; // Valid, if does not exist adds a null value and adds it to the map
    
    if (ages.find("Vicky1") != ages.end())
    {
        cout << "Found Vicky" << endl;
    } else {
        cout << "Key not found" << endl;
    }

    cout << "+++++ Iterator 1 +++++" << endl;
    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }

    cout << "+++++ Iterator 2 +++++" << endl;
    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
    {
        pair<string, int> age = *it;
        cout << age.first << ": " << age.second << endl;
    }

    return 0;
}
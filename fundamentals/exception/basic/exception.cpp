//============================================================================
// Name         : Basic.cpp
// Description  : Exceptions in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;

void mightGoWrong()
{
    bool error1 = false;
    bool error2 = true;

    if (error1)
    {
        throw "Something went wrong.";
    }

    if (error2)
    {
        throw string("Something else went wrong.");
    }
}

void usesMightWrong()
{
    mightGoWrong();
}

int main()
{
    try {
        usesMightWrong();
    } catch (int e) {
        cout << "Error code: " << e << endl;
    } catch (char const * e) {
        cout << "Error message: " << e << endl;
    } catch (string &e) {
        cout << "String Error message" << e << endl;
    }

    cout << "Done. " << endl;
    
    return 0;
}


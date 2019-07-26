#include <iostream>
using namespace std;

/* Smart Pointers */

/*
    - Smart Pointer is a weapper class over a pointer with operator like '*' and '->' overloaded.
    - The objects of smart pointer class look like pointer
        but can do many things that a normal pointer:
        * Automatic descruction
        * Reference counting and more
*/

class SmartPtr
{
private:
    int *ptr;

public:
    // Constructor
    explicit SmartPtr(int *p = NULL) { ptr = p; }

    // Destructor
    ~SmartPtr() { delete(ptr); }

    // Overloading dereferencing operator
    int &operator *() { return *ptr; }
    
};

int main(int argc, char const *argv[])
{
    /* code */
    SmartPtr ptr(new int());
    *ptr = 20;
    cout << *ptr << endl;
    // We don't need to call delete
    //  * When the object ptr goes out of scope
    //    deconstructor will be automatically called.
    return 0;
}

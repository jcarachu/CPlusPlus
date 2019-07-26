#include <stdio.h>
#include <iostream>
using namespace std;

/* NOTES */
// Circumferences is a virtual function in the Shape class
// It becomes virtual in each of the derived class.
// C++ non virtual function calls are resolved at compile time with static binding
// While virtual function calls are resolved at runtime with dynamic binding.
 
class Shape
{
    public:
        int edge_length;
        virtual int circumference()
        {
            cout << "Circumference of Base Class\n";
            return 0;
        }
};

class Triangle: public Shape
{
    public:
        int circumference()
        {
            cout << "Circumferenece of Triangle Class\n";
            return 3 * edge_length;
        }
};

int main(int argc, char const *argv[])
{
    /* code */
    Shape *x = new Shape();
    x->circumference(); // "Circumference of Base Class"
    Shape *y = new Triangle();
    y->circumference(); // "Circumference of Triangle Class"
    return 0;
}
//============================================================================
// Name         : Abstract.cpp
// Description  : Abstract Objects in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;

class Animal {
    public:
        virtual void speak() = 0;
        virtual void run() = 0;

};

class Dog: public Animal {
    public:
        virtual void speak()
        {
            cout << "Woof!" << endl;
        }

};

class Labrador: public Dog {
    public:
        virtual void run()
        {
            cout << "Labrador running" << endl;
        }
};

void test(Animal &a)
{
    a.run();
}

int main()
{
    Labrador lab;
    lab.speak();
    lab.run();

    Animal *animals[5];
    animals[0] = &lab;
    animals[0]->speak();
    
    test(lab);
    return 0;
}
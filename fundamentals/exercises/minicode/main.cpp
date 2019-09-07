#include <stdio.h>
#include <iostream>
#define NAME_SIZE 50 // Defines a macro

using namespace std;

class Person{
    
    int id; // all members are private by default
    char name[NAME_SIZE];

    public: 
        virtual void aboutMe(){
            printf("I am a person.\n");
        }
        virtual bool addCourse(string s) = 0;

        virtual ~ Person(){
            printf("Person deconstructor is called.\n");
        }
};

class Student: public Person {
    public:
        void aboutMe(){
            printf("I am a student.\n");
        }
        bool addCourse(string s){
            printf("Added course %s to student.\n", s.c_str());
            return true;
        }
        ~ Student(){
            printf("Student deconstructor is called\n");
        }
};

int main(int argc, char const *argv[])
{
    /* code */
    Person *p = new Student();
    p-> aboutMe(); // prints "I am a student."
    p-> addCourse("History");
    delete p; // IMPORTANT! Make sure to delete allocated memory.

}

//============================================================================
// Name         : Stack.h
// Description  : Stack in C++, Ansi-style
//============================================================================
#ifndef STACK_BASE_H_
#define STACK_BASE_H_
#include <stdexcept>
#include <iostream>
using namespace std;

template<typename T>
class StackBase {
    public:
        static const int MAX_STACK_SIZE = 8;
        virtual ~StackBase() = 0;
        virtual void push(const T &data) = 0;
        virtual T pop() = 0;
        virtual void clear() = 0;
        virtual bool isEmpty() const = 0;
        virtual bool isFull() const = 0;
};

#endif
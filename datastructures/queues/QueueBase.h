//============================================================================
// Name         : Queue.h
// Description  : Queue in C++, Ansi-style
//============================================================================
#ifndef QUEUE_BASE_H_
#define QUEUE_BASE_H_
#include <stdexcept>
#include <iostream>
using namespace std;

template<typename T>
class QueueBase {
    public:
        static const int MAX_QUEUE_SIZE = 8;
        virtual ~QueueBase() = 0;
        virtual void enqueue(const T &data) = 0;
        virtual T dequeue() = 0;
        virtual void clear() = 0;
        virtual bool isEmpty() const = 0;
        virtual bool isFull() const = 0;
};

#endif
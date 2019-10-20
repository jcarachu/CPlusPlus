//============================================================================
// Name         : StackLinked.h
// Description  : Stack Linked List Implementation in C++, Ansi-style
//============================================================================
#ifndef STACK_LINKED_H_
#define STACK_LINKED_H_
#include "StackBase.h"
using namespace std;

template<typename T>
class StackLinked: public StackBase<T>{
    public:
        StackLinked(int maxNumber = StackBase<T>::MAX_STACK_SIZE);
        StackLinked(const StackLinked &other);
        ~StackLinked();
        StackLinked &operator=(const StackLinked &other);
        
        void clear();
        bool isEmpty() const;
        bool isFull() const;
        void push(const T &data);
        T pop();

    private:
        struct Node {
            Node(const T &data, Node *next);
            T data;
            Node *next;
        };

        Node *head;
        Node *tail;
};

#endif
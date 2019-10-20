//============================================================================
// Name         : QueueLinked.h
// Description  : Queue Linked List Implementation in C++, Ansi-style
//============================================================================
#ifndef QUEUE_LINKED_H_
#define QUEUE_LINKED_H_
#include "QueueBase.h"
using namespace std;

template<typename T>
class QueueLinked: public Queue<T>{
    public:
        QueueLinked(int maxNumber = Queue<T>::MAX_QUEUE_SIZE);
        QueueLinked(const QueueLinked &other);
        ~QueueLinked();
        QueueLinked &operator=(const QueueLinked &other);
        
        void clear();
        bool isEmpty() const;
        bool isFull() const;
        void enqueue(const T &data);
        T dequeue();

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
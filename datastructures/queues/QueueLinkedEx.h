//============================================================================
// Name         : QueueLinked.cpp
// Description  : Queue Linked List Implementation in C++, Ansi-style
//============================================================================
#ifndef QUEUE_LINKED_EX_
#define QUEUE_LINKED_EX_
#include "QueueLinked.h"
using namespace std;

/*
 * The default constructor
 * that creates an empty Queue. Will allocate neough memory for the Queue
 * containing maxNumber data items (if necessary.)
 */
template<typename T>
QueueLinked<T>::QueueLinked(int maxNumber)
{
    head = tail = NULL;
}

/* 
 * The copy constructor
 * that initializes the Queue to be equivalent to the other Queue object
 * parameter.
 */
template<typename T>
QueueLinked<T>::QueueLinked(const QueueLinked &other)
{
    head = tail = NULL;
    this = other;
}

/*
 * The overloaded assignment operator
 * that sets the Queue to be equivalent to the other Queue object parameter and
 * returns a reference to the modified Queue.
 */
template<typename T>
QueueLinked<T>&QueueLinked<T>::operator=(const QueueLinked<T> &other)
{
    clear();
    Node *temp = other.head;
    while(temp != NULL)
    {
        insert(temp->T);
        temp = temp->next;
    }

    return *this;
}

/*
 * The destructor
 * that deallocates the memory used to store the Queue.
 */
template<typename T>
QueueLinked<T>::~QueueLinked()
{
    clear();
}

/*
 * The destructor
 * that deallocates the memory used to store the Queue.
 */
template<typename T>
QueueBase<T>::~QueueBase() {}

/*
 * Inserts newDataItem
 * at the rear of the Queue.
 */
template<typename T>
void QueueLinked<T>::enqueue(const T &data)
{
    if (!isFull())
    {
        if (!isEmpty())
            tail = tail->next = new Node(data, NULL);
        else
            head = tail = new Node(data, NULL);
    } else
        throw logic_error("enqueue() while queue is full");
}
/*
 * Removes the data item
 * that was least recently added from the Queue and returns it.
 */
template<typename T>
T QueueLinked<T>::dequeue()
{
    if (!isEmpty())
    {
        Node *temp = head->next;
        T tempdata = head->data;
        delete head;
        head = temp;
        return tempdata;
    } else
        throw logic_error("dequeue() while queue is empty");

    return (T) NULL;
}

/*
 * Removes all data items in the Queue.
 * It will deallocate memory used for the nodes to store the data. Accomplishes
 * this by iterating with dequeue().
 */
template<typename T>
void QueueLinked<T>::clear()
{
    while (head != NULL)
        dequeue();
    
    head = tail = NULL;
}

/*
 * Returns true if the Queue is empty
 * Otherwise, returns false.
 */
template<typename T>
bool QueueLinked<T>::isEmpty() const
{
    if (head == NULL)
        return true;
    else
        return false;
}

/*
 * Returns true if the Queue is full.
 * Otherwise, returns false.
 */
template<typename T>
bool QueueLinked<T>::isFull() const
{
    return false;
}

/*
 * The parameterized constructor
 * that sets the Node's data item to the value data and the Node
 * next pointer to the value of Next
 */
template<typename T>
QueueLinked<T>::Node::Node(const T &data, Node *next)
{
    this->data = data;
    this->next = next;
}

#endif
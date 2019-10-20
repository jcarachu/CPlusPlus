//============================================================================
// Name         : StackLinked.cpp
// Description  : Stack Linked List Implementation in C++, Ansi-style
//============================================================================
#ifndef STACK_LINKED_EX_
#define STACK_LINKED_EX_
#include "StackLinked.h"
using namespace std;

/*
 * The parameterized constructor
 * that sets the Node's data item to the value data and the Node
 * next pointer to the value of Next
 */
template<typename T>
StackLinked<T>::Node::Node(const T &data, Node *next)
{
    this->data = data;
    this->next = next;
}

/*
 * The default constructor
 * that creates an empty Stack. Will allocate neough memory for the Stack
 * containing maxNumber data items (if necessary.)
 */
template<typename T>
StackLinked<T>::StackLinked(int maxNumber)
{
    head = tail = NULL;
}

/* 
 * The copy constructor
 * that initializes the Stack to be equivalent to the other Stack object
 * parameter.
 */
template<typename T>
StackLinked<T>::StackLinked(const StackLinked &other)
{
    head = tail = NULL;
    this = other;
}

/*
 * The overloaded assignment operator
 * that sets the Stack to be equivalent to the other Stack object parameter and
 * returns a reference to the modified Stack.
 */
template<typename T>
StackLinked<T>&StackLinked<T>::operator=(const StackLinked<T> &other)
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
 * that deallocates the memory used to store the Stack.
 */
template<typename T>
StackLinked<T>::~StackLinked()
{
    clear();
}

/*
 * The destructor
 * that deallocates the memory used to store the Stack.
 */
template<typename T>
StackBase<T>::~StackBase() {}

/*
 * Inserts newDataItem
 * at the front of the Stack.
 */
template<typename T>
void StackLinked<T>::push(const T &data)
{
    if (!isFull())
    {
        if (!isEmpty())
            head = new Node(data,head);
        else
            head = tail = new Node(data, NULL);
    } else
        throw logic_error("pop() while stack is full");
}
/*
 * Removes the data item
 * that was recently added to the Stack and returns it.
 */
template<typename T>
T StackLinked<T>::pop()
{
    if (!isEmpty())
    {
        Node *temp = head->next;
        T tempdata = head->data;
        delete head;
        head = temp;
        return tempdata;
    } else
        throw logic_error("pop() while pop is empty");

    return (T) NULL;
}

/*
 * Removes all data items in the Stack.
 * It will deallocate memory used for the nodes to store the data. Accomplishes
 * this by iterating with dequeue().
 */
template<typename T>
void StackLinked<T>::clear()
{
    while (head != NULL)
        pop();
    
    head = tail = NULL;
}

/*
 * Returns true if the Stack is empty
 * Otherwise, returns false.
 */
template<typename T>
bool StackLinked<T>::isEmpty() const
{
    if (head == NULL)
        return true;
    else
        return false;
}

/*
 * Returns true if the Stack is full.
 * Otherwise, returns false.
 */
template<typename T>
bool StackLinked<T>::isFull() const
{
    return false;
}

#endif
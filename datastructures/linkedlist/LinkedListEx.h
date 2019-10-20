#ifndef LINKED_LIST_EX_H_
#define LINKED_LIST_EX_H_
#include "LinkedList.h"
using namespace std;

template<class T>
LinkedList<T>::Node::Node(const T &data, Node *next)
{
    this->data = data;
    this->next = next;
}

template<class T>
LinkedList<T>::LinkedList(int ignored)
{
    head = current = NULL;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList &other)
{
    head = current = NULL;
    Node *temp = other.head;
    while(temp != NULL)
    {
        insert(temp->data);
        temp = temp->next;
    }
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList &other)
{
    clear();
    Node *temp = other.head;
    while (temp != NULL)
    {
        insert(temp->data);
        temp = temp->next;
    }
    
    return *this;
}

template<class T>
LinkedList<T>:: ~LinkedList()
{
    clear();
}

template<class T>
void LinkedList<T>::insert(const T &data)
{
    if (!isFull())
    {
        if (!isEmpty())
        {
            current->next = new Node(data, current->next);
            current = current->next;
        }
        else
        {
            head = new Node(data, NULL);
            current = head;
        }
    }
}

template<class T>
void LinkedList<T>::remove()
{
    if (!isEmpty())
    {
        Node *temp = current->next;
        gotoPrior();
        if (current->next == temp)
        {
            delete current;
            head = temp;
        }
        else
        {
            delete current->next;
        }

        current->next = temp;
        current = temp;
        if (current == NULL)
        {
            gotoBeginning();
        }
    }
}

template<class T>
void LinkedList<T>::replace(const T &data)
{
    if (!isEmpty())
    {
        current->data = data;
    }
}

template<class T>
void LinkedList<T>::clear()
{
    while (current != NULL)
        remove();

    head = current = NULL;
}

template<class T>
bool LinkedList<T>::isEmpty() const
{
    if (head == NULL)
        return true;
    else
        return false;
}

template<class T>
bool LinkedList<T>::isFull() const
{
    return false;
}

template<class T>
void LinkedList<T>::gotoBeginning()
{
    if(!isEmpty())
        current = head;
}

template<class T>
void LinkedList<T>::gotoEnd()
{
    if (!isEmpty())
        while (gotoNext());
}

template<class T>
bool LinkedList<T>::gotoNext()
{
    if (!isEmpty())
    {
        if (current->next != NULL)
        {
            current = current->next;
            return true;
        }
    }

    return false;
}

template<class T>
bool LinkedList<T>::gotoPrior()
{
    if (!isEmpty())
    {
        if (current != head)
        {
            Node *temp = current;
            current = head;
            while (current->next != temp)
                gotoNext();
        }
        else
            return true;
    }

    return true;
}

template<class T>
T LinkedList<T>::getCurrent() const
{
    if (!isEmpty())
        return current->data;
    return (T) NULL;
}

template<class T>
void LinkedList<T>::showStructure() const
{
    if (isEmpty())
    {
        cout << "Empty List" << endl;
    }
    else
    {   
        
        for (Node *temp = head; temp != 0; temp = temp->next)
        {
            if (temp == current)
            {
                cout << "[";
            }
            
            cout << temp->data;

            if (temp == current)
            {
                cout << "]";
            }
        }

        cout << endl;
    }
}

#endif
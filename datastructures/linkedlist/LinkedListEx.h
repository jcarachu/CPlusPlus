#ifndef LINKED_LIST_EX_H_
#define LINKED_LIST_EX_H_
#include "LinkedList.h"
using namespace std;

/* The parameterized constructor
 * that sets the Node's data item to the value node and the List Node's
 * next pointer to the value of next pointer.
 */
template<class T>
LinkedList<T>::Node::Node(const T &data, Node *next)
{
    this->data = data;
    this->next = next;
}

/* The default constructor
 * that creates an empty List.
 */
template<class T>
LinkedList<T>::LinkedList(int ignored)
{
    head = current = NULL;
}

/* The copy constructor
 * that initializes the List to be equivalent to the other List.
 */
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

/* The overloaded assignment operator
 * that sets the List to be equivalent to the other List and returns a reference
 */
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

/* The destructor
 * that deallocates the memory used to store the nodes in the List.
 */
template<class T>
LinkedList<T>:: ~LinkedList()
{
    clear();
}

/* Inserts newDataItem into the List.
 * If the List is not empty, then inserts newDataItem after the current.
 * Otherwise, inserts newDataItem as the first (and only) data item in the List.
 * In either case, moves the current to newDataItem.
 */
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

/* Removes the data item marked by the current
 * from the List. If the resulting List is not empty, then moves the current to
 * the data item that followed the deleted data item. If the deleted data item
 * was at the end of the List, then moves the current to the beginning of the
 * List.
 */
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

/* Replaces the data item marked by the current
 * with newDataItem. The current remains at newDataItem.
 */
template<class T>
void LinkedList<T>::replace(const T &data)
{
    if (!isEmpty())
    {
        current->data = data;
    }
}

/* Removes all the data items in the List.
 * Will deallocate memory used for the nodes to store the data.
 */
template<class T>
void LinkedList<T>::clear()
{
    while (current != NULL)
        remove();

    head = current = NULL;
}

/* Returns true if the List is empty.
 * Otherwise, returns false.
 */
template<class T>
bool LinkedList<T>::isEmpty() const
{
    if (head == NULL)
        return true;
    else
        return false;
}

/* Returns true if the List is full.
 * Otherwise, returns false.
 */
template<class T>
bool LinkedList<T>::isFull() const
{
    return false;
}

/* Moves the current to the beginning
 * of the List.
 */
template<class T>
void LinkedList<T>::gotoBeginning()
{
    if(!isEmpty())
        current = head;
}

/* Moves the current to the end
 * of the List.
 */
template<class T>
void LinkedList<T>::gotoEnd()
{
    if (!isEmpty())
        while (gotoNext());
}

/* Moves the current the next data item.
 * If the current is not at the end of the List, the current moves to the next
 * data item and returns true. Otherwise, returns false. 
 */
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

/* Moves the current to the preceding data item.
 * If the current is not at the beginning of the List, the current moves to the
 * preceding data item and returns true. Otherwise, returns false.
 */
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

/* Returns the value of the data item
 * marked by the current.
 */
template<class T>
T LinkedList<T>::getCurrent() const
{
    if (!isEmpty())
        return current->data;
    return (T) NULL;
}

/* Outputs the items in a List.
 * If the List is empty, outputs "Empty list." This operation is intended for
 * testing and debugging purposes only.
 */
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
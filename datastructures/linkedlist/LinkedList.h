//============================================================================
// Name         : LinkedList.h
// Description  : LinkedList in C++, Ansi-style
//============================================================================
#ifndef LIST_H_
#define LIST_H_
#include <assert.h>
#include <memory>

template<typename T>
class LinkedList {

    public:
        struct Node {
            T data;
            Node *next;

            Node(T data, Node* next)
            : data(data), next(next) {}

            ~Node() {}
        };

        LinkedList();

        ~LinkedList();

        void Append(T data);

        void Prepend(T data);

        typedef void (*Callback)(Node *node);

        void Traverse(Callback callback);
    
    private:
        Node *head;
        Node *current;

};

template<typename T>
LinkedList<T>::LinkedList()
: current(nullptr), head(nullptr) {}

template<typename T>
LinkedList<T>::~LinkedList()
{
    for (current = head; current != nullptr;)
    {
        std::unique_ptr<Node> autoRelease(current);
        current = current->next;
    }
}

template<typename T>
void LinkedList<T>::Append(T data)
{
    Node *n = new Node(data, nullptr);
   
    if (!head)
    {
        assert(!current);
        head = n;
    } else { 
        assert(current);
        current->next = n;
    }

    current = n;
}

template<typename T>
void LinkedList<T>::Prepend(T data)
{
    Node *n = new Node(data, head);
    head = n;
    if (!current)
        current = n;
}

template<typename T>
void LinkedList<T>::Traverse(Callback callback)
{
    for (Node* cur = head; cur != nullptr; cur = cur->next)
    {
        callback(cur);
    }
}
#endif // LIST_H_
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class LinkedList {
    
    private:
        class Node {
            public:
                Node(const T &data, Node *next);
                T data;
                Node *next;
        };

        Node *head;
        Node *current;

    public:
        LinkedList(int ignored = 0);
        LinkedList(const LinkedList &other);
        LinkedList &operator=(const LinkedList &other);
        ~LinkedList();

        void insert(const T &data);
        void remove();
        void replace(const T &data);
        void clear();

        bool isEmpty() const;
        bool isFull() const;

        void gotoBeginning();
        void gotoEnd();
        bool gotoNext();
        bool gotoPrior();

        void showStructure() const;
        T getCurrent() const;
    
};

#endif
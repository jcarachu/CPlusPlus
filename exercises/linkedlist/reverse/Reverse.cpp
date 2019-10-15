#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

struct LinkedList {
    Node *head;
    LinkedList()
    {
        head = NULL;
    }

    void reverse()
    {
        Node *current = head;
        Node *prev = NULL;
        Node *next = NULL;
        
        while (current != NULL)
        {   
            // store next
            next = current->next;
            // reverse current node pointer
            current->next = prev;
            // move pointers one position
            prev = current;

            current = next;
        }

        head = prev;
    }

    void print()
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
        }
    }

    void push (int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

int main()
{
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);

    cout << "Give linked list\n";
    ll.print();
    ll.reverse();
    
    cout << "\nReverse Linked List\n";
    ll.print();
    return 0;
}
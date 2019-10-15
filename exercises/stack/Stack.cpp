#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;
void push(int val)
{
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node->data = val;
    node->next = top;
    top = node;
}

void pop()
{
    if (top == NULL)
        cout << "Stack Underflow" << endl;
    
    else {
        cout << "The popped element is " << top->data << endl;
        top = top -> next;
    }
}

void display()
{
    struct Node *node;
    if (top == NULL)
        cout << "stack is empty" << endl;
    
    else {
        node = top;
        cout << "Stack elements are: ";
        while (node != NULL)
        {
            cout << node->data << " ";
            node = node->next;
        }
    }
}

int main()
{
    return 0;
}
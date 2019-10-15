#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void printmiddle(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;
    if (head != NULL)
    {
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        printf("The middle element is[%d]\n\n", slow->data);
    }
}

void push (struct Node **node, int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = (*node);
    (*node) = temp;
}

void printlist(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d->", node->data);
        node = node->next;
    }

    printf("NULL\n");
}


int main()
{
    struct Node *head = NULL;
    for (int i = 5; i > 0; i--)
    {
        push(&head, i);
        printlist(head);
        printmiddle(head);
    }
    
    return 0;
}
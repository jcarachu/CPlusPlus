#include "LinkedListEx.h"
using namespace std;

int main()
{
    LinkedList<int> linkedlist;
    linkedlist.insert(1);
    linkedlist.insert(2);
    linkedlist.insert(3);
    linkedlist.insert(4);
    linkedlist.insert(5);
    linkedlist.showStructure();
    return 0;
}
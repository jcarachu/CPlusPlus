//============================================================================
// Name         : LinkedList.cpp
// Description  : LinkedList in C++, Ansi-style
//============================================================================
#include "LinkedList.h"
#include <iostream>

template<typename T>
void Print(T data, bool breakline)
{
    std::cout << data << ((breakline)? "->" : "\n");
}

void PrintInt(LinkedList<int>::Node *node)
{
    Print(node->data, node->next);
}

void PrintFloat(LinkedList<float>::Node *node)
{
    Print(node->data, node->next);
}

int main()
{
    int dataInt[6] = { 11, 22, 33, 44, 55, 66 };
    float dataFloat[6] = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f };

    LinkedList<int> integerlist;
    integerlist.Prepend(dataInt[0]);
    integerlist.Append(dataInt[1]);
    integerlist.Append(dataInt[2]);
    integerlist.Prepend(dataInt[3]);
    integerlist.Append(dataInt[4]);
    integerlist.Prepend(dataInt[5]);
    integerlist.Traverse(PrintInt);

    LinkedList<float> floatlist;
    floatlist.Prepend(dataFloat[0]);
    floatlist.Append(dataFloat[1]);
    floatlist.Append(dataFloat[2]);
    floatlist.Prepend(dataFloat[3]);
    floatlist.Append(dataFloat[4]);
    floatlist.Prepend(dataFloat[5]);
    floatlist.Traverse(PrintFloat);

    return 0;
}
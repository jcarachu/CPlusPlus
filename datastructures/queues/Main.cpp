//============================================================================
// Name         : Main.cpp
// Description  : Main in C++, Ansi-style
//============================================================================
#include "QueueLinkedTemplate.h"
using namespace std;

int main ()
{
    QueueLinked<int> queue(5);
    queue.enqueue(5);
    queue.enqueue(4);
    queue.enqueue(3);
    queue.enqueue(2);
    queue.enqueue(1);

    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
    
    return 0;
}
#include <iostream>
using namespace std;
#include "08__dynamic_Queue.h"

int main()
{
    QueueUsingArray<int> q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);

    cout << q.front() << endl;

    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;

    cout << q.getSize() << endl;
    
    cout << q.isEmpty() << endl;
return 0;
}
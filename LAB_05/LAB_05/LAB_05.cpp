#include <iostream>
#include "StackARR.h"
#include "StackLL.h"
#include "QueueARR.h"
#include "QueueLL.h"


int main()
{
    QueueLL q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    q.Dequeue();

    std::cout << "Queue after Dequeue:" << std::endl;
    q.PrintQueue();

    q.Clear();

    std::cout << "Queue after Clear:" << std::endl;
    q.PrintQueue();

    return 0;

}

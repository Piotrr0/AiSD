#include "QueueARR.h"

QueueARR::QueueARR(int capacity)
{
	this->capacity = capacity;
	items = new int[this->capacity];
}

bool QueueARR::Empty()
{
	if (size = 0)
		return true;
	return false;
}

bool QueueARR::Full()
{
	if (size == capacity)
		return true;
	return false;
}

void QueueARR::Enqueue(int number)
{
}

int QueueARR::Peek()
{
	if(items != nullptr)
		return items[head];
}

void QueueARR::Dequeue()
{

}

void QueueARR::Clear()
{
}

void QueueARR::PrintQueue()
{
}

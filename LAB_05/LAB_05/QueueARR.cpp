#include "QueueARR.h"
#include <iostream>

QueueARR::QueueARR(int capacity)
{
	this->capacity = capacity;
	items = new int[this->capacity];
	head = -1;
	tail = -1;
	size = 0;
}

bool QueueARR::Empty()
{
	return size == 0;
}

bool QueueARR::Full()
{
	return size == capacity;
}

void QueueARR::Enqueue(int number)
{
	if (!Full())
	{
		if (Empty())
		{
			head = 0;
		}
		tail = (tail + 1) % capacity;
		items[tail] = number;
		size++;
	}
}

int QueueARR::Peek()
{
	if (!Empty())
		return items[head];
	return -1;
}

void QueueARR::Dequeue()
{
	if (!Empty())
	{
		if (head == tail)
		{
			head = -1;
			tail = -1;
		}
		else
		{
			head = (head + 1) % capacity;
		}
		size--;
	}
}

void QueueARR::Clear()
{
	for (int i = 0; i < size; i++)
	{
		items[(head + i) % capacity] = 0;
	}
	head = -1;
	tail = -1;
	size = 0;
}

void QueueARR::PrintQueue()
{
	if (Empty())
	{
		std::cout << "Queue is empty!" << std::endl;
		return;
	}

	int index = head;
	for (int i = 0; i < size; i++)
	{
		std::cout << items[index] << std::endl;
		index = (index + 1) % capacity;
	}
}
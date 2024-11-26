#include "QueueLL.h"
#include <iostream>
#include <stdexcept> // For std::out_of_range exception

QueueLL::QueueLL()
{

}

bool QueueLL::Empty()
{
	return head == nullptr;
}

void QueueLL::Enqueue(int number)
{
	Node* newNode = new Node(number);
	if(Empty())
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
}

int QueueLL::Peek()
{
	if (Empty())
		throw std::out_of_range("Queue is empty");
	return head->val;
}

void QueueLL::Dequeue()
{
	if(!Empty())
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		if (head == nullptr)
		{
			tail = nullptr;
		}
	}
}

void QueueLL::Clear()
{
	Node* node = head;
	while(node)
	{
		Node* nodeNext = node->next;
		delete node;
		node = nodeNext;
	}
	head = nullptr;
	tail = nullptr;
}

void QueueLL::PrintQueue()
{
	Node* node = head;
	while (node != nullptr)
	{
		std::cout << node->val << std::endl;
		node = node->next;
	}
}

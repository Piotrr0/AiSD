#include "LinkedList.h"
#include <iostream>
#include <limits>

LinkedList::LinkedList()
{

}

LinkedList::~LinkedList()
{
	Clear();
}

Node* LinkedList::Append(int number)
{
	Node* newElement = new Node(number);
	newElement->next = nullptr;

	if (tail == nullptr)
	{
		head = newElement;
		tail = newElement;
		head->prev = nullptr;
	}
	else
	{
		tail->next = newElement;
		newElement->prev = tail;
		tail = newElement;
	}
	size++;
	return newElement;
}

Node* LinkedList::Prepend(int number)
{
	Node* newElement = new Node(number);
	newElement->prev = nullptr;

	if (head == nullptr)
	{
		head = newElement;
		tail = newElement;
		newElement->next = nullptr;
	}
	else
	{
		newElement->next = head;
		head->prev = newElement;
		head = newElement;
	}
	size++;
	return newElement;
}

Node* LinkedList::GetNext(Node* element)
{
	if (element)
	{
		return element->next;
	}
	return nullptr;
}

Node* LinkedList::GetPrev(Node* element)
{
	if (element)
	{
		return element->prev;
	}
	return nullptr;
}

int LinkedList::Retrive(Node* element)
{
	if (element)
	{
		return element->val;
	}
	return INT_MIN;
}

Node* LinkedList::Find(int number)
{
	Node* curr = head;
	while (curr->next)
	{
		if (curr->val == number)
			return curr;
		curr = curr->next;
	}
	return nullptr;
}

void LinkedList::Insert(int index, int number)
{
	if (index < 0 || index > size - 1) return;

	Node* newElement = new Node(number);
	if (size == 0)
	{
		head = tail = newElement;
		size++;
		return;
	}
	else if (index == 0)
	{
		Prepend(number);
	}
	else if (index == size - 1)
	{
		Append(number);
	}
	else
	{
		Node* curr = head;
		for (int i = 0; i < index - 1; i++)
		{
			curr = curr->next;
		}

		newElement->next = curr->next;
		newElement->prev = curr;

		curr->next->prev = newElement;
		curr->next = newElement;
		size++;
	}
}

void LinkedList::Delete(Node* node)
{
	if (!node || !head) return;

	Node* curr = head;
	int nodeIndex = 0;

	while (curr && curr != node)
	{
		curr = curr->next;
		nodeIndex++;
	}

	if (curr != node) return;

	if (nodeIndex == 0)
	{
		head = curr->next;
		head->prev = nullptr;
		tail = nullptr;
	}
	else if (nodeIndex == size - 1)
	{
		tail = curr->prev;
		tail->next = nullptr;
	}
	else
	{
		Node* prev = curr->prev;
		Node* next = curr->next;

		prev->next = next;
		next->prev = prev;
	}

	delete curr;
	size--;
}

void LinkedList::Clear()
{
	Node* temp = nullptr;
	while (head != nullptr)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

void LinkedList::PrintList()
{
	Node* curr = head;
	while (curr != nullptr) {
		std::cout << curr->val << " ";
		curr = curr->next;
	}
	std::cout << "\n";
}
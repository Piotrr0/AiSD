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
	Node* node = new Node(number);
	if (head == nullptr)
	{
		tail = node;
		head = node;
	}
	else
	{
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	size++;
	return node;
}

Node* LinkedList::Prepend(int number)
{
	Node* node = new Node(number);
	if (head == nullptr)
	{
		tail = node;
		head = node;
	}
	else
	{
		node->next = head;
		head->prev = node;
		head = node;
	}
	size++;
	return node;
}

Node* LinkedList::GetNext(Node* element)
{
	if(element)
		return element->next;
}

Node* LinkedList::GetPrev(Node* element)
{
	if(element)
		return element->prev;
}

int LinkedList::Retrive(Node* element)
{
	if (element)
		return element->val;
}

Node* LinkedList::Find(int number)
{
	Node* node = head;
	while(node)
	{
		if (node->val == number)
			return node;
		node = node->next;
	}
	return nullptr;
}

void LinkedList::Insert(Node* element, int number) // insert to element->prev
{
	if (element == head)
		Prepend(number);
	else if (element == tail)
		Append(number);
	else
	{
		Node* node = new Node(number);
		Node* prevElement = element->prev;
		Node* nextElement = element->next;

		node->next = element;
		node->prev = prevElement;
		prevElement->next = node;
		nextElement->prev = node;
		size++;
	}
}

void LinkedList::Delete(Node* element)
{
	if (!element) return;

	if (element == head)
	{
		Node* headNext = head->next;
		headNext->prev = nullptr;

		delete head;
		head = headNext;
	}
	else if (element == tail)
	{
		Node* tailPrev = tail->prev;
		tailPrev->next = nullptr;
		delete tail;
		tail = tailPrev;
	}
	else
	{
		Node* elementPrev = element->prev;
		Node* elementNext = element->next;

		elementPrev->next = elementNext;
		elementNext->prev = elementPrev;
		delete element;
	}
	size--;
}

void LinkedList::DeleteX(int number)
{
	Node* node = head;
	while (node)
	{
		if (node->val == number)
		{
			Delete(node);
			return;
		}
		node = node->next;
	}
}

void LinkedList::DeleteXAll(int number)
{
	Node* node = head;
	while (node)
	{
		Node* nextNode = node->next;
		if (node->val == number)
		{
			Delete(node);
		}
		node = nextNode;
	}
}

void LinkedList::Clear()
{
	while (head)
	{
		Node* headNext = head->next;
		delete head;
		head = headNext;
	}
	head = nullptr;
	tail = nullptr;
	size = 0;
}

void LinkedList::PrintList()
{
	Node* curr = head;
	while (curr)
	{
		std::cout << curr->val << std::endl;
		curr = curr->next;
	}
}
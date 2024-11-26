#pragma once
#include "Node.h"

class SortedLinkedList
{
public:
	SortedLinkedList();
	~SortedLinkedList();

	void InsertSorted(int number);
	void PrintList();
	void Clear();

private:
	void Insert(Node* element, int number);
	Node* Append(int number);
	Node* Prepend(int number);

private:
	int size = 0;
	Node* head = nullptr;
	Node* tail = nullptr;

};


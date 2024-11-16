#include <iostream>
#include "LinkedList.h"
#include "SortedLinkedList.h"

int main()
{
	//SortedLinkedList* l = new SortedLinkedList();
	LinkedList* l = new LinkedList();
	l->Append(12);
	Node* node = l->Append(9);
	l->Append(3);
	l->Insert(node, 1);
	l->PrintList();
}
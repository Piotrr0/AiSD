#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList* l = new LinkedList();
	l->Append(12);
	Node* nodeToDelete = l->Append(11);
	l->Prepend(10);
	l->Insert(1, 9);
	l->Delete(nodeToDelete);
	l->PrintList();
}
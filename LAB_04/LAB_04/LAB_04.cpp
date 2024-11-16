#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList* l = new LinkedList();
	l->Append(12);
	l->Append(9);
	l->Append(3);
	l->Prepend(1);
	l->PrintList();
}
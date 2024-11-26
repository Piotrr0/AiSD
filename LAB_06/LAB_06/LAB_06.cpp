#include <iostream>
#include "BSTree.h"

int main()
{
	BSTree* tree = new BSTree();
	tree->Insert(7);
	tree->Insert(4);
	tree->Insert(9);
	tree->Inorder();

}
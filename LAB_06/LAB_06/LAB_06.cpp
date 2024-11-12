#include <iostream>
#include "BSTree.h"

int main()
{
	BSTree* tree = new BSTree();
	tree->Insert(7);
	tree->Insert(4);
	tree->Insert(2);
	tree->Insert(8);
	tree->Insert(10);
	tree->Inorder();

	std::cout << tree->Search(8)->val << std::endl;	
}
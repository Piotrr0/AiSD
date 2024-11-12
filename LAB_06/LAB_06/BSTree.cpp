#include "BSTree.h"

BSTree::BSTree()
{
	root = nullptr;
}

void BSTree::Insert(int number)
{
	root = InsertHelper(number, root);
}

bool BSTree::Empty()
{
	return root == nullptr;
}

void BSTree::Inorder()
{
	InorderHelper(root);
	std::cout << std::endl;
}

void BSTree::Delete(int number)
{
	root = DeleteHelper(root, number);
}

Node* BSTree::Search(int number)
{
	return SearchHelper(root, number);
}

Node* BSTree::InsertHelper(int number, Node* node, Node* parent)
{
	if (node == nullptr)
	{
		Node* newNode = new Node(number);
		newNode->parent = parent;
		return newNode;
	}

	if (number > node->val)
	{
		node->right = InsertHelper(number, node->right, node);
	}
	else {
		node->left = InsertHelper(number, node->left, node);
	}

	return node;
}


void BSTree::InorderHelper(Node* node)
{
	if (node == nullptr)
		return;

	InorderHelper(node->left);
	std::cout << node->val << " ";
	InorderHelper(node->right);
}

Node* BSTree::DeleteHelper(Node* node, int number) 
{
	if (node == nullptr) 
	{
		return node;
	}

	if (number < node->val) 
	{
		node->left = DeleteHelper(node->left, number);
	}
	else if (number > node->val) 
	{
		node->right = DeleteHelper(node->right, number);
	}
	else 
	{
		if (node->left == nullptr) 
		{
			Node* temp = node->right;
			if (temp != nullptr) 
			{
				temp->parent = node->parent;
			}
			delete node;
			return temp;
		}
		else if (node->right == nullptr) 
		{
			Node* temp = node->left;
			if (temp != nullptr) 
			{
				temp->parent = node->parent;
			}
			delete node;
			return temp;
		}

		Node* temp = MinValueNode(node->right);
		node->val = temp->val;
		node->right = DeleteHelper(node->right, temp->val);
	}
	return node;
}

Node* BSTree::SearchHelper(Node* node, int number)
{
	if (node == nullptr)
		return nullptr;

	if (node->val == number)
		return node;

	SearchHelper(node->left, number);
	SearchHelper(node->right, number);
}

Node* BSTree::LeftMost(Node* node)
{
	Node* curr = node;
	while (curr->left != nullptr)
		curr = curr->left;
	return curr;
}

Node* BSTree::MinValueNode(Node* node)
{
	Node* current = node;
	while (current && current->left != nullptr)
		current = current->left;
	return current;
}

Node* BSTree::MaxValueNode(Node* node)
{
	Node* currect = node;
	while (currect && currect->right != nullptr)
		currect = currect->right;
	return currect;
}

Node* BSTree::GetSuccessor(Node* node) 
{
	if (node == nullptr) return nullptr;

	if (node->right != nullptr) 
	{
		return MinValueNode(node->right);
	}

	Node* parent = node->parent;
	while (parent != nullptr && node == parent->right) 
	{
		node = parent;
		parent = parent->parent;
	}
	return parent;
}

Node* BSTree::GetPredecessor(Node* node)
{
	if (node == nullptr) return nullptr;

	if (node->left != nullptr) 
	{
		return MaxValueNode(node->left);
	}

	Node* parent = node->parent;
	while (parent != nullptr && node == parent->left) 
	{
		node = parent;
		parent = parent->parent;
	}
	return parent;
}
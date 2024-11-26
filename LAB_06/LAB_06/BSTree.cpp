#include "BSTree.h"

BSTree::BSTree()
{
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
}

void BSTree::Delete(Node* node)
{
	if (node == nullptr) return;

	// Case 1: Node has no children
	if (!node->left && !node->right)
	{
		Node* parent = node->parent;
		if (parent)
		{
			if (node == parent->left)
				parent->left = nullptr;
			else
				parent->right = nullptr;
		}
		delete node;
	}
	// Case 2: Node has one child
	else if (!node->left || !node->right)
	{
		Node* child = node->left ? node->left : node->right;

		Node* parent = node->parent;
		if (parent)
		{
			if (node == parent->left)
				parent->left = child;
			else
				parent->right = child;
		}

		if (child)
			child->parent = parent;

		delete node;
	}
	// Case 3: Node has two children
	else
	{
		Node* successor = MinValueNode(node->right);
		node->val = successor->val;
		Delete(successor);
	}
}

Node* BSTree::Search(int number)
{
	return SearchHelper(number, root);
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
	Node* current = node;
	while (current && current->right != nullptr)
		current = current->right;
	return current;
}

Node* BSTree::Successor(Node* node)
{
	if (!node) return nullptr;

	if (node->right)
	{
		return MinValueNode(node->right);
	}

	Node* parent = node->parent;
	while (parent && node == parent->right)
	{
		node = parent;
		parent = parent->parent;
	}
	return parent;
}

Node* BSTree::Predecessor(Node* node)
{
	if (!node) return nullptr;

	if (node->left)
	{
		return MaxValueNode(node->left);
	}

	Node* parent = node->parent;
	while (parent && node == parent->left)
	{
		node = parent;
		parent = parent->parent;
	}
	return parent;
}

int BSTree::Size(Node* node)
{
	return SizeHelper(node);
}

int BSTree::Hight(Node* node)
{
	return HightHelper(node, 0);
}

void BSTree::Clear(Node* node)
{
	if (!node)
		return;

	Clear(node->left);
	Clear(node->right);

	if (node == root)
		root = nullptr;

	delete node;
}

Node* BSTree::InsertHelper(int number, Node* node)
{
	if (node == nullptr)
		return new Node(number);

	if (number < node->val)
	{
		Node* leftChild = InsertHelper(number, node->left);
		node->left = leftChild;
		leftChild->parent = node;
	}
	else
	{
		Node* rightChild = InsertHelper(number, node->right);
		node->right = rightChild;
		rightChild->parent = node;
	}

	return node;
}

void BSTree::InorderHelper(Node* node)
{
	if (node != nullptr)
	{
		InorderHelper(node->left);
		std::cout << node->val << std::endl;
		InorderHelper(node->right);
	}
}

Node* BSTree::SearchHelper(int number, Node* node)
{
	if (root == nullptr) return nullptr;

	if (node->val == number)
	{
		return node;


		if (number < node->val)
		{
			return SearchHelper(number, node->left);
		}
		else
		{
			return SearchHelper(number, node->right);
		}
	}
}

int BSTree::HightHelper(Node* node, int currHeight)
{
	if (node)
		currHeight++;

	int leftHeight = HightHelper(node->left, currHeight + 1);
	int rightHeight = HightHelper(node->right, currHeight + 1);

	return std::max(leftHeight, rightHeight);
}

int BSTree::SizeHelper(Node* node)
{
	if (node)
		return 0;

	return 1 + SizeHelper(node->left) + SizeHelper(node->right);
}

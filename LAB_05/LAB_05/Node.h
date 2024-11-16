#pragma once
struct Node
{
	Node(int val) { this->val = val; }

	int val;
	Node* next;
};
#pragma once
struct Node
{
	Node(int val) { this->val = val; }

	int val;
	Node* prev = nullptr;
	Node* next = nullptr;
};

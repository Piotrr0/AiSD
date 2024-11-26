#pragma once
#include "Node.h"

class StackLL
{
public:
	StackLL();
	bool Empty();
	void Push(int number);
	int Peek();
	void Pop();
	void Clear();
	void PrintStack();

private:

private:
	Node* top = nullptr;
	Node* head = nullptr;

public:
};


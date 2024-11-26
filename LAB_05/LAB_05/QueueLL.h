#pragma once
#include "Node.h";

class QueueLL
{
public:
	QueueLL();
	bool Empty();
	void Enqueue(int number);
	int Peek();
	void Dequeue();
	void Clear();
	void PrintQueue();

private:

private:
	Node* tail = nullptr;
	Node* head = nullptr;

public:
};


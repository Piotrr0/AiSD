#pragma once
class QueueARR
{
public:
	QueueARR(int capacity);
	bool Empty();
	bool Full();
	void Enqueue(int number);
	int Peek();
	void Dequeue();
	void Clear();
	void PrintQueue();
		
private:

private:
	int* items = nullptr;
	int capacity = 0;
	int size = 0;
	int tail = -1;
	int head = -1;

public:
};


#pragma once
class QueueARR
{
public:
	QueueARR(int capacity); // placeholder
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
	int head = -1;
	int tail = -1;

public:
};


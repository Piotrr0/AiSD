#pragma once
class StackARR
{
public: 
	StackARR(int capacity);

	bool isEmpty();
	bool Full();
	void Push(int number);
	int Peek();
	void Pop();
	void Clear();
	void PrintStack();

private:


private:
	int* items = nullptr;
	int capacity = 0;
	int top = -1;

public:

};


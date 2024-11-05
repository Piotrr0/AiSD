#include "StackARR.h"
#include <iostream>;

StackARR::StackARR(int capacity)
{
	this->capacity = capacity;
	items = new int[capacity];
}

bool StackARR::isEmpty()
{
	if (top == -1)
		return true;
	return false;
}

bool StackARR::Full()
{
	if (capacity == top + 1)
		return true;
	return false;
}

void StackARR::Push(int number)
{
	if (items != nullptr && !Full())
	{
		top++;
		items[top] = number;
	}
}

int StackARR::Peek()
{
	if (items != nullptr && !isEmpty())
	{
		return items[top];
	}
}

void StackARR::Pop()
{
	if (items != nullptr && !isEmpty())
	{
		items[top] = 0;
		top--;
	}
}

void StackARR::Clear()
{
	if (items == nullptr) return;
	for (int i = 0; i <= top; i++)
	{
		items[i] = 0;
	}
	top = -1;
}

void StackARR::PrintStack()
{
	if (items == nullptr) return;
	for (int i = 0; i <= top; i++)
	{
		std::cout << items[i] << std::endl;
	}
}

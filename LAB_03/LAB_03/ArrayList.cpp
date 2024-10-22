#include "ArrayList.h"
#include <cstring>
#include <limits.h>

ArrayList::ArrayList()
{
	items = new int[1];
}

ArrayList::~ArrayList()
{
	delete[] items;
}

int ArrayList::Top()
{
	if (!Empty())
	{
		return items[head];
	}
	return INT_MIN;
}

int ArrayList::Back()
{
	if (!Empty())
	{
		return items[tail];
	}
	return INT_MIN;
}

bool ArrayList::Empty()
{
	if (size > 0)
		return false;
	return true;
}

void ArrayList::Append(int element)
{
	if (size >= capacity)
		IncreaseCapacity();

	if (tail < 0)
		tail = 0;

	head++;
	size++;
	items[head] = element;
}

void ArrayList::PreApped(int element)
{
	ShiftArrayRight(0);

	head++;
	size++;
	items[tail] = element;
}

void ArrayList::Insert(int element, int position)
{
	if (position >= size) return;

	if (size >= capacity)
		IncreaseCapacity();

	if (tail < 0)
		tail = 0;

	ShiftArrayRight(position);
	items[position] = element;
	size++;
	head++;
}

void ArrayList::Clear()
{
	size = 0;
	head = -1;
	tail = -1;
	delete[] items;
	items = new int[capacity];
}

bool ArrayList::Delete(int position)
{
	if (position < 0 || position >= size) return false;

	ShiftArrayLeft(position);
	size--;
	head--;

	if (size == 0)
	{
		head = -1;
		tail = -1;
	}
	return true;
}

bool ArrayList::Find(int element)
{
	for (int i = 0; i < size; i++)
	{
		if (items[i] == element)
			return i;
	}
	return -1;
}

bool ArrayList::DeleteX(int element)
{
	int index = Find(element);
	if (index == -1)
		return false;
	Delete(index);
	return true;
}

bool ArrayList::DeleteAllX(int element)
{

}

void ArrayList::IncreaseCapacity()
{
	int newCapacity = capacity * 1.5;
	int* newItems = new int[newCapacity];
	std::memcpy(newItems, items, capacity * sizeof(int));
	delete[] items;
	items = newItems;
	capacity = newCapacity;
}

void ArrayList::ShiftArrayRight(int position)
{
	for (int i = size - 1; i >= position; i--)
	{
		items[i + 1] = items[i];
	}
}

void ArrayList::ShiftArrayLeft(int position)
{
	for (int i = position + 1; i < size; i++)
	{
		items[i - 1] = items[i];
	}
}


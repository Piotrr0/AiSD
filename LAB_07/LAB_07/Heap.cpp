#include "Heap.h"
#include <iostream>
#include <algorithm>

Heap::Heap(int c) : capacity(c), size(0)
{
	heap = new Element[c];
}

Heap::Heap() : capacity(11), size(0)
{
	heap = new Element[11];
}

Heap::~Heap()
{
	delete[] heap;
}

bool Heap::Empty() const
{
	return size == 0;
}

bool Heap::Full() const
{
	return size == capacity;
}

int Heap::GetLeft(int i) const
{
	return 2 * i + 1;
}

int Heap::GetRight(int i) const
{
	return  2 * i + 2;
}

int Heap::GetParent(int i) const
{
	if (i == 0) return -1;
	return (i - 1) / 2;
}

int Heap::GetSize() const
{
	return size;
}

Element Heap::GetValue(int i) const
{
	return heap[i];
}

void Heap::SetValue(int i, const Element& x)
{
	heap[i] = x;
}

void Heap::BottomUp(int i)
{
	int index = i;

	while (index > 0 && heap[index].p < heap[GetParent(index)].p)
	{
		std::swap(heap[index], heap[GetParent(index)]);
		index = GetParent(index);
	}
}

void Heap::TopDown(int i)
{
	int index = i;
	while (GetLeft(index) < size)
	{
		int left = GetLeft(index);
		int right = GetRight(index);

		int smaller = left;
		if (right < size && heap[right].p < heap[left].p)
		{
			smaller = right;
		}

		if (heap[index].p > heap[smaller].p)
		{
			std::swap(heap[index], heap[smaller]);
			index = smaller;
		}
		else
		{
			break;
		}
	}
}

void Heap::Insert(const Element& x)
{
	if (Full()) return;
	heap[size] = x;
	BottomUp(size);
	size++;
}

void Heap::Delete(int i)
{
	if (Empty()) return;
	if (i < 0 || i > size) return;

	heap[i] = heap[size - 1];
	size--;

	if (heap[i].p < heap[GetParent(i)].p)
	{
		BottomUp(i);
	}
	else
	{
		TopDown(i);
	}
}

void Heap::DeleteMaxPriority()
{
	if (Empty()) return;

	int maxIndex = 0;
	for (int i = 0; i < size; i++)
	{
		if (heap[i].p > heap[maxIndex].p)
		{
			maxIndex = i;
		}
	}

	Delete(maxIndex);
}

Element Heap::MaxPriority() const
{
	int maxIndex = 0;
	for (int i = 1; i < size; i++)
	{
		if (heap[i].p > heap[maxIndex].p)
		{
			maxIndex = i;
		}
	}
	return heap[maxIndex];
}

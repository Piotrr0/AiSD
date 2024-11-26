#include "Heap.h"
#include "Heap.h"
#include <iostream>
#include <stdexcept>

Heap::Heap(int c) : capacity(c), size(0)
{
	heap = new Element[c];
}

Heap::Heap() : capacity(11), size(0)
{
	heap = new Element[11];
}

bool Heap::Empty()
{
	return size == 0;
}

bool Heap::Full()
{
	return size == capacity;
}

int Heap::GetLeft(int i)
{
	return 2 * i + 1;
}

int Heap::GetRight(int i)
{
	return 2 * i + 2;
}

int Heap::GetParent(int i)
{
	if (i == 0) return -1;
	return (i - 1) / 2;
}

int Heap::GetSize()
{
	return size;
}

void Heap::SetSize(int s)
{
	if (s > capacity)
		return;
	size = s;
}

Element Heap::GetValue(int i)
{
	if (i < 0 || i >= size)
		return Element();
	return heap[i];
}

void Heap::SetValue(int i, Element x)
{
	heap[i] = x;
	if (i >= size)
	{
		size = i + 1;
	}
}

void Heap::BottomUp(int i)
{
	while (i > 0)
	{
		int parent = (i - 1) / 2;
		if (heap[i].p > heap[parent].p)
		{
			std::swap(heap[i], heap[parent]);
			i = parent;
		}
		else
		{
			break;
		}
	}
}

void Heap::TopDown(int i)
{
	while (GetLeft(i) < size)
	{
		int left = GetLeft(i);
		int right = GetRight(i);
		int largest = i;

		if (left < size && heap[left].p > heap[largest].p)
		{
			largest = left;
		}
		if (right < size && heap[right].p > heap[largest].p)
		{
			largest = right;
		}

		if (largest != i)
		{
			std::swap(heap[i], heap[largest]);
			i = largest;
		}
		else
		{
			break;
		}
	}
}

void Heap::Insert(Element x)
{
}

void Heap::DeleteMaxPriority()
{

}

Element Heap::MaxPriority()
{
	int max = -1;
	int index = -1;
	for (int i = 0; i < size; i++)
	{
		int prevMax = max;
		max = std::max(max, heap[i].p);
		if (max != prevMax)
		{
			index = i;
		}
	}
	return heap[index];
}

void Heap::Delete(int i)
{
}

Heap::~Heap()
{
	delete[] heap;
}
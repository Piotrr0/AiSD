#include "ArrayList.h"
#include <cstring>
#include <limits.h>

ArrayList::ArrayList()
{
    items = new int[capacity];
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
    return size == 0;
}

void ArrayList::Append(int element)
{
    if (size >= capacity)
        IncreaseCapacity();

    if (tail < 0)
    {
        tail = 0;
        head = 0;
    }
    else
    {
        head++;
    }

    items[head] = element;
    size++;
}

void ArrayList::PreApped(int element)
{
    if (size >= capacity)
        IncreaseCapacity();

    ShiftArrayRight(0);

    items[0] = element;
    size++;

    if (tail < 0)
    {
        tail = 0;
        head = 0; 
    }
    else
    {
        head++;
    }
}

void ArrayList::Insert(int element, int position)
{
    if (position > size) return;

    if (size >= capacity)
        IncreaseCapacity();

    if (tail < 0)
    {
        tail = 0;
        head = 0;
    }

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

int ArrayList::Find(int element)
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
    return false;
}

void ArrayList::IncreaseCapacity()
{
    int newCapacity = (capacity == 0) ? 1 : capacity * 2; 
    int* newItems = new int[newCapacity];
    std::memcpy(newItems, items, size * sizeof(int));
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

std::ostream& operator<<(std::ostream& os,ArrayList& arrayList)
{
    if (arrayList.Empty())
    {
        os << "ArrayList is empty.";
    }
    else
    {
        for (int i = 0; i < arrayList.GetSize(); ++i)
        {
            os << arrayList.GetItem(i);
            if (i < arrayList.GetSize() - 1)
                os << " ";
        }
    }
    return os;
}
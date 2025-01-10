#include <iostream>
#include "Heap.h"

void PrintHeap(const Heap& heap) 
{
    for (int i = 0; i < heap.GetSize(); i++) 
    {
        Element e = heap.GetValue(i);
        std::cout << "(" << e.p << ", " << e.v << ") ";
    }
    std::cout << std::endl;
}

void RunTests() 
{
    Heap h(10);
    h.Insert({ 3, 'A' });
    h.Insert({ 2, 'B' });
    h.Insert({ 5, 'C' });
    h.Insert({ 1, 'D' });

    std::cout << "Test 1 - Insert elements:" << std::endl;
    PrintHeap(h);

    Element max = h.MaxPriority();
    std::cout << "Test 2 - MaxPriority: " << max.p << ", " << max.v << std::endl;

    h.DeleteMaxPriority();
    std::cout << "Test 3 - After DeleteMaxPriority:" << std::endl;
    PrintHeap(h);

    h.Delete(1);
    std::cout << "Test 4 - After Delete(index 1):" << std::endl;
    PrintHeap(h);

    h.Insert({ 0, 'E' });
    std::cout << "Test 5 - After inserting (0, 'E'):" << std::endl;
    PrintHeap(h);

    Heap emptyHeap;
    std::cout << "Test 6 - Empty heap is empty: " << emptyHeap.Empty() << std::endl;
    std::cout << "Test 6 - Full heap is full: " << h.Full() << std::endl;

    Heap bigHeap(100);
    for (int i = 0; i < 100; i++) {
        bigHeap.Insert({ 100 - i, static_cast<char>('A' + (i % 26)) });
    }
    std::cout << "Test 7 - Stress Test Passed: " << (bigHeap.GetSize() == 100) << std::endl;

    Heap singleHeap(5);
    singleHeap.Insert({ 42, 'Z' });
    singleHeap.DeleteMaxPriority();
    std::cout << "Test 8 - Single element deletion passed: " << singleHeap.Empty() << std::endl;

    try 
    {
        emptyHeap.MaxPriority();
    }
    catch (const std::exception& e) 
    {
        std::cout << "Test 9 - MaxPriority on empty heap caught exception: " << e.what() << std::endl;
    }
}

int main() 
{
    RunTests();
    return 0;
}

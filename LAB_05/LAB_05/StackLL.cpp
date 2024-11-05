#include "StackLL.h"
#include <iostream>

StackLL::StackLL()
{

}

bool StackLL::Empty()
{
    return top == nullptr;
}

void StackLL::Push(int number)
{
    Node* pushNode = new Node(number);
    if (top == nullptr)
    {
        head = pushNode;
    }
    else
    {
        top->next = pushNode;
    }
    top = pushNode;
}

int StackLL::Peek()
{
    if (top != nullptr)
        return top->val;
    return -1;
}

void StackLL::Pop()
{
    if (top == nullptr)
        return;

    if (head == top)
    {
        delete top;
        head = nullptr;
        top = nullptr;
    }
    else
    {
        Node* current = head;
        while (current->next != top)
            current = current->next;

        delete top;
        top = current;
        top->next = nullptr;
    }
}

void StackLL::Clear()
{
    Node* temp = nullptr;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void StackLL::PrintStack()
{
    Node* curr = head;
    while (curr != nullptr && curr->next != nullptr)
    {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

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
    Node* node = new Node(number);
    node->next = top;
    top = node;
}

int StackLL::Peek()
{
    return top->val;
}

void StackLL::Pop() 
{
    if (top != nullptr) 
    {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void StackLL::Clear()
{
    while (top != nullptr) 
    {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void StackLL::PrintStack() 
{
    Node* curr = top;
    while (curr != nullptr) 
    {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}
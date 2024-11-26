#include "SortedLinkedList.h"
#include <iostream>

SortedLinkedList::SortedLinkedList()
{

}

SortedLinkedList::~SortedLinkedList()
{
}

void SortedLinkedList::InsertSorted(int number)
{
    if (size == 0)
    {
        Append(number);
    }
    else
    {
        Node* node = head;

        // Check if the number should be inserted at the beginning
        if (number <= head->val)
        {
            Prepend(number);
        }
        // Check if the number should be inserted at the end
        else if (number >= tail->val)
        {
            Append(number);
        }
        else
        {
            // Traverse the list to find the correct insertion point
            while (node)
            {
                if (node->val > number && (node->next == nullptr || node->next->val >= number))
                {
                    Insert(node, number);
                    break;
                }
                node = node->next;
            }
        }
    }
}

void SortedLinkedList::PrintList()
{
    Node* curr = head;
    while (curr)
    {
        std::cout << curr->val << std::endl;
        curr = curr->next;
    }
}

void SortedLinkedList::Clear()
{
    while (head)
    {
        Node* headNext = head->next;
        delete head;
        head = headNext;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void SortedLinkedList::Insert(Node* element, int number)
{
    Node* node = new Node(number);
    Node* prevElement = element;
    Node* nextElement = element->next;

    node->next = nextElement;
    node->prev = prevElement;
    prevElement->next = node;
    if (nextElement)
        nextElement->prev = node;
    else
        tail = node;  // If the node is inserted at the end, update the tail
    size++;
}

Node* SortedLinkedList::Append(int number)
{
    Node* node = new Node(number);
    if (head == nullptr)
    {
        tail = node;
        head = node;
    }
    else
    {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    size++;
    return node;
}

Node* SortedLinkedList::Prepend(int number)
{
    Node* node = new Node(number);
    if (head == nullptr)
    {
        tail = node;
        head = node;
    }
    else
    {
        node->next = head;
        head->prev = node;
        head = node;
    }
    size++;
    return node;
}
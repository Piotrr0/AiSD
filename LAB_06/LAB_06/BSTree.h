#pragma once
#include <iostream>

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node* parent;

    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

class BSTree
{
public:
    BSTree();
    void Insert(int number);
    bool Empty();
    void Inorder();
    void Delete(int number);
    Node* Search(int number);
    Node* MinValueNode(Node* node);
    Node* MaxValueNode(Node* node);
    Node* GetSuccessor(Node* node);
    Node* GetPredecessor(Node* node);

private:
    Node* InsertHelper(int number, Node* node, Node* parent = nullptr);
    void InorderHelper(Node* node);
    Node* DeleteHelper(Node* node, int number);
    Node* SearchHelper(Node* node, int number);

    Node* LeftMost(Node* node);

private:
    Node* root = nullptr;

public:
    inline Node* GetRoot() const { return root; }
};

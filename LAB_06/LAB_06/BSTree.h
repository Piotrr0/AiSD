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
    void Delete(Node* node);
    Node* Search(int number);
    Node* MinValueNode(Node* node);
    Node* MaxValueNode(Node* node);
    Node* Successor(Node* node);
    Node* Predecessor(Node* node);
    int Size(Node* node);
    int Hight(Node* node);
    void Clear(Node* node);

private:

    Node* InsertHelper(int number, Node* node);
    void InorderHelper(Node* node);
    Node* SearchHelper(int number, Node* node);
    int HightHelper(Node* node, int currHeight);
    int SizeHelper(Node* node);


private:
    Node* root = nullptr;

public:
    inline Node* GetRoot() const { return root; }
};

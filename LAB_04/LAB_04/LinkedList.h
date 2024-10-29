#pragma once

struct Node
{
	Node(int val) { this->val = val; }

	int val;
	Node* prev = nullptr;
	Node* next = nullptr;
};

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	Node* Append(int number);
	Node* Prepend(int number);

	Node* GetNext(Node* element);
	Node* GetPrev(Node* element);
	int Retrive(Node* element);
	Node* Find(int number);
	void Insert(int index, int number);
	void Delete(Node* node);
	void Clear();

	void PrintList();
	
private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;


public:
	
	inline int GetSize() const { return size; }
	inline bool IsEmpty() const { return size == 0; }
	inline Node* GetFirst() const { return head; }
	inline Node* GetLast() const { return tail; }

};


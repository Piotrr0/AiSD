#pragma once
struct Element
{
	int p{};
	char v{};
	Element() {}
	Element(int p, char z) : p(p), v(z) {}
};

class Heap
{
private:
	Element* heap;
	int capacity;
	int size;
public:
	Heap(int c);
	Heap();
	~Heap();
	bool Empty();
	bool Full();
	int GetLeft(int i);
	int GetRight(int i);
	int GetParent(int i);
	int GetSize();
	void SetSize(int s);
	Element GetValue(int i);
	void SetValue(int i, Element x);
	void BottomUp(int i);
	void TopDown(int i);
	void Insert(Element x);                    //wstawia element x (p - riorytet, v - wartoœæ)
	void DeleteMaxPriority();                     
	Element MaxPriority();                 
	void Delete(int i);                   
};

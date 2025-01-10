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
	bool Empty() const;
	bool Full() const;
	int GetLeft(int i) const;
	int GetRight(int i) const;
	int GetParent(int i) const;
	int GetSize() const;
	Element GetValue(int i) const;
	void SetValue(int i, const Element& x);
	void BottomUp(int i);
	void TopDown(int i);
	void Insert(const Element& x);
	void Delete(int i);
	void DeleteMaxPriority();
	Element MaxPriority() const;
};

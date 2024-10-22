#pragma once
class ArrayList
{
public:
	ArrayList();
	~ArrayList();
public:
	int Top();
	int Back();
	bool Empty();
	void Append(int element);
	void PreApped(int element);
	void Insert(int element, int position);
	void Clear();
	bool Delete(int position);
	bool Find(int element);
	bool DeleteX(int element);
	bool DeleteAllX(int element);

private:

	void IncreaseCapacity();
	void ShiftArrayRight(int position);
	void ShiftArrayLeft(int position);

	int* items = nullptr;
	int head = -1;
	int tail = -1;
	int capacity = 0;
	int size = 0;

public:

	inline int GetCapacity() const { return capacity; }
	inline int GetSize() const { return size; }

};


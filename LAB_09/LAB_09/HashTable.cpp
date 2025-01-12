#include "HashTable.h"
#include <cstring>   

HashTable::HashTable(int capacity) : capacity(capacity), size(0)
{
	t = new std::string[capacity];
}

HashTable::~HashTable()
{
	delete[] t;
}

bool HashTable::Empty()
{
	return size == 0;
}

bool HashTable::Full()
{
	return size == capacity;
}

int HashTable::HashFunction(std::string s)
{
	const int p = 31;
	const int m = 1e9 + 9;
	unsigned long long hashValue = 0;
	unsigned long long pPow = 1;

	for (char c : s)
	{
		hashValue = (hashValue + (c - 'a' + 1) * pPow) % m;
		pPow = (pPow * p) % m;
	}

	return hashValue % capacity;
}

void HashTable::Insert(std::string s)
{
	if (Full()) return;
	int attempts = 0;
	Insert(s, attempts); // Reuse the other Insert for consistency
}

void HashTable::Insert(std::string s, int& attempts)
{
	if (Full()) return;

	int index = HashFunction(s);
	int originalIndex = index;
	attempts = 0;

	while (!t[index].empty() && t[index] != s)
	{
		index = (index + 1) % capacity;
		attempts++;
		if (index == originalIndex)
		{
			std::cerr << "Hash table full while inserting " << s << std::endl;
			return;
		}
	}

	if (t[index].empty())
	{
		t[index] = s;
		size++;
	}
}

void HashTable::Del(std::string s)
{
	int index = HashFunction(s);
	int originalIndex = index;

	while (!t[index].empty())
	{
		if (t[index] == s)
		{
			t[index] = "";
			size--;
			return;
		}

		index = (index + 1) % capacity;
		if (index == originalIndex)
		{
			return;
		}
	}
}

std::string HashTable::Search(std::string s)
{
	int attempts = 0;
	return Search(s, attempts);
}

std::string HashTable::Search(std::string s, int& attempts)
{
	int index = HashFunction(s);
	int originalIndex = index;
	attempts = 0;

	while (!t[index].empty())
	{
		attempts++;
		if (t[index] == s)
		{
			return t[index];
		}

		index = (index + 1) % capacity;
		if (index == originalIndex)
		{
			break;
		}
	}
	return "";
}
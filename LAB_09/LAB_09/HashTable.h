#pragma once
#include <iostream>

class HashTable
{
public:
	HashTable(int capacity);
	~HashTable();

	bool Empty();
	bool Full();
	int HashFunction(std::string s);
	void Insert(std::string s);
	void Insert(std::string s, int& attempts);
	void Del(std::string s);
	std::string Search(std::string s);
	std::string Search(std::string s, int& attempts);

private:
	std::string* t;
	int capacity;
	int size;
};
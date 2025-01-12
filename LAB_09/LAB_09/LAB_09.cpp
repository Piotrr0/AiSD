#include <iostream>

#include <cassert>
#include <iostream>
#include <string>
#include "HashTable.h"

int main()
{
	HashTable ht(10);
	ht.Insert("apple");
	ht.Insert("banana");
	ht.Insert("cherry");

	std::cout << "Search 'banana': " << ht.Search("banana") << std::endl;
	std::cout << "Search 'grape': " << ht.Search("grape") << std::endl;

	ht.Del("banana");
	std::cout << "Search 'banana' after deletion: " << ht.Search("banana") << std::endl;
	ht.Insert("date");
	ht.Insert("elderberry");
	ht.Insert("fig");
	ht.Insert("grape");
	ht.Insert("honeydew");
	ht.Insert("kiwi");
	ht.Insert("lemon");

	std::cout << "Search 'lemon': " << ht.Search("lemon") << std::endl;
	int attempts = 0;
	std::cout << "Search 'lemon' with attempts: " << ht.Search("lemon", attempts) << " Attempts: " << attempts << std::endl;
	std::cout << "Search 'grape' with attempts: " << ht.Search("grape", attempts) << " Attempts: " << attempts << std::endl;

	ht.Insert("mango");
	return 0;
}

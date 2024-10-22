
#include <iostream>
#include "ArrayList.h"

int main()
{
	ArrayList* arr = new ArrayList();
	for (int i = 0; i < 10; i++)
	{
		arr->Append(i);
	}

	std::cout << arr->GetItem(2) << std::endl;
}
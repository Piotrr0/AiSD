
#include <iostream>
#include "ArrayList.h"

int main()
{
	ArrayList* arr = new ArrayList();
	for (int i = 0; i < arr->GetSize(); i++)
	{
		arr->Append(i);
	}
}
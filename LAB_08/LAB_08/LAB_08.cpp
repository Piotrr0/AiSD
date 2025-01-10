#include <iostream>
#include <ctime>
#include "unordered_map"

void InsertionSort(int* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i;
		while (j >= 0 && arr[j] < arr[j - 1])
		{
			std::swap(arr[j], arr[j-1]);
			j--;
		}
	}
}

void SelectionSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int minIndex = i;
		for (int j = i+1; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j; 
			}
		}
		std::swap(arr[i], arr[minIndex]);
	}
}

void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int Partition(int* arr, int left, int right)
{
	int pivot = arr[right];
	int i = left - 1;
	for (int j = left; j < right; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			std::swap(arr[i], arr[j]);
		}
	}
	i++;
	std::swap(arr[i], arr[right]);
	return i;
}

void QuickSort(int* arr, int left, int right)
{
	if (right <= left) return;
	int pivot = Partition(arr, left, right);
	QuickSort(arr, left, pivot - 1);
	QuickSort(arr, pivot + 1, right);
}

int main()
{
	int* arr = new int[10] {2, 7, 1, 5, 2, 8, 9, 0, 2, 11};
	BubbleSort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << std::endl;
	}

}
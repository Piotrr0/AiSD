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

void CountSort(int* arr, int n)
{
	int maxVal = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > maxVal) 
		{
			maxVal = arr[i];
		}
	}

	int* countArr = new int[maxVal + 1]();
	for (int i = 0; i < n; i++)
	{
		countArr[arr[i]]++;
	}

	for (int i = 1; i < maxVal + 1; i++) 
	{
		countArr[i] += countArr[i - 1];
	}

	int* outputArr = new int[n];
	for (int i = n - 1; i >= 0; i--) 
	{
		outputArr[countArr[arr[i]] - 1] = arr[i];
		countArr[arr[i]]--;
	}

	for (int i = 0; i < n; i++)
	{
		arr[i] = outputArr[i];
	}

	delete[] countArr;
	delete[] outputArr;
}

void RadixBinSort(int* arr, int n)
{
	std::unordered_map<int, std::vector<int>> bin;
	int maxVal = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > maxVal)
		{
			maxVal = arr[i];
		}
	}

	int exp = 1;
	while (maxVal / exp > 0)
	{
		for (int i = 0; i < n; i++)
		{
			int binIndex = (arr[i] / exp) % 10;
			bin[binIndex].push_back(arr[i]);
		}

		int index = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < bin[i].size(); j++)
			{
				arr[index++] = bin[i][j];
			}
			bin[i].clear();
		}
		exp *= 10;
	}
}

int main()
{
	int* arr = new int[10] {2, 7, 1, 5, 2, 8, 9, 0, 2, 11};
	RadixBinSort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << std::endl;
	}

}
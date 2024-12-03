#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>

void InsertionSort(int* arr, int n)
{
	for (int i = 1; i < n; ++i)
	{
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void SelectionSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min_idx = i;

		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
		}

		int temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
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
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int Partition(int* arr, int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}

	int temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;

	return i + 1;
}

void QuickSortHelper(int* arr, int low, int high)
{
	if (low < high)
	{
		int pivot = Partition(arr, low, high);
		QuickSortHelper(arr, low, pivot - 1);
		QuickSortHelper(arr, pivot + 1, high);
	}
}

void QuickSort(int* arr, int n)
{
	QuickSortHelper(arr, 0, n - 1);
}

int main()
{
	int n = 10000;
	int* arr = new int[n];

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 100);

	for (int i = 0; i < n; i++)
	{
		arr[i] = dist6(rng);
	}

	clock_t start = clock();
	QuickSort(arr, n);
	clock_t stop = clock();
	double resultTime = (double)(stop - start) / CLOCKS_PER_SEC;
	std::cout << resultTime << std::endl;

	for (int i = 0; i < n; i++)
	{
		//std::cout << arr[i] << std::endl;
	}
	delete[] arr;
}
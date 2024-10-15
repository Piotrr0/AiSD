#include <iostream>

int linearSearch(int* arr, int n, int x)
{
	if (arr == nullptr) return -1;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}

int linearSearch(int* arr, int n, int x, int& steps)
{
	if (arr == nullptr) return -1;
	steps = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
		{
			steps = i + 1;
			return i;
		}
	}
	steps = n;
	return -1;
}

int binarySearch(int* arr, int n, int x)
{
	if (arr == nullptr) return -1;

	int i = 0;
	int j = n - 1;
	while (i <= j)
	{
		int m = (i + j) / 2;
		if (arr[m] == x)
			return m;
		else if (arr[m] < x)
			i = m + 1;
		else
			j = m - 1;
	}
	return -1;
}

int binarySearch(int* arr, int n, int x, int& steps)
{
	if (arr == nullptr) return -1;
	steps = 0;

	int i = 0;
	int j = n - 1;
	while (i <= j)
	{
		int m = (i + j) / 2;
		steps++;
		if (arr[m] == x)
			return m;
		else if (arr[m] < x)
			i = m + 1;
		else
			j = m - 1;
	}
	return -1;
}

int interpolationSearch(int* arr, int n, int x)
{
	if (arr == nullptr) return -1;
	int i = 0;
	int j = n-1;

	while (x >= arr[i] && x <= arr[j] && i <= j)
	{
		int guess = i + (j - i) * (x - arr[i]) / (arr[j] - arr[i]);
		if (arr[guess] == x)
			return guess;
		else if (arr[guess] < x)
			i = guess + 1;
		else
			j = guess - 1;
	}
	return -1;
}

int interpolationSearch(int* arr, int n, int x, int& steps)
{
	if (arr == nullptr) return -1;
	steps = 0;
	int i = 0;
	int j = n - 1;

	while (x >= arr[i] && x <= arr[j] && i <= j)
	{
		int guess = i + (j - i) * (x - arr[i]) / (arr[j] - arr[i]);
		steps++;
		if (arr[guess] == x)
			return guess;
		else if (arr[guess] < x)
			i = guess + 1;
		else
			j = guess - 1;
	}
	return -1;
}

int main()
{
	int n = 13;        
	int* arr = new int[n] {3,5,7,8,10,11,16,18,20,25,27,30,31};
	int steps = 0;
	std::cout << interpolationSearch(arr, n, 10, steps) << std::endl;
	std::cout << steps << std::endl;
}

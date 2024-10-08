#include <iostream>
#include <vector>

int divSum(int n)
{
	int sum = 1;
	for (int i = 2; i < (n / 2) + 1; i++)
	{
		if (n % i == 0)
		{
			sum += i;
		}
	}
	return sum;
}

bool isPerfect(int n)
{
	const int sum = divSum(n);
	if (sum == n)
	{
		return true;
	}
	return false;
}

std::vector<int> allPerfect(int n)
{
	std::vector<int> res;
	for (int i = 2; i <= n; i++)
	{
		if (isPerfect(i))
		{
			res.push_back(i);
		}
	}
	return res;
}

bool areAmicable(int n, int m)
{
	const int sumN = divSum(n);
	const int sumM = divSum(m);

	if (sumM == n && sumN == m) return true;
	return false;
}

std::vector<std::pair<int, int>> allAmicable(int n)
{
	std::vector<std::pair<int, int>> res;
	for (int i = 0; i < n; i++)
	{
		const int sumI = divSum(i);

		if (sumI > i && sumI <= n && areAmicable(i, sumI))
		{
			std::pair<int, int> pair;
			pair.first = i;
			pair.second = sumI;

			res.push_back(pair);
		}
	}
	return res;
}

int main()
{
	std::cout << "suma dzelnikow 15 = " << divSum(15) << std::endl;
	std::cout << "suma dzelnikow 17 = " << divSum(17) << std::endl;

	std::cout << "Liczba: 6 " << isPerfect(6) << std::endl;
	std::cout << "Liczba: 12 " << isPerfect(12) << std::endl;

	std::vector<int> perfectNumbers = allPerfect(9000);
	for (int number : perfectNumbers)
	{
		std::cout << number << " ";
	}
	std::cout << std::endl;

	std::cout << "Liczby 220 i 284 " << areAmicable(220, 284) << std::endl;
}
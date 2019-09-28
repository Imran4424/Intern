#include <iostream>
using namespace std;

const int mSize = 1122;

int prime[] = {};

int maxPrimeNum;

int targetSum, requiredNum;

int SumCount;

void FindCount(int i, int currentCount, int currentSum)
{

	if (currentSum > targetSum)
	{
		return;
	}

	if (currentCount == requiredNum)
	{
		if (currentSum == targetSum)
		{
			SumCount++;
		}

		return;
	}

	if (prime[i] > targetSum)
	{
		return;
	}

	if (i == maxPrimeNum)
	{
		return;
	}

	FindCount(i + 1, currentCount, currentSum);

	FindCount(i + 1, currentCount + 1,currentSum + prime[i]);
}

void Display()
{
	cout << SumCount << endl;
}

int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Sieve();

	cin >> targetSum >> requiredNum;

	while(0 != targetSum && 0 != requiredNum)
	{
		// clearing test cases
		SumCount = 0;

		FindCount(0, 0, 0);

		Display();

		cin >> targetSum >> requiredNum;
	}

	return 0;
}
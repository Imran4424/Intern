#include <iostream>
using namespace std;

const int mSize = 1122;

bool isPrime[mSize];
int prime[mSize/3];

int maxPrimeNum;

int targetSum, requiredNum;

int SumCount;

void InitPrime()
{
	for (int i = 0; i < mSize; ++i)
	{
		isPrime[i] = true;
	}
}

void Sieve()
{
	InitPrime();

	isPrime[0] = isPrime[1] = false;

	for (int p = 2; p*p < mSize; ++p)
	{
		if (isPrime[p])
		{
			for (int i = p*p; i < mSize; i = i + p)
			{
				isPrime[i] = false;
			}
		}
	}

	int x = 0;

	for (int i = 2; i < mSize; ++i)
	{
		if (isPrime[i])
		{
			prime[x++]= i;
		}
	}

	maxPrimeNum = x;	
}

void FindCount(int i, int currentCount, int currentSum)
{

	if (currentSum > targetSum)
	{
		return;
	}

	if (prime[i] > targetSum)
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
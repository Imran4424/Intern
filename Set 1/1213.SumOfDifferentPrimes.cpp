#include <iostream>
using namespace std;

const int mSize = 1122;
const int maxK = 15;

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

int dpCount[188][maxK][mSize];

void InitDp()
{
	for (int i = 0; i < maxPrimeNum; ++i)
	{
		for (int j = 0; j < maxK; ++j)
		{
			for (int k = 0; k < mSize; ++k)
			{
				dpCount[i][j][k] = -1;
			}
		}
	}
}

int FindCount(int i, int currentCount, int currentSum)
{
	if (-1 != dpCount[i][currentCount][currentSum])
	{
		return dpCount[i][currentCount][currentSum];
	}

	if ( 0 == currentCount)
	{
		if (0 == currentSum)
		{
			return dpCount[i][currentCount][currentSum] = 1;
		}

		return dpCount[i][currentCount][currentSum] = 0;
	}

	if (prime[i] > targetSum)
	{
		return dpCount[i][currentCount][currentSum] = 0;
	}

	if (i == maxPrimeNum)
	{
		return dpCount[i][currentCount][currentSum] = 0;
	}

	int left = FindCount(i + 1, currentCount, currentSum);

	int right;

	if (currentSum >= prime[i])
	{
		right = FindCount(i + 1, currentCount - 1, currentSum - prime[i]);
	}
	else
	{
		right = 0;
	}
	

	return dpCount[i][currentCount][currentSum] = left + right;
}


int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Sieve();
	InitDp();

	cin >> targetSum >> requiredNum;

	while(0 != targetSum && 0 != requiredNum)
	{
		cout << FindCount(0, requiredNum, targetSum) << endl;

		cin >> targetSum >> requiredNum;
	}

	return 0;
}
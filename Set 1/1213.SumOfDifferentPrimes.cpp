#include <iostream>
using namespace std;

const int mSize = 1122;

bool isPrime[mSize];
int prime[mSize/3];

int maxPrimeNum;

int targetSum, requiredNum;

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

void FindCount(int i, int currentSum)


int main(int argc, char const *argv[])
{
	Sieve();

	cin >> targetSum >> requiredNum;

	while(0 == targetSum && 0 == requiredNum)
	{
		
	}

	return 0;
}
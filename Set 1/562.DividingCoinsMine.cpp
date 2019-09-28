#include <iostream>
using namespace std;

const int mSize = 101;
const int mValue = 101 * 500;

int coins[mSize];
int dpSum[mSize][mValue];

int coinNum, totalSum;
int minDiff;

void Init()
{
	for (int i = 0; i <= coinNum; ++i)
	{
		for (int j = 0; j <= totalSum; ++j)
		{
			dpSum[i][j] = -1;
		}
	}
}

int Abs(int x)
{
	if (x < 0)
	{
		return -x;
	}

	return x;
}

int SubSetSum(int k, int subSum)
{
	if (-1 != dpSum[k][subSum])
	{
		return dpSum[k][subSum];
	}

	if (k == coinNum)
	{
		int otherSub = totalSum - subSum;

		if (minDiff > Abs(subSum - otherSub))
		{
			minDiff = Abs(subSum - otherSub);
		}

		return dpSum[k][subSum] = subSum;
	}

	int left = SubSetSum(k + 1, subSum);

	int right = SubSetSum(k + 1, subSum + coins[k]);

	if (left > right)
	{
		dpSum[k][subSum] = left;
	}
	else
	{
		dpSum[k][subSum] = right;
	}

	return dpSum[k][subSum];
}

void ReadCase()
{
	cin >> coinNum;

	totalSum = 0;
	Init();

	for (int i = 0; i < coinNum; ++i)
	{
		cin >> coins[i];

		totalSum += coins[i];
	}

	minDiff = totalSum;
}

void Display()
{
	cout << minDiff << endl;

	//cout << totalSum << endl;
}

int main(int argc, char const *argv[])
{
	// freopen("input.txt","r", stdin);
	// freopen("output.txt", "w", stdout);

	int test;
	cin >> test;

	while(test--)
	{
		ReadCase();
		SubSetSum(0, 0);
		Display();
	}

	return 0;
}
/*
	this solution is not accepted yet
*/

#include <iostream>
using namespace std;

const int mSize = 1001, pSize = 101;
const int wMax = 70;

int price[mSize], weight[mSize];
int dpPrice[mSize][wMax];

int weightCarry[pSize];

int objectNum, peopleNum, maxCarryWeight, totalCarryWeight;

int maxCarryHome, maxFamilyHome;

void Init()
{
	for (int i = 0; i < mSize; ++i)
	{
		for (int j = 0; j < wMax; ++j)
		{
			dpPrice[i][j] = -1;
		}
	}
}

int MaxSubSum(int i, int pSum, int wSum)
{
	if (-1 != dpPrice[i][wSum])
	{
		return dpPrice[i][wSum];
	}

	if (i == objectNum)
	{
		if (maxCarryWeight >= wSum)
		{
			return dpPrice[i][wSum] = pSum;
		}

		return dpPrice[i][wSum] = 0;
	}

	int left = MaxSubSum(i+1, pSum, wSum);

	int right;

	if (maxCarryWeight >= wSum + weight[i])
	{
		right = MaxSubSum(i+1, pSum + price[i], wSum + weight[i]);
	}
	else
	{
		right = 0;
	}

	if (left > right)
	{
		return dpPrice[i][wSum] = left;
	}
	
	return dpPrice[i][wSum] = right;
}

void Solve()
{
	// Clearing for test cases
	maxFamilyHome = 0;
	Init();

	for (int i = 0; i < peopleNum; ++i)
	{
		maxCarryWeight = weightCarry[i];

		maxFamilyHome += MaxSubSum(0, 0, 0);
	}
}

void ReadCase()
{

	cin >> objectNum;

	for (int i = 0; i < objectNum; ++i)
	{
		cin >> price[i] >> weight[i];
	}

	cin >> peopleNum;

	for (int i = 0; i < peopleNum; ++i)
	{
		cin >> weightCarry[i];
	}

}

void Display()
{
	cout << maxFamilyHome << endl;
}

int main(int argc, char const *argv[])
{
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);

	int test;
	cin >> test;

	while(test--)
	{
		ReadCase();
		Solve();
		Display();
	}

	return 0;
}
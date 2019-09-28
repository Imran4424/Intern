#include <iostream>
using namespace std;

const int mSize = 1001, pSize = 101;
const int wMax = 33;

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

int MaxSubSum(int i, int capacity)
{
	if (-1 != dpPrice[i][capacity])
	{
		return dpPrice[i][capacity];
	}

	if (i == objectNum)
	{
		return dpPrice[i][capacity] = 0;
	}

	int left = MaxSubSum(i+1, capacity);

	int right;

	if (capacity >= weight[i])
	{
		right = MaxSubSum(i+1, capacity - weight[i]) + price[i];
	}
	else
	{
		right = 0;
	}

	if (left >= right)
	{
		return dpPrice[i][capacity] = left;
	}
	
	return dpPrice[i][capacity] = right;
}

void Solve()
{
	// Clearing for test cases
	maxFamilyHome = 0;
	Init();

	for (int i = 0; i < peopleNum; ++i)
	{
		maxCarryWeight = weightCarry[i];

		maxFamilyHome += MaxSubSum(0, maxCarryWeight);
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

	//Init();

}

void Display()
{
	cout << maxFamilyHome << endl;
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
		Solve();
		Display();
	}

	return 0;
}
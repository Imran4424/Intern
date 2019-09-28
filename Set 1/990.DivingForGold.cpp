#include <iostream>
using namespace std;

const int tSize = 32;
const int highCap = 1001;

int picked[tSize];
int binary[tSize];

int totalTime, pathConstant;
int treasureNum;
int depth[tSize], tCount[tSize];

int tObjectCount, maxProfit;

bool firstElement;

void Init()
{
	for (int i = 0; i < tSize; i++)
	{
		binary[i] = 0;
		picked[i] = 0;
	}
}

void PathUpdate()
{
	// for each call
	tObjectCount = 0;

	for (int i = 0; i < treasureNum; ++i)
	{
		if (binary[i])
		{
			tObjectCount++;
		}

		picked[i] = binary[i];
	}
}

void FindMaxTreasure(int i, int currentCap, int pSum)
{
	if (i == treasureNum)
	{
		if (pSum > maxProfit)
		{
			maxProfit = pSum;
			PathUpdate();
		}

		return;
	}

	binary[i] = 0;
	FindMaxTreasure(i + 1, currentCap, pSum);

	if (currentCap >= pathConstant * depth[i])
	{
		binary[i] = 1;
		FindMaxTreasure(i + 1, currentCap - (pathConstant * depth[i]), pSum + tCount[i]);
	}
}

void ReadCase()
{
	//cin >> totalTime >> pathConstant;

	pathConstant = pathConstant * 3; // 1 for down, 2 for up, 2 + 1 = 3

	cin >> treasureNum;

	for (int i = 0; i < treasureNum; ++i)
	{
		cin >> depth[i] >> tCount[i];
	}

}

void Display()
{
	// clearing for test cases
	maxProfit = 0;
	Init();

	if (firstElement)
	{
		firstElement = false;
	}
	else
	{
		cout << endl;
	}

	FindMaxTreasure(0, totalTime, 0);

	cout << maxProfit << endl;

	cout << tObjectCount << endl;

	for (int i = 0; i < treasureNum; ++i)
	{
		if (picked[i])
		{
			cout << depth[i] << " " << tCount[i] << endl;
		}
	}

}

int main(int argc, char const *argv[])
{
	//freopen("input.txt","r", stdin);
	//freopen("output.txt", "w", stdout);

	firstElement = true;

	while (cin >> totalTime >> pathConstant)
	{
		ReadCase();
		Display();
	}

	return 0;
}
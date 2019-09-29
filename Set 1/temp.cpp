#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int mSize = 21;
const int wSize = 201;

int luggages[mSize];
int dpWeight[mSize][wSize];

int totalSum, totalObject, minDiff;

void Init()
{
	for (int i = 0; i <= totalObject; ++i)
	{
		for (int j = 0; j <= totalSum; ++j)
		{
			dpWeight[i][j] = -1;
		}
	}
}


int FindMinDiff(int i, int currentSum)
{
	if (-1 != dpWeight[i][currentSum])
	{
		return dpWeight[i][currentSum];
	}

	if (i == totalObject)
	{
		int otherhalf = totalSum - currentSum;

		if(currentSum == otherhalf)
		{
			return dpWeight[i][currentSum] = 0;
		}

		return dpWeight[i][currentSum] = 5;
	}

	int left = FindMinDiff(i+1, currentSum);

	int right = FindMinDiff(i+1, currentSum + luggages[i]);

	if (left < right)
	{
		return dpWeight[i][currentSum] = left;
	}

	return dpWeight[i][currentSum] = right;
}

void ReadCase()
{
	char num[3];
	char ch;

	int x = 0;
	totalSum = 0;

	while(scanf("%s %c", &num, &ch) == 2)
	{
		totalSum += atoi(num);
		luggages[x++] = atoi(num);

		if (' ' != ch)
		{
			break;
		}
	}

	totalObject = x;

	for (int i = 0; i < totalObject; ++i)
	{
		cout << luggages[i] << " ";
	}

	cout << totalSum << endl;

}

void Display()
{
	if (0 == minDiff)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
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

		minDiff = FindMinDiff(0, 0);

		Display();
	}
	return 0;
}
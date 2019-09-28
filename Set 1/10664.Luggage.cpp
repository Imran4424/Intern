#include <iostream>
using namespace std;

const int mSize = 21;
const int wSize = 201;

int luggages[mSize];
int dpWeight[mSize][wSize];

int totalSum, totalObject;

void Init()
{
	for (int i = 0; i <= totalObject; ++i)
	{
		for (int i = 0; i <= totalSum; ++i)
		{
			dpWeight[i][j] = -1;
		}
	}
}

void ReadCase()
{
	cin >> noskipws;

	int num;
	char ch;

	int x = 0;

	while(cin >> num >> ch)
	{
		totalSum += num;
		luggages[x++] = num;

		if (' ' != ch)
		{
			break;
		}
	}

	totalObject = x;

	cin >> skipws;
}

int main(int argc, char const *argv[])
{
	int test;
	cin >> test;

	while(test--)
	{
		ReadCase();
	}
	return 0;
}
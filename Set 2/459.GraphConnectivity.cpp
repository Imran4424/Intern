#include <iostream>
#include <cstdio>
using namespace std;

const int pSize = 27;

int path[pSize][pSize];	
bool visited[pSize];
char entry;
char first, second;
char inputString[5];

int parentCount;

void Init()
{
	for (int i = 0; i < parentCount; i++)
	{
		visited[i] = false;

		for (int j = 0; j < parentCount; ++j)
		{
			path[i][j] = 0;
		}
	}

	
}


void ReadCase()
{
	gets(inputString);

	entry = inputString[0];
	
	parentCount = (int)(entry - 'A') + 1;
	
	Init(); // clearing test cases

	while (gets(inputString))
	{
		if ('\0' == inputString[0])
		{
			break;
		}
				
		first = inputString[0];
		second = inputString[1];

		int firstIndex = (int)(first - 'A');
		int secondIndex = (int)(second - 'A');

		path[firstIndex][secondIndex] = 1;
		path[secondIndex][firstIndex] = 1;
	}
}

void Display()
{
	cout << parentCount << endl;
}

int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int test;
	// cin >> test;
	scanf("%d", &test);

	getchar();
	getchar();

	while (test--)
	{
		ReadCase();
		Display();

		if (test)
		{
			cout << endl;
		}
	}
}
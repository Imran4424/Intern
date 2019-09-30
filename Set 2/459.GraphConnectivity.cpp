#include <iostream>
#include <cstdio>
using namespace std;

const int pSize = 27;

int parent[pSize];	
bool visited[pSize];
char entry;
char first, second;
char inputString[5];

int parentCount;

void Init()
{
	for (int i = 0; i < parentCount; i++)
	{
		parent[i] = i;
		visited[i] = false;
	}
}

int SearchParent(int vertex)
{
	if (vertex == parent[vertex])
	{
		return vertex;
	}

	return parent[vertex] = SearchParent(parent[vertex]);
}

void Union(int xVertex, int yVertex)
{
	int xParent = SearchParent(xVertex);
	int yParent = SearchParent(yVertex);

	if (xParent != yParent)
	{
		parent[yParent] = xParent;

		parentCount--;
	}
}

void ReadCase()
{
	gets(inputString);

	entry = inputString[0];
	
	int entryIndex = (int)(entry - 'A') + 1;

	parentCount = entryIndex;
	
	Init(); // clearing test cases

	while (gets(inputString))
	{
		if ('\0' == inputString[0])
		{
			break;
		}
				
		// cout << inputString << endl;
		first = inputString[0];
		second = inputString[1];

		int firstIndex = (int)(first - 'A');
		int secondIndex = (int)(second - 'A');

		Union(firstIndex, secondIndex);
		
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
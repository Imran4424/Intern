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
	for (int i = 0; i < pSize; i++)
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

int Union(int xVertex, int yVertex)
{
	int xParent = SearchParent(xVertex);
	int yParent = SearchParent(yVertex);

	if (xParent != yParent)
	{
		parent[yParent] = xParent;

		return 1;
	}

	return 0;
}

void ReadCase()
{
	gets(inputString);

	entry = inputString[0];

	cout << entry << endl;
	
	int entryIndex = (int)(entry - 'A');

	visited[entryIndex] = true;
	parentCount = 1;

	

	while (gets(inputString))
	{
		if ('\0' == inputString[0])
		{
			break;
		}
				
		//cout << inputString << endl;
		first = inputString[0];
		second = inputString[1];

		int firstIndex = (int)(first - 'A');
		int secondIndex = (int)(second - 'A');

		int reducedNum = Union(firstIndex, secondIndex);

		if (!visited[firstIndex] && !visited[secondIndex])
		{
			parentCount++;
			visited[firstIndex] = true;
			visited[secondIndex] = true;
		}
		else if (!visited[firstIndex])
		{
			visited[firstIndex] = true;
		}
		else if (!visited[secondIndex])
		{
			visited[secondIndex] = true;
		}
		else
		{
			parentCount = parentCount - reducedNum;
		}

		//cout << parentCount << " ";
	}
}

void Display()
{
	cout << parentCount << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	bool first = true;

	int test;
	scanf("%d", test);

	while (test--)
	{
		Init();
		getchar();
		getchar();
		ReadCase();
		Display();

		if (test)
		{
			cout << endl;
		}
	}
}
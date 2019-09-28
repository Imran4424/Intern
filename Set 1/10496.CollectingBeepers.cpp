#include <iostream>
using namespace std;

const int pSize = 11;

int boardRow, boardCol;
int posX[pSize], posY[pSize];

int shopX, shopY;
int beeperNum;
int minimumPath;

bool visited[pSize];

int Abs(int x)
{
	if (x < 0)
	{
		return -x;
	}

	return x;
}

void FindMinPath(int i, int index, int pathCost)
{
	if (i == beeperNum)
	{
		pathCost += Abs(posX[index] - shopX) + Abs(posY[index] - shopY);

		if (pathCost < minimumPath)
		{
			minimumPath = pathCost;
		}

		return;
	}

	for (int next = 1; next <= beeperNum; next++)
	{
		if (!visited[next])
		{
			visited[next] = true;

			FindMinPath(i + 1, next, pathCost + Abs(posX[index] - posX[next]) + Abs(posY[index] - posY[next]));
		
			visited[next] = false; // backtrack
		}
	}
}

void Init()
{
	for (int i = 1; i <= beeperNum; i++)
	{
		visited[i] = false;
	}
}

void ReadCase()
{
	cin >> boardRow >> boardCol;

	cin >> shopX >> shopY;

	posX[0] = shopX;
	posY[0] = shopY;

	cin >> beeperNum;

	for (int i = 1; i <= beeperNum; i++)
	{
		cin >> posX[i] >> posY[i];
	}

	// clearing for test cases

	Init();
	minimumPath = 32000;
}

void Display()
{
	cout << "The shortest path has length " << minimumPath << endl;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int test;
	cin >> test;

	while (test--)
	{
		ReadCase();
		FindMinPath(0, 0, 0);
		Display();
	}

	return 0;
}
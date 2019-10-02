#include <iostream>
#include <stdio.h>
using namespace std;

const int rSize = 35;
const int cSize = 85;

char grid[rSize][cSize];
int row;

void FillTravel(int x, int y)
{
	grid[x][y] = '#';

	if (' ' == grid[x - 1][y])
	{
		FillTravel(x - 1, y);
	}

	if (' ' == grid[x + 1][y])
	{
		FillTravel(x + 1, y);
	}

	if (' ' == grid[x][y - 1])
	{
		FillTravel(x, y - 1);
	}

	if (' ' == grid[x][y + 1])
	{
		FillTravel(x, y + 1);
	}
}

void Solve()
{
	for (int i = 0; i <= row; ++i)
	{
		for(int j = 0; grid[i][j] != '0'; j++)
		{
			if ('*' == grid[i][j])
			{
				FillTravel(i, j);

				return;
			}
		}
	}
}

void ReadCase()
{
	row = 0;

	while(gets(grid[row]))
	{
		if('_' == grid[row][0])
		{
			break;
		}

		row++;
	}
}

void Display()
{
	for (int i = 0; i <= row; ++i)
	{
		printf("%s\n", grid[i]);
	}
}

int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int test;
	scanf("%d", &test);

	while(test--)
	{
		ReadCase();
		Display();
	}


	return 0;
}
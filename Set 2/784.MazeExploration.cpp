#include <iostream>
#include <stdio.h>
using namespace std;

const int rSize = 35;
const int cSize = 85;

char grid[rSize][cSize];
int row;


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
	int test;
	scanf("%d", &test);

	while(test--)
	{
		ReadCase();
		Display();
	}


	return 0;
}
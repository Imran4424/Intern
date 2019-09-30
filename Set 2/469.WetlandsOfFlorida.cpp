#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

const int lSize = 100;

char land[100][102];
int xNum;

void ReadCase()
{
	xNum = 0;

	while(gets(land[xNum]))
	{
		if ('L' != land[xNum][0] || 'W' != land[xNum][0])
		{
			break;
		}

		xNum++;
	}
}

int main(int argc, char const *argv[])
{
	int test;
	scanf("%d", &test);

	getchar();
	getchar();

	while(test--)
	{
		ReadCase();
		Display();

		if (test)
		{
			printf("\n");
		}
	}

	return 0;
}
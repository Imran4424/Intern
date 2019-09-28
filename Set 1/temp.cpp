#include <iostream>
using namespace std;

const int maxPrimeNum = 187;
const int maxN = 1121;
const int maxK = 15;
 
int dpCount[maxPrimeNum + 1][maxK][maxN];

int prime[187] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,
	103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,
	223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,
	347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,
	463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,
	607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,
	743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,
	883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997,1009,1013,1019,1021,
	1031,1033,1039,1049,1051,1061,1063,1069,1087,1091,1093,1097,1103,1109,1117};


int targetSum, requiredNum;

int SumCount;

void InitDp()
{
	for (int i = 0; i <= maxPrimeNum; ++i)
	{
		for (int j = 0; j < maxK; ++j)
		{
			for (int k = 0; k < maxN; ++k)
			{
				dpCount[i][j][k] = -1;
			}
		}
	}
}

int FindCount(int i, int currentCount, int currentSum)
{
	if (-1 != dpCount[i][currentCount][currentSum])
	{
		return dpCount[i][currentCount][currentSum];
	}

	if (currentCount == 0)
	{
		if (0 == targetSum)
		{
			return dpCount[i][currentCount][currentSum] = 1;
		}

		return dpCount[i][currentCount][currentSum] = 0;
	}

	// if (prime[i] > targetSum)
	// {
	// 	return dpCount[i][currentCount][currentSum] = 0;
	// }

	if (i == maxPrimeNum)
	{
		return dpCount[i][currentCount][currentSum] = 0;
	}

	int left = FindCount(i + 1, currentCount, currentSum);

	int right;

	if (currentSum >= prime[i])
	{
		right = FindCount(i + 1, currentCount - 1, currentSum - prime[i]);
	}
	else
	{
		right = 0;
	}
	

	return dpCount[i][currentCount][currentSum] = left + right;
}


int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	InitDp();

	cin >> targetSum >> requiredNum;

	while(0 != targetSum && 0 != requiredNum)
	{
		cout << FindCount(0, requiredNum, targetSum) << endl;

		cin >> targetSum >> requiredNum;
	}

	return 0;
}
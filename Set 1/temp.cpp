#include <iostream>
using namespace std;

void ReadCase()
{
	string allNum;

	getline(cin, allNum);

	cout << allNum << endl;
}

int main(int argc, char const *argv[])
{
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);

	int test;
	cin >> test;

	getchar();

	while(test--)
	{
		ReadCase();
	}

	return 0;
}
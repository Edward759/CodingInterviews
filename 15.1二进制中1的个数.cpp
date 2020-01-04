#include<iostream>
using namespace std;

int CountOfBin1(int number)
{
	int cnt = 0;
	int flag = 1;

	while (flag)
	{
		if (number&flag)
			cnt++;

		flag = flag << 1;
	}

	return cnt;
}

int CountOfBin2(int number)
{
	int cnt = 0;
	
	while (number)
	{
		cnt++;
		number = (number - 1)&number;
	}

	return cnt;
}

int main()
{
	cout << CountOfBin1(0) << endl;
	cout << CountOfBin1(1) << endl;

	cout << CountOfBin1(9) << endl;
	cout << CountOfBin1(27) << endl;

	cout << CountOfBin1(-8) << endl;
	cout << CountOfBin1(-1) << endl;

	system("pause");
	return 0;
}
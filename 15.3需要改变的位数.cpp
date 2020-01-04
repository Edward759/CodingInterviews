#include<iostream>
using namespace std;

int change(int m, int n)
{
	int t = m^n;

	int cnt = 0;
	
	while (t)
	{
		cnt++;
		t = (t - 1)&t;
	}

	return cnt;
}

int main()
{
	cout << change(10, 13) << endl;

	system("pause");
	return 0;
}
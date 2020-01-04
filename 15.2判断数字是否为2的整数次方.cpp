#include<iostream>
using namespace std;

bool is2(int n)
{
	if (((n - 1)&n) == 0)
		return true;

	return false;
}

int main()
{
	cout << is2(1) << endl;
	cout << is2(2) << endl;
	cout << is2(3) << endl;
	cout << is2(4) << endl;

	system("pause");
	return 0;
}
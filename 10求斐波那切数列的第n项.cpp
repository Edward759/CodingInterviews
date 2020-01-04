#include<iostream>
using namespace std;

long long Fibonacci(unsigned n)
{
	long long f0 = 0, f1 = 1, f2 = f0 + f1;

	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
	{
		for (unsigned int i = 2; i <= n; ++i)
		{
			f2 = f0 + f1;
			f0 = f1;
			f1 = f2;
		}
		return f2;
	}
}

int main()
{
	unsigned n = 10;

	cout << Fibonacci(5) << endl;

	system("pause");
	return 0;
}
#include<iostream>

using namespace std;

int duplicate(int A[],int n)
{
	int i = 0;

	if (A == nullptr || n <= 0)
		return -1;

	for (i = 0; i < n; ++i)
		if (A[i]<0 || A[i]>n - 1)
			return -1;

	for (i = 0; i < n; ++i)
	{
		while (A[i] != i)
		{
			if (A[i] == A[A[i]])
				return A[i];
			else
			{
				int tmp = A[i];
				A[i] = A[A[i]];
				A[tmp] = tmp;
			}
		}
	}

	return -1;
}

int main()
{
	int A[] = { 4, 6, 0, 2, 5, 3 ,-2};

	int rs = duplicate(A, 7);

	cout << rs << endl;

	system("pause");
	return 0;
}
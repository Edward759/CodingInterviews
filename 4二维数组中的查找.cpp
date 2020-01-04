#include<iostream>
using namespace std;

bool find(int A[], int row, int col, int x)
{
	int i = 0, j = col-1;
	int p=A[row*i + j];

	if (A == nullptr || row < 0 || col<0)
		return false;

	while (i < row && j >= 0)
	{
		p = A[row*i + j];
		if (p > x)
			j--;
		else if (p < x)
			i--;
		else
			return true;
	}
	return false;
}

int main()
{
	int A[] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };

	cout << find(A, 4, 4, 1) << endl;
	cout << find(A, 4, 4, 15) << endl;


	system("pause");
	return 0;
}
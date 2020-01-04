#include<iostream>

using namespace std;

int duplicate(int A[], int length, int n)
{
	int low = 1, high = n;
	int mid,cnt;

	if (A == nullptr || length <= 0 || n != length - 1 )
		return -1;

	while (low <= high)
	{
		mid = (high + low) / 2;
		cnt = 0;
		for (int i = 0; i < length; ++i)
			if (A[i] >= low&&A[i] <= mid)
				cnt++;

		if (low == high)
		{
			if (cnt > 1)
				return low;
			else
				break;
		}

		if (cnt > mid - low + 1)
			high = mid;
		else
			low = mid + 1;
	}
}

int main()
{
	int A[] = { 2, 3, 5, 4, 3, 2, 6, 7 };

	int rs = duplicate(A, 8, 7);

	cout << rs << endl;

	system("pause");

	return 0;
}
#include<iostream>
using namespace std;

int Min(int data[], int length)
{
	if (data == nullptr || length <= 0)
		throw new exception("invalid data");

	int left = 0, right = length - 1, mid = 0;

	if (data[left] < data[right])
		return data[left];

	while (right - 1 > left)
	{
		mid = (left + right) / 2;
		if (data[mid] > data[left])
			left = mid;
		else if (data[left] == data[mid] && data[mid] == data[right])
		{
			for (int i = left+1; i <= right; ++i)
			{
				if (data[i] < data[i - 1] && data[i] < data[i + 1])
					return data[i];
			}
		}
		else
			right = mid;
	}

	return data[right];
}

int main()
{
	int data[] = { 1, 0, 1, 1, 1 };
	int data2[] = { 1, 1, 1, 0, 1 };
	int data3[] = { 1 };
	int data4[] = { 2, 2, 3, 4, 5, 1 };

	cout << Min(data, 5) << endl;
	cout << Min(data2, 5) << endl;
	cout << Min(data3, 1) << endl;
	cout << Min(data4, 6) << endl;

	system("pause");
	return 0;
}
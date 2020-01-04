#include<iostream>
using namespace std;

int RandomInRange(int start, int end)
{
	return rand() % (end - start) + start;
}

void Swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int Partition(int data[], int length, int start, int end)
{
	if (data == nullptr || length <= 0 || start < 0 || end >= length)
		throw new exception("invalid parameters");

	int index = RandomInRange(start, end);
	Swap(&data[index], &data[end]);

	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (data[index] < data[end])
		{
			++small;
			if (data[index] != data[small])
				Swap(&data[index], &data[small]);
		}
	}

	++small;
	Swap(&data[small], &data[end]);

	for (int i = 0; i < length; ++i)
		cout << data[i] << " ";
	cout << endl;

	return small;
}

void QuickSort(int data[], int length, int start, int end)
{
	if (start == end)
		return;

	int index = Partition(data, length, start, end);
	if (index>start)
		QuickSort(data, length, start, index - 1);
	if (index < end)
		QuickSort (data, length, index + 1, end);
}

int main()
{
	int data[] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	QuickSort(data, 8, 0, 7);


	system("pause");
	return 0;
}
#include<iostream>
using namespace std;


//A¡¢BÉýÐò
void Merge(int A[], int B[], int MaxLength)
{
	int pa = 0, pb = 0, p=0;
	int LenA = 0, LenB = 0;

	if (A == nullptr || B == nullptr || MaxLength <= 0)
		return;

	while (A[pa]>0)
	{
		LenA++;
		pa++;
	}

	while (B[pb]>0)
	{
		LenB++;
		pb++;
	}

	pa = LenA - 1;
	pb = LenB - 1;
	p = pa + LenB;
	cout << LenA << ' ' << LenB << endl;
	cout << pa << ' ' << pb << ' ' << p << ' ' << endl;

	if (p > MaxLength)
		return;

	while (pa >= 0 && pb >= 0 && p>=0)
	{
		if (A[pa] > B[pb])
		{
			A[p] = A[pa];
			pa--;
		}
		else
		{
			A[p] = B[pb];
			pb--;
		}
		p--;
	}
}

int main()
{
	int A[10] = { 1, 3, 5, 7 };
	int B[] = { 2, 4, 6, 8 };

	Merge(A, B, 10);

	for (int i = 0; i < 8;++i)
		cout << A[i] << endl;

	system("pause");
	return 0;
}
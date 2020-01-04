#include<iostream>
using namespace std;

void ReplaceBlank(char str[], int MaxLength)
{
	int cnt = 0;
	int OriginalLength = 0;
	int p1 = 0, p2;
	char asc[] = "%20";

	if (str == nullptr || MaxLength <= 0)
		return;

	while (str[p1] != '\0')
	{
		OriginalLength++;
		if (str[p1] == ' ')
			cnt++;
		++p1;
	}

	p1 = OriginalLength - 1;
	p2 = OriginalLength + cnt * 2 - 1;

	if (p2 > MaxLength)
		return;

	while (p1>=0&&p2>=0)
	{
		if (str[p1] != ' ')
		{
			str[p2] = str[p1];
			p2--;
			p1--;
		}
		else
		{
			for (int i = 2; i >= 0; --i)
			{
				str[p2] = asc[i];
				p2--;
			}
			p1--;
		}
		
	}
}

int main()
{
	char str[30] = "We are happy.";

	ReplaceBlank(str, 30);

	cout << str << endl;

	system("pause");
	return 0;
}
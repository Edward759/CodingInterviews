#pragma warning(disable:4996)

#include<string>
#include<iostream>
using namespace std;

class CMyString{
public:
	CMyString(string pData = nullptr);
	//CmyString(const CMyString& str);
	~CMyString(void);

	CMyString& operator=(const CMyString& str);

	void Print();

private:
	char* m_pData;
};

CMyString::CMyString(string pData)
{
	if (pData.empty())
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		int length = pData.length();
		m_pData = new char[length + 1];
		m_pData = pData;
	}
}

void Test1()
{
	char* text = "hello world";

	CMyString str1(text);

	printf("%s", text);
}

int main(int argc,char* argv[])
{
	Test1();

	return 0;
}
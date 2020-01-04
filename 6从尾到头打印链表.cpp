#include<iostream>
#include<stack>
using namespace std;

struct ListNode
{
	int m_nKey;
	ListNode*m_pNext; 
};

void PostPrint_1(ListNode* pHead)
{
	if (pHead == nullptr)
		return;

	int len = 0;
	ListNode* p = pHead;
	stack<ListNode*>nodes;

	while (p!=nullptr)
	{
		nodes.push(p);
		p = p->m_pNext;
	}

	while (!nodes.empty())
	{
		p = nodes.top();
		nodes.pop();
		cout << p->m_nKey << endl;
	}
}

void PostPrint_2(ListNode* pHead)
{
	if (pHead != nullptr)
	{
		if (pHead->m_pNext != nullptr)
			PostPrint_2(pHead->m_pNext);

		cout << pHead->m_nKey << endl;
	}
}

int main()
{
	ListNode*pHead = new ListNode();
	pHead->m_nKey = 1;
	pHead->m_pNext = nullptr;
	ListNode*p = pHead;
	for (int i = 1; i <= 5; ++i)
	{
		ListNode*pNode = new ListNode;
		pNode->m_nKey = i + 1;
		pNode->m_pNext = nullptr;
		p->m_pNext = pNode;
		p = p->m_pNext;
	}

	//p = pHead;
	//while (p)
	//{
	//	cout << p->m_nKey << endl;
	//	p = p->m_pNext;
	//}

	PostPrint_2(pHead);

	system("pause");
	return 0;
}
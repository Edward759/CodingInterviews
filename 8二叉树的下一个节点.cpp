#include<iostream>

using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
};

BinaryTreeNode* GetNext(BinaryTreeNode* pHead, BinaryTreeNode* pNode)
{
	if (pHead == nullptr || pNode == nullptr)
		return nullptr;

	BinaryTreeNode* pNext = new BinaryTreeNode();

	if (pNode->m_pRight != nullptr)
	{
		pNext = pNode->m_pRight;
		while (pNext->m_pLeft)
			pNext = pNext->m_pLeft;

		return pNext;
	}
	if (pNode->m_pRight == nullptr)
	{
		pNext = pNode;
		BinaryTreeNode* pParent = pNode->m_pParent;
		while (pParent!=nullptr&&pParent->m_pRight==pNext)
		{
			pNext = pParent;
			pParent = pParent->m_pParent;
		}
		return pParent;
	}
}

BinaryTreeNode* CreateNode(int value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_nValue = value;
	pNode->m_pLeft = nullptr;
	pNode->m_pRight = nullptr;
	pNode->m_pParent = nullptr;

	return pNode;
}

void ConnectNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pParent != nullptr)
	{
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;

		if (pLeft != nullptr)
			pLeft->m_pParent = pParent;
		if (pRight != nullptr)
			pRight->m_pParent = pParent;
	}
}

int main()
{
	BinaryTreeNode* p1 = CreateNode(1);
	BinaryTreeNode* p2 = CreateNode(2);
	BinaryTreeNode* p3 = CreateNode(3);
	BinaryTreeNode* p4 = CreateNode(4);
	BinaryTreeNode* p5 = CreateNode(5);
	BinaryTreeNode* p6 = CreateNode(6);
	BinaryTreeNode* p7 = CreateNode(7);
	BinaryTreeNode* p8 = CreateNode(8);
	BinaryTreeNode* p9 = CreateNode(9);

	ConnectNodes(p1, p2, p3);
	ConnectNodes(p2, p4, p5);
	ConnectNodes(p3, p6, p7);
	ConnectNodes(p4, p8, p9);

	BinaryTreeNode* rs = GetNext(p1, p8);

	if (rs != nullptr)
		cout << rs->m_nValue << endl;
	else
		cout << "null" << endl;

	system("pause");
	return 0;
}
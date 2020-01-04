#include<iostream>

using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);

BinaryTreeNode* Construct(int * preorder, int* inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;

	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;

	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder&&*startPreorder == *startInorder)
			return root;
		else
			throw exception("Invalid input.");
	}

	int* rootInorder = startInorder;
	while (rootInorder <= endInorder&&*rootInorder != rootValue)
		++rootInorder;

	if (rootInorder == endInorder&&*rootInorder != rootValue)
		throw exception("Invalid input.");
	
	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0)
	{
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder)
	{
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}

	return root;
}

int main()
{
	int preOrder[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inOder[] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	BinaryTreeNode* BT = Rebuild(preOrder, inOder, 0, 7, 0, 7);

	system("pause");
	return 0;
}
#include<iostream>
#include<queue>
using namespace std;

template<typename T>class CStack
{
public:
	CStack(void);
	~CStack(void);
	void appendTail(const T& node);
	T deleteTail();

private:
	queue<T>queue1;
	queue<T>queue2;
};

template<typename T> CStack<T>::CStack(void)
{

}

template<typename T> CStack<T>::~CStack(void)
{

}

template<typename T> void CStack<T>::appendTail(const T& element)
{
	if (!queue1.empty())
		queue1.push(element);
	else
		queue2.push(element);
}

template<typename T> T CStack<T>::deleteTail()
{
	int data = 0;
	if (!queue1.empty())
	{
		while (queue1.size() > 1)
		{
			data = queue1.front();
			queue1.pop();
			queue2.push(data);
		}
		data = queue1.front();
		queue1.pop();
		return data;
	}
	else
	{
		while (queue2.size() > 1)
		{
			data = queue2.front();
			queue2.pop();
			queue1.push(data);
		}
		data = queue2.front();
		queue2.pop();
		return data;
	}

	if (queue1.size() == 0 || queue2.size() == 0)
		throw new exception("queue is empty");
}

int main()
{
	CStack<int>stack;

	stack.appendTail(1);
	stack.appendTail(2);
	stack.appendTail(3);

	int rs1=stack.deleteTail();
	int rs2 = stack.deleteTail();
	int rs3 = stack.deleteTail();

	cout << rs1 << endl;
	cout << rs2 << endl;
	cout << rs3 << endl;

	system("pause");
	return 0;
}
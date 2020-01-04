#include<iostream>
#include<stack>
using namespace std;

template <typename T>class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T& node);
	T deleteHead();

private:
	stack<T>stack1;
	stack<T>stack2;
};

template<typename T>CQueue<T>::CQueue(void)
{

}

template<typename T>CQueue<T>::~CQueue(void)
{

}

template<typename T>void CQueue<T>::appendTail(const T& element)
{
	stack1.push(element);
}

template<typename T>T CQueue<T>::deleteHead()
{
	if (stack2.size() <= 0)
	{
		while (stack1.size()>0)
		{
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}

	if (stack2.size() == 0)
		throw new exception("queue is empty");

	T& head = stack2.top();
	stack2.pop();

	return head;
}

int main()
{
	CQueue<int>queue;

	queue.appendTail(3);
	queue.appendTail(2);
	queue.appendTail(1);

	int rs1 = queue.deleteHead();
	int rs2 = queue.deleteHead();
	int rs3 = queue.deleteHead();
	int rs4 = queue.deleteHead();


	cout << rs3 << endl;

	system("pause");
	return 0;
}
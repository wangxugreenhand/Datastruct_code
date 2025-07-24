#include<iostream>

using namespace std;

struct Node
{
	int val;
	int num;
	Node* link;
	Node(Node* l = NULL, int v = -1, int n =0)
	{
		link = l;
		num = n;
		val = v;
	}
};
class Stack
{
public:
	Node* top;
	Stack() : top(NULL) {}	   //���캯��
	~Stack() { makeEmpty(); }   //��������
	void Push(int x,int y);	//��ջ
	bool Pop(int& x);
	void makeEmpty();
	int gettop1();
	int gettop2();
	//bool empty();

};
void Stack::makeEmpty() {
	//���ɾȥ��ʽջ�е�Ԫ��ֱ��ջ��ָ��Ϊ�ա�
	Node* p;
	while (top != NULL)		//�������ͷ�
	{
		p = top;  top = top->link;  delete p;
	}
};
void Stack::Push(int x,int y) {
	Node* p = new Node;
	p->val = x;
	p->num = y;
	if (top == NULL)
	{
		top = p;
		p->link = NULL;
	}
	else
	{
		p->link = top;
		top = p;
	}
};

bool Stack::Pop(int& x) {
	//ɾ��ջ�����, ���ر�ɾջ��Ԫ�ص�ֵ��

	Node* p = top;		//�ݴ�ջ��Ԫ��
	top = top->link;			//��ջ��ָ��
	x = p->val;   delete p;		//�ͷŽ��
	return true;
};
int Stack::gettop1()
{
	int x = top->val;                       //����ջ��Ԫ�ص�ֵ
	return x;

};
int Stack::gettop2()
{
	int x = top->num;                       //����ջ��Ԫ�ص�ֵ
	return x;

};

int main()
{
	Stack mystack1;
	Stack mystack2;
	int n;
	cin >> n;
	mystack1.Push(-1,-1);
	mystack2.Push(-1, n);
	int* p = new int[n];
	for (int i = 0; i < n; i++)
		cin >> p[i];
	long long res = 0;
	int* l = new int[n];
	int* r = new int[n];
	for (int i = 0; i < n; i++)
	{
		if (p[i] > mystack1.gettop1())
		{
			l[i] = i - mystack1.gettop2();
			mystack1.Push(p[i],i);
		}
			
		else
		{
			while (p[i] <= mystack1.gettop1())
			{
				int t;
				mystack1.Pop(t);
			}
			l[i] = i - mystack1.gettop2();
			mystack1.Push(p[i], i);
		}

	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (p[i] > mystack2.gettop1())
		{
			r[i] = mystack2.gettop2() - i;
			mystack2.Push(p[i],i);
		}
		else
		{
			while (p[i] <= mystack2.gettop1())
			{
				int t;
				mystack2.Pop(t);
			}
			r[i] =  mystack2.gettop2() - i;
			mystack2.Push(p[i], i);
		}
	}

	for (int i = 0; i < n; i++)
	{
		int ans = p[i] * (l[i] + r[i] - 1);
		res = res > ans ? res : ans;
	}
	cout<< res;
}
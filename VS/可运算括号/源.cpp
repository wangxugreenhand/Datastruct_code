#include<iostream>
#include<cstring>

using namespace std;
struct Node
{
	int val;
	char ch;
	Node* link;
	Node(Node* l = NULL,int v = -1, char c = 0)
	{
		link = l;
		ch = c;
		val = v;
	}
};
class Stack
{
public:
	Node* top;
	Stack() : top(NULL) {}	   //���캯��
	~Stack() { makeEmpty(); }   //��������
	void Push(int x);	//��ջ
	bool Pop(int& x);
	void makeEmpty();
	int gettop();
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
void Stack::Push(int x) {
	Node* p = new Node;
	p->val = x;
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
int Stack::gettop()
{
	int x = top->val;                       //����ջ��Ԫ�ص�ֵ
	return x;

}


int main()
{
	Stack mystack;
	mystack.Push(-1);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int max = 0;
	int length = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
			mystack.Push(i);
		else
		{
			if (mystack.gettop()==-1 ||   s[mystack.gettop()] == ')')
			{
				int p;
				mystack.Pop(p);
				mystack.Push(i);
				length = 0;
				continue;
			}
			else
			{
				int p;
				mystack.Pop(p);
				length = i - mystack.top->val;
				max = max > (length) ? max : (length);
			}

		}
	}
	cout << max;
}


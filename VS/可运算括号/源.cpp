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
	Stack() : top(NULL) {}	   //构造函数
	~Stack() { makeEmpty(); }   //析构函数
	void Push(int x);	//进栈
	bool Pop(int& x);
	void makeEmpty();
	int gettop();
	//bool empty();

};
void Stack::makeEmpty() {
	//逐次删去链式栈中的元素直至栈顶指针为空。
	Node* p;
	while (top != NULL)		//逐个结点释放
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
	//删除栈顶结点, 返回被删栈顶元素的值。

	Node* p = top;		//暂存栈顶元素
	top = top->link;			//退栈顶指针
	x = p->val;   delete p;		//释放结点
	return true;
};
int Stack::gettop()
{
	int x = top->val;                       //返回栈顶元素的值
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


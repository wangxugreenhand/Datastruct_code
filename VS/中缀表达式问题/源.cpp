#include<iostream>
using namespace std;


struct Node
{
    int num;
    long long val;
    Node* link;
    char ch;
    Node(Node* l = NULL, long long v = -1, char c = 0, int n = -1)
    {
        link = l; ch = c; val = v; num = n;
    }
};
class Stack
{
public:
    Node* top;
    Stack() : top(NULL) {}	   //构造函数
    ~Stack() { makeEmpty(); }   //析构函数
    void Push1(char x);		
    void Push2(long long x);	//进栈
    bool Pop(Node& x);
    void makeEmpty();
    bool gettop(Node& x);
    int k = 1;

};
void Stack::makeEmpty() {
    //逐次删去链式栈中的元素直至栈顶指针为空。
    Node* p;
    while (top != NULL)		//逐个结点释放
    {
        p = top;  top = top->link;  delete p;
    }
};
void Stack::Push1(char x) {
    Node* p = new Node;
    p->ch = x;
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
    switch (p->ch) {
    case '(': p->num = 1; break;
    case ')': p->num = 10; break;
    case '+':case '-': p->num = 3; break;
    case '*':case '/': case '%': p->num = 5; break;
    case '~': p->num = 8; break;
    case '^': p->num = 7; break;
    default: break;
    }
}
void Stack::Push2(long long x) {
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
}

bool Stack::Pop(Node& x) {
    //删除栈顶结点, 返回被删栈顶元素的值。

    Node* p = top;		//暂存栈顶元素
    top = top->link;			//退栈顶指针
    x = *p;   delete p;		//释放结点
    return true;
};
bool Stack::gettop(Node& x)
{
    x = *top;                       //返回栈顶元素的值
    return true;

}

long long power(long long x, long long y)
{
    long long res = 1;
    for (int i = 1; i <= y; i++)
    {
        res *= x;
    }
    return res;
}

int main()
{
    Stack mystack1, mystack2;
    string s, m;
    cin >> s;
    char temp;
    
    for (int i = 0; i < s.length(); i++)
    {
        char temp;
        temp = s[i];
        if (temp >= 48 && temp <= 57)
            m+=temp;
        else
        {
            Node* p = new Node;
            p->ch = temp;
            switch (p->ch) {
            case '(': p->num = 10; break;
            case ')': p->num = 1; break;
            case '+':case '-': p->num = 2; break;
            case '*':case '/': case '%': p->num = 4; break;
            case '~': p->num = 9; break;
            case '^': p->num = 6; break;
            default: break;
            }
            if (mystack1.top ==NULL)
            {
                mystack1.Push1(p->ch);
              
            }
            else
            {
                if (p->num > mystack1.top->num)
                    mystack1.Push1(p->ch );
                else if (p->num < mystack1.top->num)
                {
                    while (p->num <= mystack1.top->num)
                    {
                        Node q;
                        mystack1.Pop(q);
                        if (p->num == q.num)
                            break;
                        m+= q.ch;
                        if (mystack1.top == NULL)
                            break;
                    }
                    if (p->ch != ')')
                        mystack1.Push1(p->ch);
                }
                else
                {
                    Node q;
                    mystack1.Pop(q);
                }
            }
        }
    }
    while (mystack1.top != NULL)		//逐个结点释放
    {
        m += mystack1.top->ch; Node* p = mystack1.top; mystack1.top = mystack1.top->link;  delete p;
    }
    for (int i = 0; i < m.length(); i++)
    {
        char temp;
        temp = m[i];
        if (temp >= 48 && temp <= 57)
        {
            Node* p = new Node;
            p->val = temp - 48;
            mystack2.Push2(p->val);
        }
        else
        {
            Node r, l, res;
            if (temp == '~')
            {
                mystack2.Pop(r);
                res.val = r.val * -1;
                mystack2.Push2(res.val);
            }
            else
            {
                mystack2.Pop(r);
                mystack2.Pop(l);
                switch (temp)
                {
                case '+':res.val = l.val + r.val; mystack2.Push2(res.val); break;
                case '-':res.val = l.val - r.val; mystack2.Push2(res.val); break;
                case '*':res.val = l.val * r.val; mystack2.Push2(res.val); break;
                case '/':res.val = l.val / r.val; mystack2.Push2(res.val); break;
                    //case '~':res.val = r.val * -1; mystack2.Push2(l.val); mystack2.Push2(res.val); break;
                case '^':res.val = power(l.val, r.val); mystack2.Push2(res.val); break;
                }
            }
        }
    }
    cout << mystack2.top->val;

    
    return 0;
}
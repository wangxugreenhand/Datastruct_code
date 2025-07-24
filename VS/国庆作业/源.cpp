#include<iostream>

using namespace std;

struct Node
{
    int num;
    int val;
    Node* link, * rlink;
    Node(Node* l = NULL, Node* r = NULL, int v = -1, int n = -1)
    {
        link = l;  val = v; num = n; rlink = r;
    }
};
class Stack
{
public:
    Node* top;
    Node* bes;
    Stack() : top(NULL), bes(NULL) {}	   //构造函数
    ~Stack() { makeEmpty(); }
    void Push(int num, int val);		             	   //进栈
    bool Pop();
    bool Pop_fir();
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
void Stack::Push(int num, int val) {
    Node* p = new Node;
    p->val = val;
    p->num = num;
    if (top == NULL)
    {
        top = p;
        bes = p;
        p->link = NULL;
        p->rlink = NULL;
    }
    else
    {
        p->link = top;
        top->rlink = p;
        top = p;
    }

}
bool Stack::Pop() {
    //删除栈顶结点, 返回被删栈顶元素的值。

    Node* p = top;		//暂存栈顶元素
    top = top->link;			//退栈顶指针
    delete p;		//释放结点
    return true;
};
bool Stack::Pop_fir()
{
    Node* p = bes;
    bes = bes->rlink;

    delete p;
    return true;
}
bool Stack::gettop(Node& x)
{
    x = *top;                       //返回栈顶元素的值
    return true;

}


int main()
{
    int t;
    cin >> t;
    int ans[110];
    for (int i = 0; i < t; i++)
    {
        Stack my_stack;
        my_stack.Push(0, 0);
        int n, k;
        cin >> n >> k;
        int* a = new int[n];
        long long b[100003] = { 0 };
        


        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
            b[j + 1] = b[j] + a[j];
        }
        int min = n + 9;

        for (int i = 1; i < n + 1; i++)
        {
            if (b[i] - my_stack.bes->val < k)
            {
                if (b[i] > my_stack.top->val)
                {
                    my_stack.Push(i, b[i]);
                }
                else
                {
                    while (my_stack.top != NULL && b[i] <= my_stack.top->val)
                    {
                        my_stack.Pop();
                    }
                    my_stack.Push(i, b[i]);
                }
            }
            else       
            {
                while (my_stack.bes != NULL && b[i] - my_stack.bes->val >= k)
                {
                    if (i - my_stack.bes->num <= min)
                        min = i - my_stack.bes->num;
                    my_stack.Pop_fir();
                }
                my_stack.Push(i, b[i]);
            }
        }
        if (min == n + 9)
            ans[i] = -1;
        else         
            ans[i] = min;
       
    }
    for (int i = 0; i < t; i++)
        cout << ans[i] << endl;


   
    return 0;
}
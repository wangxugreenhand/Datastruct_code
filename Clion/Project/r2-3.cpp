#include<iostream>
using namespace std;
int a[10005] = {0};
int b[10005] = {0};
struct Node{
    int val;
    Node* left;
    Node* right;
    int flag;
    Node* par;
    Node():val(0),left(NULL),right(NULL),flag(0),par(NULL){}
};
Node* head = NULL;

int a_num = 1;

Node* queue[10005];
int back = 0,front = 0;
void push_back(Node* x)
{
    queue[back++] = x;
}
void pop_front(Node* &x)
{
    x = queue[front];
    front++;
}
bool empty()
{
    return front == back;
}



void creat_tree(int l, int r, Node* &p,Node* &pp)
{
    if(l > r)
        return ;
    Node* q = new Node;
    q->val = a[a_num];
    p = q;
    p->par = pp;
    int i;
    for( i = l;i <= r;i++)
    {
        if(b[i] == a[a_num])
            break;
    }
    a_num++;
    creat_tree(l,i-1,p->left,p);
    creat_tree(i+1,r,p->right,p);

}


int main()
{
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++)
        cin>>a[i];
    for(int i = 1;i<=n;i++)
        cin>>b[i];
    Node* qq = NULL;
    creat_tree(1,n,head,qq);
    Node* p = head;

    push_back(p);
    //int t = 1;
    int c = -1;
    while(!empty())
    {
        Node* te;
        pop_front(te);
        if(te->flag > c )
        {
            cout << te->val << " ";

            c += 1;
        }
        if(te->left !=NULL)
        {
            te->left->flag = te->flag+1;
            push_back(te->left);

        }
        if(te->right != NULL) {
            te->right->flag = te->flag+1;
            push_back(te->right);
        }

    }



    return 0;
}
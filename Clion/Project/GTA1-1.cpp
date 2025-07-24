#include<iostream>
using namespace std;
struct Node{
    int val;
    Node* l;
    Node(int v):val(v),l(NULL){}
};
Node* a[10001] = {NULL};
int d[10001] = {0};
bool vis[10001] = {false};
int cnt = 0;

Node* getnext( Node* p)
{
    if(p->l == NULL)
        return NULL;
    else
        return p->l;
}
Node* getfirst(int x)
{
    return a[x];
}
void dfs(int x)
{
    vis[x] = true;
    d[x] = cnt;
    for(Node* p = getfirst(x);p != NULL; p = p->l)
    {
        if(!vis[p->val])
            dfs(p->val);
    }

}
int main()
{
    int n,m;
    cin>>n>>m;
    int x,y;
    for(int i = 1;i<= m;i++)
    {
        cin>>x>>y;
        Node* p1 = new Node(y);
        if(a[x] == NULL)
            a[x] = p1;
        else
        {
            Node* q = a[x];
            while(q->l)
                q = q->l;
            q->l = p1;
        }
        Node* p2 = new Node(x);
        if(a[y] == NULL)
            a[y] = p2;
        else
        {
            Node* q1 = a[y];
            while(q1->l)
                q1 = q1->l;
            q1->l = p2;
        }
    }

    for(int i = 1; i<=n;i++ )
    {
        if(!vis[i])
        {
            cnt++;
            dfs(i);
        }
    }
    cout<<cnt;
    return 0;
}
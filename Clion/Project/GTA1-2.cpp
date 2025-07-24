#include<iostream>
#include "cmath"
using namespace std;

struct Node{
    int val;
    Node* l;
    Node(int v):val(v),l(NULL){}
};
Node* a[10001] = {NULL};
bool vis[10001] = {false};
int d[10001] = {0};
int low[10001] = {0};
bool Judge[10001] = {false};
int parent[10001] = {0};
int children[10001] = {0};
int num = 0;


Node* getfirst(int x)
{
    return a[x];
}
void DFSCV(int u, int t)
{
    t++;
    d[u] = t;
    low[u] = d[u];
    vis[u] = true;
    for(Node* p = getfirst(u);p != NULL; p = p->l)
    {
        int v = p->val;
        if(!vis[v]) {
            parent[v] = u;
            children[u]++;
            DFSCV(v,t);
            low[u] = min(low[u],low[v]);
            if(parent[u] == 0 && children[u] >= 2) { Judge[u] = true ;}
            else if(parent[u] != 0&& low[v]>= d[u]) { Judge[u] = true;}
        }
        else if(v != parent[u])
            low[u] = min(low[u],d[v]);


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
            DFSCV(i,0);
        }
    }

    for(int i = 1;i<= n;i++)
    {
        if(Judge[i])
            num++;
    }
    cout<<num<<endl;
    for(int i = 1;i<= n;i++)
    {
        if(Judge[i])
            cout<<i<<endl;
    }
    return 0;
}
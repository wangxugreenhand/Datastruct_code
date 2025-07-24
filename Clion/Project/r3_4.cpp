#include<iostream>
#define max_ INT32_MAX
using namespace std;

struct Edge{
    int v;
    int w;
    Edge* link;
    Edge():v(-1),w(1),link(NULL){}
    Edge(int v1)
    {
        v = v1;
        w = 1;
        link = NULL;
    }
};
struct Node{
    bool flag;
    Edge* head;
    Node():flag(NULL),head(NULL){}
};

Node a[200005];
int dfn[200005] = {0};
int index = 1;
int low[200005] = {0};
bool vis[200005] = {0};
int dist[200005] = {0};

int stack[200005] = {-1};
int top = 0;
void  push(int i)
{
    stack[top++] = i;
}
void pop()
{
    top--;
}
bool empty()
{
    return (top==0);
}

int min_(int x, int y)
{
    return (x>y)?y:x;
}

void tarjan(int u)
{
    push(u);
    dfn[u] = low[u] = index++;
    vis[u] = true;
    Edge * p = a[u].head;
    while(p)
    {
        if(!dfn[p->v]) {
            tarjan(p->v);
            low[u] = min_(low[u],low[p->v]);
        }
        else if(vis[p->v])
        {
            low[u] = min_(low[u],low[p->v]);
        }
        p = p->link;
    }
    if(dfn[u] == low[u])
    {
        while(stack[top-1] != u)
        {
            vis[stack[top-1]] = false;
            a[stack[top-1]].flag = true;
            pop();

        }
        a[stack[top-1]].flag = true;
        pop();
        vis[u] = false;
    }
}
extern void dijkstra(int v,int num);

int main()
{
    int n,m,x;
    cin>>n>>m>>x;
    int u,v;
    for(int i = 1;i<= m;i++)
    {
        cin>>u>>v;
        Edge* p = new Edge(v);
        Edge* q = new Edge(u);
        p->link = a[u].head;
        a[u].head = p;
        q->link = a[v].head;
        a[v].head = q;
    }
    for(int i = 1;i<=n;i++)
    {
        if(!dfn[i])
            tarjan(i);
    }
    dijkstra(x,n);
    int min = max_;
    for(int i = 1;i<=n;i++)
    {
        if(i != x && a[i].flag && dist[i] < min)
        {
            min = dist[i];
        }
    }
    if(min == max_)
        cout<<"-1";
    else
        cout<<min;
    return 0;
}
void dijkstra(int v,int num)
{
    int min,i,j,k;
    bool* s = new bool[num];
    for(i = 1;i<=num;i++) {
        dist[i] = max_;
        s[i] = false;
    }
    Edge* p = a[v].head;
    while(p)
    {
        dist[p->v] = p->w;
        p = p->link;
    }
    s[v] = true;
    dist[v] = 0;
    for(i = 1;i< num;i++)
    {
        min = max_;
        int u = v;
        for(j = 1;j<=num;j++)
        {
            if(!s[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }
        s[u] = true;
        p = a[u].head;
        while(p)
        {
            if(!s[p->v] && dist[u] + p->w < dist[p->v])
                dist[p->v] = dist[u] + p->w;
            p = p->link;
        }
    }
}
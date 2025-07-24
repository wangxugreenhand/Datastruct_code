#include<iostream>
using  namespace  std;

int n,m;
int a[10005][10005] = {0};

int co[10005] = {0};
struct Node{
    int num;
    int id;
    Node():num(0),id(10005){}
};
Node nn[10005];
int col = 1;

int dfn[10005] = {0};
int low[10005] = {0};
bool vis[10005] = {0};

int stack[10005] = {-1};
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
int index = 1;
int min_(int x, int y)
{
    return (x>y)?y:x;
}
int getnext(int i,int j)
{
    for(int p = j+1;p<n;p++)
    {
        if(a[i][p])
            return p;
    }
    return -1;
}
void tarjan(int u)
{
    push(u);
    dfn[u] = low[u] = index++;
    vis[u] = true;
    int w = getnext(u,-1);
    while(w != -1)
    {
        if(!dfn[w]) {
            tarjan(w);
            low[u] = min_(low[u],low[w]);
        }
        else if(vis[w])
        {
            low[u] = min_(low[u],low[w]);
        }
        w = getnext(u, w);
    }
    if(dfn[u] == low[u])
    {
        co[u] = col;
        while(stack[top-1] != u)
        {
            co[stack[top-1]] = col;
            vis[stack[top-1]] = false;
            pop();
        
        }
        pop();
        vis[u] = false;
        col++;
    }
}

int main()
{

    cin>>n>>m;
    int x,y;
    for(int i = 0;i<m;i++)
    {
        cin>>x>>y;
        a[x][y] = 1;
    }
    for(int i = 0;i<n;i++)
    {
        if(!dfn[i])
            tarjan(i);
    }

    int max_ = 0;
    int m_max = -1;
    for(int i =0;i<n;i++)
    {
        int s = co[i];
        nn[s].num++;
        if(i < nn[s].id)
            nn[s].id = i;
        if(nn[s].num > max_)
        {
            max_ = nn[s].num;
            m_max = s;
        }
        if(nn[s].num == max_  && nn[s].id < nn[m_max].id)
            m_max = s;
    }
    for(int i = 0;i<n;i++)
    {
        if(co[i] == m_max)
            cout<<i<<" ";
    }


    return 0;
}
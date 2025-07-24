#include<iostream>
#include<algorithm>
#include "vector"
#include "map"
#include "set"
using namespace std;
//全局变量
int n,m;
bool flag = false;
vector<int> G[101];
int a[101][101] = {0};
struct Edge{
    int u,v;
    Edge():u(0),v(0){}
    bool operator < (const Edge &e) const {
        if(u == e.u) return v < e.v;
        return u < e.u;
    }
};
Edge edge[2001];
set<int> P;
set<Edge> E;

//DFS
bool vis[101] = {false};
int fa[101] = {0};
int temp = 0;
//函数声明

void DFS(int u);

int main()
{
    cin>>n>>m;
    for(int i = 0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
        edge[i].u = u;
        edge[i].v = v;
        a[u][v] = 1;
        a[v][u] = 1;
    }
    DFS(1);
    P.insert(temp);
    while(P.size() <= n || E.size()<= m)
    {
        
    }

    return 0;
}
void DFS(int u) {
    vis[u] = true;
    for (int i = 0; i < G[u].size() && !flag; i++) {
        int v = G[u][i];
        if (!vis[v]) {
            fa[v] = u;
            DFS(v);
        } else if (v != fa[u]) {
            temp = v;
            flag = true;
        }
    }
    if (temp != u) {
        P.insert(u);
        Edge e;
        e.u = u;
        e.v = fa[u];
        E.insert(e);
        a[u][fa[u]] = 2;
        a[fa[u]][u] = 2;
    }
}



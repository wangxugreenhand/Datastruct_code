#include<iostream>
#include<string.h>
using namespace std;

//struct Edge{
//    int v1;
//    int v2;
//    int weight;
//    Edge* link1;
//    Edge* link2;
//    Edge():v1(-1),v2(-1),weight(0),link1(NULL),link2(NULL){}
//};
//
//struct V{
//    int data;
//    Edge* firstout;
//    Edge* firstin;
//    V():data(0),firstout(NULL),firstin(NULL){}
//};
//
//V a[1005];


int a[1005][1005] = {0};
int b[1005][1005] = {0};
int n,m;
int dist[1005] = {0};

void short_path_1()
{
    bool s[1005] = {false};
    int i,j,k;
    for( i = 1;i<=n;i++)
    {
        dist[i] = (a[1][i] == 0)?10005:a[1][i];
        s[i] = false;
    }
    s[1] = true;
    dist[1] = 0;
    int min;
    for(i = 2;i<= n;i++)
    {
        min = 10005;
        int t = 1;
        for(j = 1; j<= n; j++)
            if(!s[j] && dist[j] < min){
                t = j;
                min = dist[j];
            }
        s[t] = true;
        for(k = 1;k<= n; k++)
        {
            int wei = (a[t][k] == 0)?10005:a[t][k];
            if(!s[k] && wei < 10005 && dist[t] + wei < dist[k]){
                dist[k] = dist[t] + wei;
            }
        }
    }
}

void short_path()
{
    memset(dist,0,1005);
    bool *s = new bool[n];
    int i,j,k;
    for( i = 1;i<=n;i++)
    {
        dist[i] = (b[1][i] == 0)?10005:b[1][i];
        s[i] = false;
    }
    s[1] = true;
    dist[1] = 0;
    int min;
    for(i = 2;i<= n;i++)
    {
        min = 10005;
        int t = 1;
        for(j = 1; j<= n; j++)
            if(!s[j] && dist[j] < min){
                t = j;
                min = dist[j];
            }
        s[t] = true;
        for(k = 1;k<= n; k++)
        {
            int wei = (b[t][k] == 0)?10005:b[t][k];
            if(!s[k] && wei < 10005 && dist[t] + wei < dist[k]){
                dist[k] = dist[t] + wei;
            }
        }
    }
}


int main()
{

    cin>>n>>m;
//    for(int i =1;i <= n;i++)
//        a[i].data = i;
//    for(int i = 1;i<=m;i++)
//    {
//        int u,v,w;
//        cin>>u>>v>>w;
//        Edge* p = a[u].firstout;
//        while(p != NULL)
//            p = p->link1;
//        p = new Edge;
//        p->weight = w;
//        p->v1 = u;
//        p->v2 = v;
//    }
    for(int i = 1;i<=m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = w;
        b[v][u] = w;
    }
    short_path_1();
    long long sum = 0;
    for(int i = 1;i<=n;i++)
        sum+=dist[i];
    short_path();
    for(int i = 1;i<=n;i++)
        sum+=dist[i];

    cout<<sum;
    return 0;
}
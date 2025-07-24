#include<iostream>
#define max_ INT32_MAX
using namespace std;
struct Edge{
    int v;
    int w;
    Edge* link;
    Edge():v(-1),w(0),link(NULL){}
    Edge(int v1,int w1)
    {
        v = v1;
        w = w1;
        link = NULL;
    }
};
struct Node{
    int count;
    Edge* head;
    Node():count(0),head(NULL){}
};

Node a[1005];
int dist[1005] = {0};
extern void dijkstra(int v,int num);
int main()
{
    int n,m,k;
    int time = 0;
    cin>>n>>m>>k;
    int u1,v1,w1;
    for(int i = 1;i<=m;i++)
    {
        cin>>u1>>v1>>w1;
        Edge* p = new Edge(v1,w1);
        p->link = a[u1].head;
        a[u1].head = p;
    }
    dijkstra(k,n);
    for(int i = 1; i<= n;i++)
    {
        if(i == k)
            continue;
        else
        {
            if(dist[i] == max_)
            {
                time = -1;
                break;
            }
            else if(dist[i] > time)
                time = dist[i];
        }
    }
    cout<<time;
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
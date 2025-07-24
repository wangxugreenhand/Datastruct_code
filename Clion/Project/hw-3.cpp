#include<iostream>
using namespace std;
#define max_ INT32_MAX
struct Edge{
    int e;
    int time;
    int p1;
    int p2;
    Edge* link;
    Edge():e(0),time(0),p1(0),p2(0),link(NULL){}
    Edge(int n,int days,int pp1,int pp2)
    {
        e = n;
        time = days;
        p1 =pp1;
        p2 = pp2;
        link = NULL;
    }
};
Edge* a[10005] = {NULL};
long long dist[10005];
extern void dijkstra(int v,int num);
int main()
{
    int n,m;
    cin>>n>>m;
    int n1,n2,days,p1,p2;
    for(int i = 1; i<=m;i++)
    {
        cin>>n1>>n2>>days>>p1>>p2;
        Edge* p = new Edge(n2,days,p1,p2);
        Edge* q = new Edge(n1,days,p1,p2);
        p->link = a[n1];
        a[n1] = p;
        q->link = a[n2];
        a[n2] = q;
    }
    dijkstra(1,n);
    cout<<dist[n];
    return 0;
}
void dijkstra(int v,int num)  //dijkstra算法
{
    int min,i,j,k;
    bool* s = new bool[num];
    for(i = 1;i<=num;i++) {
        dist[i] = max_;
        s[i] = false;
    }
    Edge* p = a[v];
    while(p)
    {
        if(p->time < p->p1)
            dist[p->e] = 1 + p->time;
        else
            dist[p->e] = p->p2+ 1 + p->time;
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
        p = a[u];
        //下面的内容开始与传统算法有所区别
        while(p)
        {
            if(!s[p->e])
            {
                //  可以替换的情况罗列，包括时间更小，以及不可跨越维修时间段。
                if((dist[u] + p->time > p->p1 && dist[u] + p->time <= p->p2) || (dist[u] >p->p1  && dist[u] <= p->p2))
                {
                    if((p->p2 + 1 + p->time) < dist[p->e])
                        dist[p->e] =  p->p2 + 1 + p->time;
                }


                else if(dist[u] + p->time  < dist[p->e])
                    dist[p->e] = dist[u] + p->time;

            }
            p = p->link;

        }
    }

}
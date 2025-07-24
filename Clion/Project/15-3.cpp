#include<iostream>
#include <cstring>
using namespace std;
#define MAX 1000000000;
//struct Edge{
//    int v1;
//    int v2;
//    int w;
//    Edge():v1(-1),v2(-1),w(0){}
//};
//
//Edge edge[5000];

int a[100][100] = {0};
//int b[100][100] = {0};
int d1[100] = {0};
//int d2[100] = {0};
int n1[100] = {1};
//int n2[100] = {1};

void shortPath1(int n,int v,int p,int dst)
{
    bool* s = new bool[n];
    int i,j,min;
    for(i = 0;i<n;i++)
    {
        d1[i] = (a[v][i]!=0)?a[v][i]:MAX;
        s[i] = false;
    }
    s[v] = true;
    d1[v] = 0;
    n1[v] = 0;
    for(i = 0;i<n-1;i++)
    {
        min = 1000000001;
        int u = v;
        for(j = 0;j<n;j++)
        {
            if(!s[j] && d1[j] < min)
            {
                u = j;
                min = d1[j];
            }
        }
        s[u] = true;
        for(int k = 0;k<n;k++)
        {
            int w = (a[u][k]!=0)?a[u][k]:MAX;
            if(!s[k] && w < 1000000000 && d1[u] + w < d1[k] && (( k ==dst  && n1[u]<=p) || (k !=dst && n1[u]<p)))
            {
                d1[k] = d1[u] + w;
                n1[k] = n1[u] + 1;
            }

        }
    }
    delete[]s;
}



int main()
{
    int src,dst,k;
    cin>>src>>dst>>k;
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++)
    {
        int from,to,time;
        cin>>from>>to>>time;
        a[from][to] = time;
    }
    int res = 0;
    for(int i = 0;i< 100;i++)
        n1[i] = 1;
    shortPath1(n,src,k,dst);
    //shortPath2(n,dst);
    if(d1[dst] == 1000000000 &&  n1[dst] == 1)
        cout<<"-1";
    else if(n1[dst] <= k + 2)
        cout<<d1[dst];
    


    return 0;
}

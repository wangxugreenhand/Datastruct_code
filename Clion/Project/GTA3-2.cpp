#include<iostream>
#include <climits>
#include<cstring>
#include<algorithm>
#include "cmath"
#include<queue>
#define max_ LONG_LONG_MAX
using namespace std;

int n,m,s,t;
long long Edge[201][201] = {0};
long long f[201] = {0};
queue<int> q;

long long BFS()
{
    while(!q.empty())
        q.pop();

}
int main()
{
    cin>>n>>m>>s>>t;
    for(int i = 0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        Edge[u][v] = w;
    }
    long long ext = max_;
    long long res = 0;
    while(1)
    {
        int Pre[201] = {0};
        ext = BFS();
        if(ext == -1)break;
        else
        {
            res += ext;
            int b = t;
            while(b != s)
            {
                int p = Pre[b];
                Edge[p][b] -= ext;
                Edge[b][p] += ext;
                b = Par[b];
            }
        }
    }

    cout << res;
    return 0;
}
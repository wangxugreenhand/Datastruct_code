#include<iostream>
#include<algorithm>
#include "vector"
using namespace std;
vector<int> X[1001];
vector<int> Y[1001];

bool vis_y[1001] = {false};
int Match[1001] = {0};

int DFSAP(int v)
{
    for(int i = 0; i< X[v].size();i++)
    {
        int r = X[v][i];
        if(vis_y[r] == false) {
            vis_y[r] = true;
            if(Match[r] == 0 || DFSAP(Match[r]) == 1 ) {
                Match[r] = v;
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    int n,m,e;
    int res = 0;
    cin >> n >> m >> e;
    for(int i = 0; i < e; i++)
    {
        int x,y;
        cin >> x >> y;
        X[x].push_back(y);
        Y[y].push_back(x);
    }
    for(int i = 1; i<= n;i++)
    {
        for(int i =1; i<=n;i++)
            vis_y[i] = false;
        int j = DFSAP(i);
        res+= j;
    }
    cout<<res;
    return 0;
}
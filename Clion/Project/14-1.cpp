#include<iostream>
using namespace std;

int fa[100005] = {0};//存储父节点
int Rank[100005] = {0};
int num[100005] = {0};

inline void init(int n)
{
    for (int i = 0; i < n; ++i)
    {
        fa[i] = i;
        Rank[i] = 1;
    }
}
int find(int x)
{
    if(x == fa[x])
        return x;
    else{
        fa[x] = find(fa[x]);  //父节点设为根节点
        return fa[x];         //返回父节点
    }
}
inline void merge(int i, int j)
{
    int x = find(i), y = find(j);
    if (Rank[x] <= Rank[y])
        fa[x] = y;
    else
        fa[y] = x;
    if (Rank[x] == Rank[y] && x != y)
        Rank[y]++;
}


int main()
{
    int n,m;
    cin>>n>>m;
    int res = -1;
    int **a = new int*[m];
    for(int i = 0;i<m;i++)
    {
       a[i] = new int(2);
    }
    for(int i = 0;i<m;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    if(m < n - 1)
        cout<<"-1";
    else
    {
        init(n);
        for(int i = 0;i<m;i++)
        {
            merge(a[i][0],a[i][1]);
        }
        for(int j = 0;j<n;j++)
        {
            num[find(j)]= 1;
        }
        for(int j = 0;j<n;j++)
        {
            if(num[j])
                res++;
        }
        cout<<res;
    }

    return 0;

}
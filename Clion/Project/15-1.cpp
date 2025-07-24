#include<iostream>
using  namespace  std;

//int a[10005][10005] = {0};

bool vis[10005] = {0};
int n,m;
int fa[1005] = {0};//存储父节点
int Rank[1005] = {0};
int num[1005] = {0};

inline void init(int n)
{
    for (int i = 1; i <= n; ++i)
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
//    if (Rank[x] <= Rank[y])
//    {
//        fa[x] = y;
//    }
//    else {
//        fa[y] = x;
//    }
//    if (Rank[x] == Rank[y] && x != y)
//        Rank[y]++;
    x = (x >y)?x:y;//x is the maxer
    y = x+y - x;
    fa[x] = y;

}



int main()
{

    cin>>n>>m;
    int x,y;
    init(n);
    for(int i = 0;i<m;i++)
    {
        cin>>x>>y;
        //a[x][y] = 1;
        //a[y][x] = 1;
        if(find(x) != find(y))
            merge(x,y);
    }
    int max = 0;
    int m_num = -1;
    for(int i = 0;i<n;i++)
    {
        if(fa[i] != i)
            continue;
        if(num[i] > max)
        {
            max = num[i];
            m_num = i;
        }
    }

    for(int i = 0;i<n;i++)
        cout<<i<<" ";



    return 0;
}
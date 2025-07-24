//是并查集

int fa[2005] = {0};//存储父节点
int Rank[2005] = {0};

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
    if (Rank[x] <= Rank[y])
        fa[x] = y;
    else
        fa[y] = x;
    if (Rank[x] == Rank[y] && x != y)
        Rank[y]++;
}


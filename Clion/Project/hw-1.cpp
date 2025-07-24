#include<iostream>
using namespace std;

int a[1005][1005];//储存原始数据

int num[1000005];//并查集的元素个数，记录在根节点对应元素上，若不是根节点，则最终为0；
int fa[1000005] = {0};//存储父节点
int Rank[1000005] = {0};//每个并插接根节点对应的树的高度，用于优化merge操作
//以下为并查集的初始化、寻找父节点、合并操作，结合上面定义的num和Rank数组
inline void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        Rank[i] = 1;
        num[i] = 1;
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
//merge函数中，高度小的树并到高度大的树上，若一样高，则后者并到前者的树上
inline void merge(int i, int j)
{
    int x = find(i), y = find(j);
    if(x == y)
        return;
    if (Rank[x] < Rank[y])
    {
        fa[x] = y;
        num[y]+=num[x];
        num[x] = 0;
    }
    else {
        fa[y] = x;
        num[x]+= num[y];
        num[y] = 0;
    }
    if (Rank[x] == Rank[y] && x != y)
        Rank[x]++;
}

int main()
{
    //输入初始化
    int dif[4] = {0};//记录填充的岛屿周围四个地方若是岛屿，他们的父节点，用于判断周围的岛屿是否在同一并查集里
    int n;
    int res = 0,temp = 0;// res是最终输出答案；temp是设置的一个变量，用于表示变海为岛屿后增加的1。
    cin>>n;
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
            cin >> a[i][j];
    // 初始化并查集
    init(n*n);
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(a[i][j] && a[i+1][j])
                merge(((i-1) * n +j),(i*n +j));
            if(a[i][j] && a[i][j+1])
                merge(((i-1) * n +j),((i-1)*n +j + 1));
        }
    }//遍历矩阵，初始化相连的岛屿，将其归并到一个并查集中

    //下面是主要操作，遍历，逐渐将res替换为更大的值，其中会有变海为岛的操作
    int father = 0;
    bool flag = false;//判断是否会有全是岛屿的情况，若是，则flag为false
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            //对每一个不是岛屿的地方都尝试将其变为岛屿后，去看此时该岛屿与周围的岛屿组成的大岛屿的面积，与res比较
            if(a[i][j] == 0)
            {
                flag = true;
                temp = 1;
                //下面分别看周围四个地方是否是岛屿，若是，记录其父节点，看是否要逐一将其所述并查集个数加到temp上
                if(a[i+1][j])
                {
                    father = find(i*n+j);
                    dif[0] = father;//记录父节点，便于判断其他周围岛屿是否与其同属一个并查集
                    temp+=num[father];//将该岛屿所属并查集的点的数量加到temp上
                }
                if(a[i][j+1])
                {
                    father = find((i-1)*n+j+1);
                    if(dif[0] != father)//看是否属于已经加过的并查集
                    {
                        dif[1] = father;
                        temp+=num[father];
                    }
                    else
                        dif[1] = dif[0];
                }
                if(a[i-1][j])
                {
                    father = find((i-2)*n+j);
                    if(father != dif[0] && father != dif[1])//看是否属于已经加过的并查集
                    {
                        dif[2] = father;
                        temp+=num[father];
                    }
                    else
                        dif[2] = dif[1];

                }
                if(a[i][j-1])
                {
                    father = find((i-1)*n+j-1);
                    if(father != dif[0] && father != dif[1] && father != dif[2])//看是否属于已经加过的并查集
                    {
                        dif[3] = father;
                        temp+=num[father];
                    }
                    else
                        dif[3] = dif[2];
                }
                res = (temp>res)?temp:res;//temp是此时暂时的结果，与res比较，看是否要替换
                temp = 0;//再将其清零
            }
        }
    }
    if(!flag)
        cout<<n*n;//n*n全是岛屿的情况
    else
        cout<<res;
    return 0;
}

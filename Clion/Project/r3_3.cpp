#include<iostream>
#define max_ INT32_MAX
using namespace std;
struct Node{
    int x;
    int y;
    Node():x(-1),y(-1){}
};
Node a[505];
int b[501][501] = {0};

int fa[508] = {0};//存储父节点
int Rank[505] = {0};

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



struct Edge{
    int v1;
    int v2;
    double dis;
    Edge():v1(0),v2(0),dis(0){}
};

Edge heap[200000];
int currentsize = 0;


void siftDown2(int start, int m)
{
    int i = start, j = 2 * i + 1;
    Edge temp = heap[i];
    while (j <= m) {
        if (j < m && heap[j].dis > heap[j + 1].dis) j++;
        if (temp.dis <= heap[j].dis) break;
        else { heap[i] = heap[j]; i = j; j = 2 * j + 1; }
    }
    heap[i] = temp;
}
void siftUp2(int start)
{
    int j = start, i = (j - 1) / 2;
    Edge temp = heap[j];
    while (j > 0) {
        if (heap[i].dis <= temp.dis) break;
        else { heap[j] = heap[i]; j = i; i = (i - 1) / 2; }
    }
    heap[j] = temp;
}

bool insert2(int x,int y) {
    heap[currentsize].v1 = x;
    heap[currentsize].v2 = y;
    heap[currentsize].dis = b[x][y];
    siftUp2(currentsize);
    currentsize++;
    return  true;
}
bool remove2() {
    heap[0] = heap[currentsize - 1];
    currentsize--;
    siftDown2(0, currentsize - 1);
    return true;
}


int heap_[505] = { 0 };

int currentsize_ = 0;


void siftDown(int start, int m)
{
    int i = start, j = 2 * i + 1;
    int temp = heap_[i];
    while (j <= m) {
        if (j < m && heap_[j] < heap_[j + 1]) j++;
        if (temp >= heap_[j]) break;
        else { heap_[i] = heap_[j]; i = j; j = 2 * j + 1; }
    }
    heap_[i] = temp;
}
void siftUp(int start)
{
    int j = start, i = (j - 1) / 2;
    int temp = heap_[j];
    while (j > 0) {
        if (heap_[i] >= temp) break;
        else { heap_[j] = heap_[i]; j = i; i = (i - 1) / 2; }
    }
    heap_[j] = temp;
}

bool insert(double x) {
    heap_[currentsize_] = x;
    siftUp(currentsize_);
    currentsize_++;
    return  true;
}
bool remove() {

    heap_[0] = heap_[currentsize_ - 1];
    currentsize_--;
    siftDown(0, currentsize_ - 1);
    return true;
}




int distance(int i, int j)
{
    int x1 = (a[i].x>a[j].x)?a[i].x:a[j].x;
    int y1 = (a[i].y>a[j].y)?a[i].y:a[j].y;
    int x2 = a[i].x + a[j].x - x1;
    int y2 = a[i].y + a[j].y - y1;
    return (x1 - x2 + y1 - y2);
}
int main()
{
    int n;
    cin>>n;
    init(505);
    int x1,y1;
    int res;
    int max = 0;
    for(int i =1;i<=n;i++)
    {
        cin>>x1>>y1;
        a[i].x = x1;
        a[i].y = y1;
    }
    for(int i =1;i<=n;i++)
        for(int j = i+1;j<= n;j++)
        {
            int dis =distance(i,j);
            b[i][j] = dis;
            b[j][i] = dis;
        }
    for(int u = 1; u<= n;u++)
    {
        for(int v= u+1;v <= n; v++)
        {
            insert2(u,v);
        }
    }
    int count = 1;
    while(count < n)
    {
        int u_ = find(heap[0].v1);
        int v1 = heap[0].v1;
        int v2 = heap[0].v2;
        int v_ = find(heap[0].v2);
        remove2();
        if(u_ != v_)
        {
            merge(u_,v_);
            insert(b[v1][v2]);
            count++;
        }
    }
    max = heap_[0];



    if(max % 2 == 0)
        res = max / 2;
    else
        res = max / 2 + 1;

    cout<<res;

    return 0;
}

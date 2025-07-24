#include<iostream>
using namespace  std;
#include<cmath>

struct Node{
    int x;
    int y;
    float dis;
    int flag;
    Node():x(0),y(0),dis(0),flag(1){}
};
Node stu[100005];
double dis[505][505] = {0};


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
    heap[currentsize].dis = dis[x][y];
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

double heap_[505] = { 0 };

int currentsize_ = 0;


void siftDown(int start, int m)
{
    int i = start, j = 2 * i + 1;
    double temp = heap_[i];
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
    double temp = heap_[j];
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



double distance(int i ,int j)
{
    double s = sqrt(pow((stu[i].x - stu[j].x),2) +pow((stu[i].y - stu[j].y) ,2));
    return s;
}

int main() {
    int s, p;
    init(505);
    cin >> s >> p;
    for(int i = 1;i<=p;i++)
        cin>>stu[i].x>>stu[i].y;

    for(int i = 1;i<=p;i++)
    {
        for(int j = i+1;j<=p;j++)
        {
            dis[i][j] = distance(i,j);
            //dis[j][i] = dis[i][j];
        }
    }
    for(int u = 1; u<= p;u++)
    {
        for(int v= u+1;v <= p; v++)
        {
            insert2(u,v);
        }
    }
    int count = 1;
    while(count < p)
    {
        int u_ = find(heap[0].v1);
        int v1 = heap[0].v1;
        int v2 = heap[0].v2;
        int v_ = find(heap[0].v2);
        remove2();
        if(u_ != v_)
        {
            merge(u_,v_);
            insert(dis[v1][v2]);
            count++;
        }
    }
    for(int i = 1;i<= s-1;i++)
    {
        remove();
    }
    std::printf("%.2f",heap_[0]);

    return 0;
}
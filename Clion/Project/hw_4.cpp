#include<iostream>
using namespace std;

struct Node{
    int type;
    int x;
    int y;
    int z;
    Node():type(0),x(-1),y(-1),z(-1){}
};
Node a[200005];  //场景描述记录

struct Good{
    int seller;    //商品目前的销量
    int time;      //商品上次被买的时间 ，时间越大，表明越近时被人买
    bool ex;       //商品是否被进货
    int time_id;   //商品在以时间为序的最小堆中的位置；
    int sell_id;   //商品在以销量为序的最小堆的位置
    Good():seller(0),time(-1),ex(false),time_id(-1),sell_id(-1){}
};
Good g[100005];   //最多100000个货物种类

bool less_(int i,int j)   //用于比较两个货物的销量大小，其中包含了二者销量相同时，比较时间
{
    if(g[i].seller < g[j].seller)
        return true;
    if(g[i].seller == g[j].seller  && g[i].time < g[j].time )
        return true;
    return false;
}

//最小堆的实现,用于销量的排序；
int heap2[10005] = { -1 };
int currentsize2 = 0;
void siftDown2(int start, int m)   //siftdown和siftup使用的是ppt上的函数
{
    int i = start, j = 2 * i + 1;
    int temp = heap2[i];
    while (j <= m) {
        if (j < m && less_(heap2[j+1],heap2[j])) j++;
        if (less_(temp,heap2[j])) break;
        else { heap2[i] = heap2[j];g[heap2[j]].sell_id = i; i = j; j = 2 * j + 1; }
    }
    heap2[i] = temp;
    g[temp].sell_id = i;    //其中对应位置随着交换数据也要改变
}
void siftUp2(int start)
{
    int j = start, i = (j - 1) / 2;
    int temp = heap2[j];
    while (j > 0) {
        if (less_(heap2[i],heap2[j])) break;
        else {
            heap2[j] = heap2[i];
            g[heap2[i]].sell_id = j;
            j = i; i = (i - 1) / 2; }
    }
    heap2[j] = temp;
    g[temp].sell_id = j;
}

bool insert2(int x) {      //插入货物，选择放在尾段，然后siftup
    heap2[currentsize2] = x;
    g[x].sell_id = currentsize2;
    siftUp2(currentsize2);
    currentsize2++;
    return  true;
}
bool remove2(int &x) {   //取堆顶并且删掉堆顶
    x = heap2[0];
    heap2[0] = heap2[currentsize2 - 1];
    g[heap2[currentsize2 - 1]].sell_id = 0;
    currentsize2--;
    siftDown2(0, currentsize2 - 1);
    return true;
}
bool remove2_random(int x)   //当在另一个堆删除堆顶时，在本堆中删除相应的元素，位置不一定在堆顶。
{
    heap2[x] = heap2[currentsize2-1];
    g[heap2[currentsize2-1]].sell_id = x;  //选择将该位置与尾段交换
    currentsize2--;
    int j = (x - 1) / 2;
    if(x > 0 && less_(heap2[x],heap2[j]))  //交换后节点对应值小于父亲节点，进行siftup
        siftUp2(x);
    else
        siftDown2(x,currentsize2-1);   //交换后节点对应值大于父亲节点，进行siftdown
    return true;
}


//最小堆的实现,用于销售时间的排序
int heap1[10005] = { -1 };
int currentsize1 = 0;
void siftDown1(int start, int m)
{
    int i = start, j = 2 * i + 1;
    int temp = heap1[i];
    while (j <= m) {
        if (j < m && g[heap1[j]].time > g[heap1[j + 1]].time) j++;
        if (g[temp].time <= g[heap1[j]].time) break;
        else { heap1[i] = heap1[j];g[heap1[j]].time_id = i; i = j; j = 2 * j + 1; }
    }
    heap1[i] = temp;
    g[temp].time_id = i;
}
void siftUp1(int start)
{
    int j = start, i = (j - 1) / 2;
    int temp = heap1[j];
    while (j > 0) {
        if (g[heap1[i]].time <= g[temp].time) break;
        else { heap1[j] = heap1[i];g[heap1[i]].time_id = j; j = i; i = (i - 1) / 2; }
    }
    heap1[j] = temp;
    g[temp].time_id = j;
}

bool insert1(int x) {
    heap1[currentsize1] = x;
    g[x].time_id = currentsize1;
    siftUp1(currentsize1);
    currentsize1++;
    return  true;
}
bool remove1(int &x) {
    x = heap1[0];
    heap1[0] = heap1[currentsize1 - 1];
    g[heap1[currentsize1-1]].time_id = 0;
    currentsize1--;
    siftDown1(0, currentsize1 - 1);
    return true;
}
bool remove1_random(int x)
{
    heap1[x] = heap1[currentsize1-1];
    g[heap1[currentsize1-1]].time_id = x;
    currentsize1--;
    int j = (x - 1) / 2;
    if(x > 0 && g[heap1[x]].time < g[heap1[j]].time)
        siftUp1(x);
    else
        siftDown1(x,currentsize1-1);
    return true;

}

//快排
//extern void Quicksort(int left, int right);
//extern int Partition(int low,int high);
int main()
{

    int n,m;
    cin>>n>>m;
    int cnt = 0;
    int t;
    for(int i =1;i<= m;i++)
    {
        cin>>t;
        if(t == 1)
            cin>>a[i].x;
        else
            cin>>a[i].y>>a[i].z;
        a[i].type = t;
    }  //初始化输入

    for(int i = 1;i<=m;i++)
    {
        if(a[i].type == 1)  //顾客购买商品
        {
            int now = a[i].x;
            if(!g[now].ex)
            {
                cout<<"-1"<<" ";
            }
            else
            {
                g[now].seller++;
                g[now].time = i; //用时间的数量，即 i 来代表时间
                siftDown1(g[now].time_id,currentsize1 - 1);
                siftDown2(g[now].sell_id,currentsize2 - 1);
            }
        }
        else if(!g[a[i].y].ex)
        {
            if(cnt < n)  //货物种类不足n时
            {
                cnt++;
                int yes = a[i].y;
                g[yes].ex = true;
                g[yes].time = i;
                g[yes].seller = 0;
                insert2(yes);
                insert1(yes);
            }
            else                   //要剔除货物
            {
                int r ;
                if(a[i].z == 1)  //按照时间进行剔除，相应的堆是heap1
                    remove1(r);
                else            //按照时间进行剔除，相应的堆是heap2
                    remove2(r);
                int yes = a[i].y;
                cout<<r<<" ";

                g[r].time = -1;  //对要删除的元素清空数据
                g[r].seller = 0;
                g[r].ex = false;

                g[yes].ex = true;
                g[yes].time = i;
                g[yes].seller = 0;
                if(a[i].z == 1)  //如果是按照时间顺序删除，还需要在heap2中删除对应元素
                {
                    int q = g[r].sell_id; //q是r元素在heap2中的位置
                    remove2_random(q);
                }
                else             //情况相反，同理
                {
                    int q = g[r].time_id;
                    remove1_random(q);
                }
                insert2(yes);  //最后再两个堆中插入新元素
                insert1(yes);
            }
        }
    }
    int size = 0;
    for(int i = 0;i<100001;i++)  //顺序输出已经进货的货物种类
    {
        if(g[i].ex) {
            cout << i << " ";
            size++;
            if(size == n)
                break;
        }
    }
    return 0;
}

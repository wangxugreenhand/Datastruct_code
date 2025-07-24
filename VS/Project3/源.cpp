#include<iostream>
using namespace std;

struct Good {
    int seller;    //商品目前的销量
    int time;      //商品上次被买的时间 ，时间越大，表明越近时被人买
    bool ex;       //商品是否被进货
    int time_id;   //商品在以时间为序的最小堆中的位置；
    int sell_id;   //商品在以销量为序的最小堆的位置
    Good() :seller(0), time(-1), ex(false), time_id(-1), sell_id(-1) {}
};
Good g[100005];   //最多100000个货物种类
//type为1是time，为2是sell
int MinHeap_time[10005] = { -1 };
int MinHeap_sell[10005] = { -1 };
int CurrentSize_time = 0;
int CurrentSize_sell = 0;

extern bool less_(int i, int j);
extern bool insert(int x, int type);
extern void siftUp(int start, int type);
extern void siftDown(int start, int m, int type);

int main()
{
    int n, m;
    cin >> n >> m;
    int type, x, y, z;
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> x;
            if (g[x].ex == false)
                cout << "-1" << " ";
            else
            {
                g[x].time = i;
                g[x].seller++;
                siftDown(g[x].time_id, CurrentSize_time - 1, 1);
                siftDown(g[x].sell_id, CurrentSize_sell - 1, 2);
            }
        }
        else
        {
            cin >> y >> z;
            if (g[y].ex)
                continue;
            g[y].ex = true;
            g[y].time = i;
            g[y].seller = 0;
            if (cnt == n)
            {
                int id = -1;
                if (z == 1)
                {
                    id = MinHeap_time[0];
                    cout << id << " ";
                    MinHeap_time[0] = y;
                    g[y].time_id = 0;
                    siftDown(0, CurrentSize_time - 1, 1);
                    MinHeap_sell[g[id].sell_id] = y;
                    g[y].sell_id = g[id].sell_id;
                    int par = (g[id].sell_id - 1) / 2;
                    if (g[id].sell_id > 0 && less_(y, MinHeap_sell[par]))
                        siftUp(g[id].sell_id, 2);
                    else
                        siftDown(g[id].sell_id, CurrentSize_sell - 1, 2);
                }
                else
                {
                    int id = MinHeap_sell[0];
                    cout << id << " ";
                    MinHeap_sell[0] = y;
                    g[y].sell_id = 0;
                    siftDown(0, CurrentSize_sell - 1, 2);
                    MinHeap_time[g[id].time_id] = y;
                    g[y].time_id = g[id].time_id;
                    siftDown(g[id].time_id, CurrentSize_time - 1, 1);
                }
                g[id].ex = false;
                g[id].seller = 0;
                g[id].time = -1;
                g[id].sell_id = -1;
                g[id].time_id = -1;
            }
            else
                cnt++;
        }
    }
    int num = 0;
    for (int i = 0; i < 100001; i++)
    {
        if (g[i].ex) {
            cout << i << " ";
            num++;
            if (num == n)
                break;
        }

    }
    return 0;
}
bool less_(int i, int j)
{
    bool res = false;
    if (g[i].seller < g[j].seller)
        res = true;
    else if (g[i].seller == g[j].seller)
        res = (g[i].time < g[j].time);
    return res;
}
bool insert(int x, int type) {      //插入货物，选择放在尾段，然后siftup
    if (type == 1) {
        MinHeap_time[CurrentSize_time] = x;
        g[x].time_id = CurrentSize_time;
        siftUp(CurrentSize_time, type);
        CurrentSize_time++;
        return true;
    }
    else
    {
        MinHeap_sell[CurrentSize_sell] = x;
        g[x].sell_id = CurrentSize_sell;
        siftUp(CurrentSize_sell, type);
        CurrentSize_sell++;
        return true;
    }
}
void siftUp(int start, int type)
{
    int j = start, i = (j - 1) / 2;
    if (type == 1)
    {
        int temp = MinHeap_time[j];
        while (j > 0)
        {
            if (g[temp].time > g[i].time)break;
            else
            {
                MinHeap_time[j] = MinHeap_time[i];
                g[MinHeap_time[j]].time_id = j;
                j = i;
                i = (j - 1) / 2;
            }
        }
        MinHeap_time[j] = temp;
        g[temp].time_id = j;
    }
    else
    {
        int temp = MinHeap_sell[j];
        while (j > 0)
        {
            if (less_(MinHeap_sell[i], temp))break;
            else
            {
                MinHeap_sell[j] = MinHeap_sell[i];
                g[MinHeap_sell[j]].sell_id = j;
                j = i;
                i = (j - 1) / 2;
            }
        }
        MinHeap_sell[j] = temp;
        g[temp].sell_id = j;
    }
}
void siftDown(int start, int m, int type)
{
    int i = start, j = 2 * start + 1;
    if (type == 1)
    {
        int temp = MinHeap_time[i];
        while (j <= m)
        {
            if (j < m && g[MinHeap_time[j]].time > g[MinHeap_time[j + 1]].time)j++;
            if (g[temp].time < g[MinHeap_time[j]].time) break;
            else {
                MinHeap_time[i] = MinHeap_time[j];
                g[MinHeap_time[i]].time_id = i;
                i = j;
                j = 2 * j + 1;
            }
            MinHeap_time[i] = temp;
            g[temp].time_id = i;
        }
    }
    else
    {
        int temp = MinHeap_sell[i];
        while (j <= m)
        {
            if (j < m && less_(MinHeap_sell[j + 1], MinHeap_sell[j]))j++;
            if (less_(temp, MinHeap_sell[j])) break;
            else {
                MinHeap_sell[i] = MinHeap_sell[j];
                g[MinHeap_sell[i]].sell_id = i;
                i = j;
                j = 2 * j + 1;
            }
            MinHeap_sell[i] = temp;
            g[temp].sell_id = i;
        }
    }
}

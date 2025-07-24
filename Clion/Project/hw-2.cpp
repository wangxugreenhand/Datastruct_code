#include<iostream>
using namespace std;

int a[1000005];

//最小堆的实现
int heap2[1000005] = { 0 };
int currentsize2 = 0;
void siftDown2(int start, int m)
{
    int i = start, j = 2 * i + 1;
    int temp = heap2[i];
    while (j <= m) {
        if (j < m && heap2[j] > heap2[j + 1]) j++;
        if (temp <= heap2[j]) break;
        else { heap2[i] = heap2[j]; i = j; j = 2 * j + 1; }
    }
    heap2[i] = temp;
}
void siftUp2(int start)
{
    int j = start, i = (j - 1) / 2;
    int temp = heap2[j];
    while (j > 0) {
        if (heap2[i] <= temp) break;
        else { heap2[j] = heap2[i]; j = i; i = (i - 1) / 2; }
    }
    heap2[j] = temp;
}

bool insert2(int x) {
    heap2[currentsize2] = x;
    siftUp2(currentsize2);
    currentsize2++;
    return  true;
}
bool remove2(int &x) {
    x = heap2[0];
    heap2[0] = heap2[currentsize2 - 1];
    currentsize2--;
    siftDown2(0, currentsize2 - 1);
    return true;
}

//最大堆的实现
int heap1[1000005] = { 0 };
int currentsize1 = 0;
void siftDown1(int start, int m)
{
    int i = start, j = 2 * i + 1;
    int temp = heap1[i];
    while (j <= m) {
        if (j < m && heap1[j] < heap1[j + 1]) j++;
        if (temp >= heap1[j]) break;
        else { heap1[i] = heap1[j]; i = j; j = 2 * j + 1; }
    }
    heap1[i] = temp;
}
void siftUp1(int start)
{
    int j = start, i = (j - 1) / 2;
    int temp = heap1[j];
    while (j > 0) {
        if (heap1[i] >= temp) break;
        else { heap1[j] = heap1[i]; j = i; i = (i - 1) / 2; }
    }
    heap1[j] = temp;
}

bool insert1(int x) {
    heap1[currentsize1] = x;
    siftUp1(currentsize1);
    currentsize1++;
    return  true;
}
bool remove1(int &x) {
    x = heap1[0];
    heap1[0] = heap1[currentsize1 - 1];
    currentsize1--;
    siftDown1(0, currentsize1 - 1);
    return true;
}
//取上天花板函数
int floor_(int i, int j)
{
    int res = i / j;
    if(i % j != 0)
        res++;
    return res;
}

int main()//heap1是最大堆，heap2是最小堆
{
    int m,n;
    cin>>m>>n;
    int rank,res;
    for(int i =1;i<=n;i++)
        cin>>a[i];
    for(int i= 1;i<=n;i++)
    {
        //处理最为特殊的情况，即n==1的情况，此时直接将a[1]插入最小堆，res也是a[1]
        if(i == 1)
        {
            rank = 1;
            res = a[1];
            insert2(a[1]);
        }
        //处理不是第一次的情况
        else
        {
            int temp = floor_(i,m);//取上天花板，看是要第几高评分的
            if(temp == rank  &&  a[i] <= res)
                insert1(a[i]);//名词和之前一致，并且新的酒店评分较低，不产生影响

            //处理名次提高，并且新的评分低于之前选择的评分，将新的酒店插入最大堆
            //然后将最大堆的堆顶溢出并且插入到最小堆
            else if((temp - rank) == 1 && a[i] <= res)
            {
                insert1(a[i]);
                remove1(res);
                insert2(res);
                rank = temp;
            }
            //名次不变，但是新的酒店评分更高
            else if(temp == rank && a[i] > res)
            {
                remove2(res);
                insert2(a[i]);
                insert1(res);
                res = heap2[0];
            }
            //名次加一，新的酒店评分高于之前选择的酒店
            else if((temp - rank) == 1 && a[i] > res)
            {
                insert2(a[i]);
                rank = temp;
            }

        }
        cout<<res<<" ";
    }
    return 0;
}

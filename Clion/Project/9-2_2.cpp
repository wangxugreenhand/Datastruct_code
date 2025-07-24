#include<iostream>
using namespace std;

int num[400005] = {0};
int a[200005] = {0};
struct Node{
    int val;
    int parent;
    int leftchild;
    int rightchild;
    Node():val(0),parent(0),leftchild(0),rightchild(0){}
};

Node tree[400005];

int get_layer(long long x)
{
    int layer = 1;
    long long temp = 1;
    long long sum = 1;
    while(sum < x)
    {
        temp *= 2;
        sum+=temp;
        layer++;
    }
    return layer;

}
long long pow_2(int x)
{
    long long res = 1;
    for(int i = 1;i<= x;i++)
        res *= 2;
    return res;
}


int main()
{
    long long res = 0;
    int n,k;
    cin>>n>>k;
    for(int i = 1;i<= 2 *n +1;i++){
        cin>>num[i];
    }
    for(int i =1;i<=n;i++)
        cin>>a[i];
    long long fast =2,slow = 1;
    int p = 1;
    int val_num = 2;
    //接下构建树，树用struct数组表示,先处理第一个
    tree[1].val = a[1];
    tree[1].leftchild = num[2];
    tree[1].rightchild = num[3];
    //处理下面2n个
    while(fast <= 2*n +1)
    {
        if(num[fast] == -1)
        {
            p++;
            if(p == 3)
            {
                p = 1;
                slow++;
            }
        }
        else
        {
            tree[val_num].val = a[num[fast]];
            if(p == 1)
            {
                tree[slow].leftchild = num[fast];
                p++;
                tree[val_num].parent = slow;
            }
            else if(p == 2)
            {
                tree[slow].rightchild = num[fast];
                tree[val_num].parent = slow;
                p = 1;
                slow++;
            }
            val_num++;
        }
        fast++;
    }
    while(n > 1)
    {
        if(tree[n].val % k == 0)
        {
            res+=tree[n].val / k;
            tree[tree[n].parent].val += tree[n].val;
        }
        else
        {
            res+= tree[n].val / k+1;
            tree[tree[n].parent].val += tree[n].val;
        }
        n--;
    }




    cout<<res;
    return 0;
}


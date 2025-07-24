#include<iostream>
using namespace std;

struct Node{
    int val;
    int parent;
    int leftchild;
    int rightchild;
    int sum;
    Node():val(0),parent(0),leftchild(0),rightchild(0),sum(0){}
};
int num[200005] = {0};
int t[1000001] = {0};
Node tree[200005];

int main()
{
    int n;
    int res = 0;
    //int num_ = 0;
    int max = -1;

    cin>>n;
    for(int i = 1;i<= 2 *n+1;i++)
        cin>>num[i];

    long long fast =2,slow = 1;
    int p = 1;
    int val_num = 2;
    tree[1].val = num[1];
    tree[1].leftchild = (num[2] == -1 ?-1:2);
    tree[1].rightchild = (num[3] == -1 ?-1:3);
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
            tree[val_num].val = num[fast];
            if(p == 1)
            {
                tree[slow].leftchild = val_num;
                p++;
                tree[val_num].parent = slow;
            }
            else if(p == 2)
            {
                tree[slow].rightchild = val_num;
                tree[val_num].parent = slow;
                p = 1;
                slow++;
            }
            val_num++;
        }
        fast++;
    }
    for(int j = n;j>0;j--)
    {
        tree[j].sum+=tree[j].val;
        if(tree[j].rightchild != 0)
            tree[j].sum+= tree[tree[j].rightchild].sum;
        if(tree[j].leftchild != 0)
            tree[j].sum+= tree[tree[j].leftchild].sum;

    }
    for(int i = 1;i<= n; i++)
    {
        t[tree[i].sum]++;
        if(t[tree[i].sum] > max) {
            max = t[tree[i].sum];
            res = tree[i].sum;
        }
    }



    cout<<res<<" "<<max;
    return 0;
}
#include<iostream>

using namespace  std;

struct Node{
    int val;
    int parent;
    int leftchild;
    int rightchild;
    int flor;
    Node():val(0),parent(0),leftchild(0),rightchild(0),flor(0){}
};

int num[400005] = {0};
Node tree[400005];
int flag = 1;

int max_(int x, int y)
{
    return (x>y?x:y);
}
void judge(int n)
{
    for(int i = n;i>=1;i--)
    {
        tree[i].flor = max_(tree[tree[i].leftchild].flor , tree[tree[i].rightchild].flor) + 1;
        if(tree[i].leftchild != 0 && tree[tree[i].leftchild].val >= tree[i].val )
        {
            flag = 0;
            break;
        }
        if(tree[i].rightchild != 0 && tree[tree[i].rightchild].val <= tree[i].val )
        {
            flag = 0;
            break;
        }
        if(tree[tree[i].leftchild].flor - tree[tree[i].rightchild].flor > 1  || tree[tree[i].leftchild].flor - tree[tree[i].rightchild].flor < -1 ) {
            flag = 0;
            break;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i = 1;i<= n*2+1 ; i++)
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

    judge(n);



    if(flag)
        cout<<"yes";
    else
        cout<<"no";

    return 0;
}

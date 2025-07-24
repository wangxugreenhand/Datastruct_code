//建树！！！  贪心算法


#include<iostream>

using namespace  std;

int num[400005] = {0};
struct Node{
    int id;
    int parent;
    int leftchild;
    int rightchild;
    int flag;
    Node():id(-1),parent(0),leftchild(0),rightchild(0),flag(0){}
};

Node tree[200005];//是真正的树。

int main()
{
    int n;
    int res = 0;
    cin>>n;
    for(int i = 1;i<= 2*n+1;i++)
        cin>>num[i];
    long long fast =2,slow = 1;
    int p = 1;
    int val_num = 2;
    tree[1].id = num[1];
    tree[1].leftchild = num[2];
    tree[1].rightchild = num[3];
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
            tree[val_num].id = num[fast];
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
    for(int i = 1 ;i<= n;i++)
    {
        if(tree[i].leftchild == -1)
            tree[i].leftchild = 0;
        if(tree[i].rightchild == -1)
            tree[i].rightchild = 0;
    }
    while(n>0)
    {
        if(tree[n].flag == 0)
        {
            res++;
            tree[tree[n].parent].flag = 1;
            tree[tree[tree[n].parent].leftchild].flag = 1;
            tree[tree[tree[n].parent].rightchild].flag = 1;
            tree[tree[tree[n].parent].parent].flag = 1;
        }


        n--;
    }



    cout<<res;
    return 0;
}
//有一个非常棒的建树套路！！！、按层次遍历，且不是完全二叉树


#include<iostream>
 using namespace  std;

//int a[200005] = {0};
int num[400005] = {0};//放的是输入的树的值

struct Node{
    int id;
    int parent;
    int leftchild;
    int rightchild;
    Node():id(-1),parent(0),leftchild(0),rightchild(0){}
};

Node tree[200005];//是真正的树。

int get_sum1(int id_)
{
    if(tree[id_].id == -1)
        return 0;
    int sum = 1;
    sum+= get_sum1(tree[id_].leftchild);
    sum+= get_sum1(tree[id_].rightchild);
    return sum;

}

int main()
{
    int n,x;
    cin>>n>>x;
    int flag =1;
    for(int i = 1; i<= 2*n + 1;i++)
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

    int id_ = 0;
    for(int i = 1;i<=n;i++)
    {
        if(tree[i].id == x)
            id_ = i;
    }
    //计算改点及其子树的节点个数
    int sum = get_sum1(id_);
    if(sum * 2 >= n)
    {
        sum = get_sum1(tree[id_].leftchild);
        if(sum * 2 <= n)
        {
            sum = get_sum1(tree[id_].rightchild);
            if(sum *2 <= n)
                flag = 0;
        }
    }

    if(flag)
        cout<<"true";
    else
        cout<<"false";



}

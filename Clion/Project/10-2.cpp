#include<iostream>

using namespace  std;
struct Pair
{
    int val1;
    int val2;
    Pair():val1(0),val2(0){}
};

Pair p[10005];
//构造并查集
struct Node
{
    int *p;
    int riv;
    Node():p(NULL),riv(0){}
};
int b[2005] = {0};
Node a[2005];

int main()
{
    int n,k;
    cin>>n>>k;
    int flag = 1;
    int cur = 1;

    for(int i = 1;i<= k;i++)
        cin>>p[i].val1>>p[i].val2;
    for(int i = 1;i<=n;i++)
    {
        b[i] = i;
    }

    for(int i = 1;i<= k;i++)
    {
        if(p[i].val1 == p[i].val2)
            continue;
        if(a[p[i].val1].p == NULL && a[p[i].val2].p == NULL)
        {
            a[p[i].val1].p = &b[cur];
            cur++;
            a[p[i].val1].riv = cur;
            a[p[i].val2].p = &b[cur];
            a[p[i].val2].riv = cur-1;
            cur++;
        }
        else if(a[p[i].val1].p == NULL)
        {
            a[p[i].val1].p = &b[a[p[i].val2].riv];
            a[p[i].val1].riv = a[p[i].val2].p - &b[0];
        }
        else if(a[p[i].val2].p == NULL)
        {
            a[p[i].val2].p = &b[a[p[i].val1].riv];
            a[p[i].val2].riv = a[p[i].val1].p - &b[0];
        }
        else
        {
            if(*a[p[i].val1].p == *a[p[i].val2].p)
            {
                flag = 0;
                break;
            }
            else
            {
                *a[p[i].val1].p = b[a[p[i].val2].riv];
                b[a[p[i].val1].riv] = *a[p[i].val2].p;
            }
        }
    }


    if(flag)
        cout<<"true";
    else
        cout<<"false";

    return 0;
}
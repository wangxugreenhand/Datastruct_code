#include<iostream>
using namespace std;

int num[400005] = {0};
int a[200005] = {0};
int tree[10000000] = {0};

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
    long long slow =1,fast = 1;
    tree[fast] = num[1];
    slow++;
    fast++;
    while(slow <= 2*n +1)
    {
        if(tree[fast / 2] == -1 )
        {
            tree[fast] = -1;
            fast++;
        }
        else
        {
            tree[fast] = num[slow];
            slow++;
            fast++;
        }

    }

    fast--;
    for(int i =1;i<=n;i++)
        cin>>a[i];
    int layer = get_layer(fast);
    for(;layer>1;layer--)
    {
        long long cur = pow_2(layer-1) ;
        long long next = pow_2(layer) - 1;
        long long cur_end = fast < next?fast:next;
        for(long long i = cur;i<= cur_end;i++)
        {
            if(tree[i] != -1){
                if(a[tree[i]] % k == 0)
                    res+=a[tree[i]] / k;
                else
                    res += a[tree[i]] / k + 1;
                a[tree[i / 2]] += a[tree[i]];
            }
        }
    }


    cout<<res;
    return 0;
}
#include<iostream>
using namespace std;
struct Node{
    int val;
    int id;
    Node():val(0),id(0){}
};

Node a[100005];

int min_step(int l, int r, int s)
{

}
int main()
{
    int n,s,k;
    int res = 0;
    cin>>n>>s>>k;
    int j = 1;
    for(int i = 1;i<= 2*n;i+=2)
    {
        cin>>a[j].id>>a[j].val;
        j++;
    }
    int cn = 0;
    int l = 0;
    for(int r = 0; r< a[n].id;r++)
    {
        cn+=a[r].val;
        while(l <= r && min_step(l,r,s) > k)
        {
            cn-=a[l].val;
            l++;
        }
        ans = max_(ans,cn);
    }




    cout<<res;
    return 0;
}
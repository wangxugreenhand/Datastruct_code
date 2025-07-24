//递归模型

#include<iostream>
using namespace std;

int res =INT_MIN;


int a[1000000] = {0};

int pow_(int x,int y){
    if(y == 0)
        return 1;
    for(int i =1;i<y;i++){
        x *= 2;
    }
    return x;
}
int max_(int x,int y)
{
    return x>y?x:y;
}

int Maxsum(int p){
    if(a[p]==0)
        return 0;
    int leftsum =max_(Maxsum(2*p+1),0);
    int rightsum =max_(Maxsum(2*p+2),0);

    int temp = a[p] + leftsum + rightsum;
    res = max_(res,temp);

    return a[p] + max_(leftsum,rightsum);

}


int main()
{
    int n;

    cin>>n;

    for(int i = 0;i< n;i++)
        cin>>a[i];
    Maxsum(0);


    cout<<res;
    return 0;
}

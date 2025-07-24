#include<iostream>


using namespace std;

int pow_(int x,int y){
    if(y == 0)
        return 1;
    for(int i =1;i<y;i++){
        x *= 2;
    }
    return x;
}


int main()
{
    int n;
    cin>>n;
    int * nums = new int[n];
    for(int i = 0;i<n;i++)
    {
        cin>>nums[i];
    }
    int flag = 1;//自做向右为1，自右向左为0；
    int num = 0;
    int l = 0;
    while(num < n)
    {
        if(flag){
            int p = pow_(2,l);
            for(int i =0;i<p ;i++) {
              if(nums[p -1 + i] != -1)
                  cout<<nums[p -1 + i]<<" ";
              num++;
            }
            flag = 0;
        }
        else{
            int p = pow_(2,l);
            int start = pow_(2,l+1) -1;
            for(int i =1;i<=p ;i++) {
                if(nums[start-i] != -1)
                    cout<<nums[start-i]<<" ";
                num++;
            }
            flag = 1;
        }
        l++;
    }
    return 0;
}

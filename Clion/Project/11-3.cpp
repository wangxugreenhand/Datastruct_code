//二分法！！！


#include<iostream>
using namespace std;



int NJU[1000005] = {0};


int main()
{
    int V =0;
    int n;
    long long m;
    cin>>n>>m;
    int max = 0;
    for(int i =0;i< n;i++)
    {
        cin >> NJU[i];
        max = max>NJU[i]?max:NJU[i];
    }
    int left = 1, right = max;
    long long sum = 0;
    int pre = 0;
    while(left <= right)
    {
        sum = 0;
        V = left + (right - left) / 2;
        for(int i = 0;i<n;i++)
        {
            if(NJU[i] > V)
                sum+=(NJU[i] - V);
        }
        if(sum < m)
        {
            if(pre+1 == V)
            {
                V = pre;
                break;
            }
            right = V - 1;

        }
        else if(sum == m)
            break;
        else
        {
            pre = V;
            left = V+1;
        }

    }




    cout<<V;
    return 0;
}
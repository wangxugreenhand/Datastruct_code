#include<iostream>
using namespace  std;

int a[105][105] = {0};

int main()
{
    int n,m;
    cin>>n>>m;
    int sum = 0;
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++)
            cin>>a[i][j];
    for(int i = 0;i<n+2;i++)
    {
        a[0][i] = 0;
        a[n+1][i] = 0;
    }
    for(int i = 1;i<n+1;i++)
    {
        a[i][0] = 0;
        a[i][m+1] = 0;
    }

    for(int i = 0;i< n+2;i++)
    {
        for(int j = 0;j< m+ 2 ;j++)
        {
            if(a[i][j] == 1)
            {
                if(a[i-1][j] == 0)
                    sum++;
                if(a[i+1][j] == 0)
                    sum++;
                if(a[i][j-1] == 0)
                    sum++;
                if(a[i][j+1] == 0)
                    sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}

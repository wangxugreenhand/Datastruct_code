#include<iostream>
using namespace std;
int a[1000][1000] = {0};
int b[1000][1000] = {0};
int c[1000][1000] = {0};
int main()
{
    int n,t,m;
    cin>>n>>t>>m;

    for(int i = 0;i<n;i++)
        for(int j = 0; j< t; j++)
            cin>>a[i][j];

    for(int i = 0;i<t;i++)
        for(int j = 0; j< m; j++)
            cin>>b[i][j];

    for(int i = 0;i<n;i++ )
        for(int k = 0; k< t;k++)
            if(a[i][k] != 0)
            {
                for(int j = 0;j< m;j++)
                    c[i][j] += a[i][k] * b[k][j];
            }
    for(int i =0;i<n;i++) {
        for (int j = 0; j < m; j++)
            cout << c[i][j] << ' ' ;
        cout<<endl;
    }
    return 0;
}

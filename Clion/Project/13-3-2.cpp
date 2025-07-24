#include<iostream>
#include<string.h>
using namespace  std;


char s[105][105];
int m,n;
int vis[105][105][205];
int hvp()
{
    memset(vis,0,sizeof(vis));
    int h = (m+n-1) /2;
    vis[0][0][1] = 1;
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            for(int k = 0;k<=i+j+1 && k<= h;k++)
            {
                if(s[i][j] == '(')
                {
                    if(k == 0) continue;
                    if(( i>=1 && vis[i-1][j][k-1] ) ||(j >= 1 && vis[i][j-1][k-1]))
                        vis[i][j][k] = 1;

                }
                else
                {
                    if(k == h) continue;
                    if((i-1 >= 0 && vis[i-1][j][k+1]) || (j-1 >= 0 && vis[i][j-1][k+1]))
                        vis[i][j][k] = true;

                }
            }
        }
    }
    return vis[m-1][n-1][0];
}

int main()
{

    int t;
    cin>>t;
    for(int q = 0;q<t;q++)
    {
        memset(s,0,sizeof(s));

        cin>>m>>n;
        for(int i = 0;i<m;i++)
            for(int j =0; j < n; j++)
                cin >> s[i][j];

        if((m+n) %2 == 0 || s[0][0] == ')' || s[m-1][n-1] == '(') {
            cout << "no"<<endl;
            continue;
        }
        int flag = hvp();

        if(flag)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
}

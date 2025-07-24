#include<iostream>
#include<string.h>
using namespace  std;

char s[105][105];
int m,n;
int vis[105][105][205] = {0};

bool dfs(int x, int y, int c)
{
    if(c > m -x + n -y - 1) return false;
    if( x == m - 1 && y == n - 1) return c==1;
    if(vis[x][y][c] == 1) return false;
    vis[x][y][c] = 1;
    if(s[x][y] == '(')
        c++;
    else
        c--;
    if(c < 0)
        return false;
    else
    {
        if(x < m - 1 && dfs(x + 1, y, c) || y < n - 1 && dfs(x, y + 1, c))
            return true;
    }

}

int main()
{
    int t;
    cin>>t;
    for(int q = 0;q<t;q++)
    {
        cin>>m>>n;
        memset(s,0,105*105);
        for(int i = 0;i<m;i++)
            for(int j =0; j < n; j++)
            {
                cin >> s[i][j];
            }
        for(int i = 0;i<105;i++)
            for(int j = 0;j<105;j++)
                for(int p = 0 ;p<205;p++)
                    vis[i][j][p] = 0;
        if((m+n) %2 == 0 || s[0][0] == ')' || s[m-1][n-1] == '(') {
            cout << "no"<<endl;
            continue;
        }
        bool flag = dfs(0,0,0);
        if(flag)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;

    }

    return 0;
}




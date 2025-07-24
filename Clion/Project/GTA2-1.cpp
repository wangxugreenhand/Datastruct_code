#include<iostream>
#include<vector>
using namespace std;

int E[101][101] = {0};
int num[100] = {0};
int env[100] = {0};
vector<int> Point;
int n,m;
extern void DFS(int x);
int main()
{
    int res = 0;
    cin>>n>>m;
    int x,y;
    for(int i = 1;i<= m;i++)
    {
        cin>>x>>y;
        E[x][y]++;
        E[y][x]++;
        num[x]++;
        num[y]++;
    }
    int temp = 0;
    for(int i = 1;i<= n;i++)
        if(num[i] %2 != 0) { env[temp] = i; temp++;}
    if(temp > 2)
        cout << 0;
    else
    {
        if(temp == 2)
        {
            int max = env[0]>env[1]?env[0]:env[1];
            DFS(max);
        }
        else
        {
            int s = n;
            for (int i = n; i >= 1; i--)
                if(num[i]!= 0) {
                    s = i;
                    break;
                }
            DFS(s);
        }
        if(Point.size()!= m+1)
            cout<<0;
        else {
            cout<<1<<endl;
            for (int i = Point.size() - 1; i >= 0; i--)
                cout << Point[i] << " ";
        }
    }

    return 0;
}
void DFS(int x)
{
    for(int i= n;i>=1;i-- )
    {
        if(E[x][i] != 0)
        {
            E[x][i]--;
            E[i][x]--;
            DFS(i);
        }
    }
    Point.push_back(x);
}
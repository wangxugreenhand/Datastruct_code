#include<iostream>
#include "cmath"
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

struct Node{
    int val;
    Node* l;
    Node(int v):val(v),l(NULL){}
};

Node* a[10001] = {NULL};
bool vis[10001] = {false};
int d[10001] = {0};
int low[10001] = {0};
bool Judge[10001] = {false};
int parent[10001] = {0};
int children[10001] = {0};
int num = 0;
stack<pair<int,int>> S;
vector<int> res;

Node* getfirst(int x)
{
    return a[x];
}
void DFSBLK(int u, int t)
{
    t++;
    d[u] = t;
    low[u] = d[u];
    vis[u] = true;
    for(Node* p = getfirst(u);p != NULL; p = p->l)
    {
        int v = p->val;
        if(!vis[v]) {
            S.push(pair<int,int>(u,v));
            parent[v] = u;
            children[u]++;
            DFSBLK(v,t);
            low[u] = min(low[u],low[v]);
            if((parent[u] == 0 && children[u] >= 2) ||(parent[u] !=0 && low[v]>= d[u]))
            {
                int num = 0;
                pair<int,int> pp(0,0);
                do {
                    pp = S.top();
                    S.pop();
                    num++;
                }while(pair<int,int>(u,v) != pp);
                res.push_back(num);
            }
        }
        else if(v != parent[u])
        {
            if(d[u] > d[v])
                S.push((pair<int,int>(u,v)));
            low[u] = min(low[u], d[v]);
        }

    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    int x,y;
    for(int i = 1;i<= m;i++)
    {
        cin>>x>>y;
        Node* p1 = new Node(y);
        if(a[x] == NULL)
            a[x] = p1;
        else
        {
            Node* q = a[x];
            while(q->l)
                q = q->l;
            q->l = p1;
        }
        Node* p2 = new Node(x);
        if(a[y] == NULL)
            a[y] = p2;
        else
        {
            Node* q1 = a[y];
            while(q1->l)
                q1 = q1->l;
            q1->l = p2;
        }
    }
    for(int i = 1; i<=n;i++ ) {
        if (!vis[i] && getfirst(i) != NULL) {
            DFSBLK(i, 0);
            int num_ = 0;
            while(!S.empty())
            {
                S.pop();
                num_++;
            }
            res.push_back(num_);
        } else if (!vis[i] && getfirst(i) == NULL) {
            res.push_back((0));
            vis[i] = true;
        }
    }
    cout<<res.size()<<endl;
    sort(res.begin(),res.end());
    for(int i = 0;i<res.size();i++)
        cout<<res[i]<<" ";

    return 0;
}
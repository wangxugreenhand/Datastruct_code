#include<iostream>

using namespace std;
int n,e;
int rea[20000] = {-1};
int rea_[20000] = {-1};

int ve[20000] = {0};
int vl[20000] = {0};

struct Edge{
    int v;
    int w;
    Edge* link;
    Edge():v(-1),w(0),link(NULL){}
};
struct Node{
    int count;
    Edge* head;
    Node():count(0),head(NULL){}
};

Node a[20000];



void Topu()
{
    int head = 0;
    int top = -1;

    for(int i = 0;i<n;i++)
        if(a[i].count== 0)
        {
            a[i].count = top;
            top = i;
        }
    for(int i =0;i<n;i++) {
        int v = top;
        top = a[top].count;
        rea[head] = v;
        rea_[v] = head;
        head++;
        Edge* w = a[v].head;
        //int w = getfirstnode(v);
        while (w != NULL) {
            a[w->v].count--;
            if (!a[w->v].count) {
                a[w->v].count = top;
                top = w->v;
            }
            w = w->link;
        }
    }
}

void CriticalPath()
{
    for(int i = 0;i<n;i++)
    {
        Edge* j = a[rea[i]].head;
        while(j != NULL)
        {
            int dur = j->w;
            if(ve[i] + dur > ve[rea_[j->v]])
                ve[rea_[j->v]] = ve[i]+dur;
            j = j->link;
        }
    }
    vl[n-1] = ve[n-1];
    for(int i =0;i<n-1;i++)
        vl[i] = vl[n-1];
    for(int j = n-2;j>0;j--)
    {
        Edge* k = a[rea[j]].head;
        while(k != NULL)
        {
            int dur = k->w;
            if(vl[rea_[k->v]] - dur < vl[j])
                vl[j] = vl[rea_[k->v]] - dur;
            k = k->link;
        }
    }
    int ae,al;
    for(int i = 0;i<n;i++)
    {
        Edge* j = a[i].head;
        while(j !=NULL){
            ae = ve[rea_[i]];
            al = vl[rea_[j->v]] - j->w;
            if(ae == al)
            {
                cout<<i<<" "<<j->v<<endl;
            }
            j = j->link;
        }
    }


}


int main()
{
    cin>>n>>e;
    int f,t,w;
    for(int i = 0;i<e;i++)
    {
        cin>>f>>t>>w;
        Edge* p = new Edge;
        p->v = t;
        p->w = w;
        p->link = a[f].head;
        a[f].head = p;
        a[t].count++;
    }
    Topu();
    CriticalPath();

    return 0;
}
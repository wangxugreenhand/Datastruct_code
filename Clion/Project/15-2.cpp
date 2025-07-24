#include <iostream>

using namespace std;
int r[20005][20005] = {0};

int rea[20005] = {-1};
int rea_[20005] = {-1};
int n,e;
int ve[20005] = {0};
int vl[20005] = {0};
struct Node{
    int fr;
    int to;
    Node():fr(-1),to(-1){}
};

struct Edge{
    int v1;
    int v2;
    Edge():v1(0),v2(0){}
};

Edge heap[10005];
int currentsize = 0;

bool biger(Edge i ,Edge j)
{
    if(i.v1 > j.v1)
        return true;
    if(i.v1 == j.v1  &&  i.v2 > j.v2)
        return true;
    return false;
}

void siftDown2(int start, int m)
{
    int i = start, j = 2 * i + 1;
    Edge temp = heap[i];
    while (j <= m) {
        if (j < m && biger(heap[j],heap[j+1])) j++;
        if (biger(heap[j],temp)) break;
        else { heap[i] = heap[j]; i = j; j = 2 * j + 1; }
    }
    heap[i] = temp;
}
void siftUp2(int start)
{
    int j = start, i = (j - 1) / 2;
    Edge temp = heap[j];
    while (j > 0) {
        if (biger(temp,heap[i])) break;
        else { heap[j] = heap[i]; j = i; i = (i - 1) / 2; }
    }
    heap[j] = temp;
}

bool insert2(int x,int y) {
    heap[currentsize].v1 = x;
    heap[currentsize].v2 = y;
    siftUp2(currentsize);
    currentsize++;
    return  true;
}
bool remove2() {
    heap[0] = heap[currentsize - 1];
    currentsize--;
    siftDown2(0, currentsize - 1);
    return true;
}



int getnext(int i,int j)
{
    for(int p = j+1;p<n;p++)
    {
        if(r[i][p])
            return p;
    }
    return -1;
}




void Topo()
{
    int head = 0;
    int top = -1;

    int* count = new int[n];
    for(int i = 0;i<n;i++)
        count[i] = 0;
    int f,t,w;
    for(int i = 0;i<e;i++)
    {
        cin>>f>>t>>w;
        r[f][t] = w;
        count[t]++;
    }
    for(int i = 0;i<n;i++)
        if(count[i] == 0)
        {
            count[i] = top;
            top = i;
        }
    for(int i =0;i<n;i++)
    {
        int v = top;
        top = count[top];
        rea[head] = v;
        rea_[v] = head;
        head++;
        int w = getnext(v,-1);
        while(w != -1)
        {
            count[w]--;
            if(!count[w])
            {
                count[w] = top;
                top =w;
            }
            w = getnext(v,w);
        }
    }
    delete[]count;

}
void change()
{
    int ** arr = new int*[n];
    for(int i = 0;i<n;i++)
        arr[i] = new int[n];
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            arr[i][j] = 0;

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(r[i][j])
            {
                arr[rea_[i]][rea_[j]] = r[i][j];
                r[i][j] = 0;
            }
        }
    }
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(arr[i][j])
            {
                r[i][j] = arr[i][j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        delete[]arr[i];

    }
    delete []arr;

}


void CriticalPath()
{
    for(int i = 0;i<n;i++)
    {
        int j = getnext(i,-1);
        while(j != -1)
        {
           int dur = r[i][j];
           if(ve[i] + dur > ve[j])
               ve[j] = ve[i]+dur;
           j = getnext(i,j);
        }
    }
    vl[n-1] = ve[n-1];
    for(int i =0;i<n-1;i++)
        vl[i] = vl[n-1];
    for(int j = n-2;j>0;j--)
    {
        int k = getnext(j,-1);
        while(k != -1)
        {
            int dur = r[j][k];
            if(vl[k] - dur < vl[j])
                vl[j] = vl[k] - dur;
            k = getnext(j,k+1);
        }
    }
    int ae,al;
    for(int i = 0;i<n;i++)
    {
        int j = getnext(i,-1);
        while(j !=-1){
            ae = ve[i];
            al = vl[j] - r[i][j];
            if(ae == al)
            {
                insert2(rea[i],rea[j]);
            }
            j = getnext(i,j);
        }
    }
    while(currentsize)
    {
        cout<<heap[0].v1<<" "<<heap[0].v2<<endl;
        remove2();
    }


}
int main()
{
    cin>>n>>e;
    Topo();
    change();
    CriticalPath();

    return 0;
}
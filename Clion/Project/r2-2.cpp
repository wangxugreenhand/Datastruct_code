#include<iostream>
using namespace std;

int a[500005] = {0};
int res[500005]= {0};

int queue[600005] = {0};
int back = 0,front = 0;
void push_back(int x)
{
    queue[back++] = x;
}
void pop_front()
{
    front++;
}
bool empty()
{
    return front == back;
}
void pop_back()
{
    back--;
}
int gettop()
{
    return queue[front];
}
int getback()
{
    int x = back - 1;
    return queue[x];
}

int main()
{
    int n ,m;
    cin>>n>>m;
    if(m > n)
        return 0;
    for(int i = 1;i<=n;i++)
        cin>>a[i];
    for(int i = 1;i<=n;i++)
    {
        if(empty())
            push_back(i);
        else {
            while (!empty()  &&a[getback()] <= a[i]) {
                    pop_back();

            }
            push_back(i);
            while (!empty()  && (i - m) >= gettop())
                pop_front();

        }
        if (i >= m)
            res[i - m] = a[gettop()];

    }

    for(int i = 0;i<=(n-m);i++)
        cout<<res[i]<<" ";

    return 0;
}
#include<iostream>

using namespace std;
int t[100005] = { 0 };
int a[100005] = { 0 };

int rear = 0;
int front = 0;
int get_back()
{
    return t[rear - 1];
};
int get_front()
{
    return t[front];
};
bool empty()
{
    return rear == front;
}
void push_back(int x)
{
    t[rear] = x;
    rear++;
}
void pop_back()
{
    rear--;
}
void pop_front()
{
    front++;
}
int min_(int x, int y)
{
    int res = x > y ? y : x;
    return res;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        rear = 0;
        front = 0;
        long long b[100005] = { 0 };
        int n, k;
        cin >> n >> k;
        int res = 1000000;
        
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i + 1] = a[i] + b[i];
        }
        for (int i = 0; i < n + 1; i++)
        {
            while (!empty() && b[i] <= b[get_back()])
                pop_back();
            while (!empty() && b[i] - b[get_front()] >= k)
            {
                res = min_(res, i - get_front());
                pop_front();
            }
            push_back(i);
        }
        if (res == 1000000)
            res = -1;
        
        cout << res << endl;

    }
   

  
    return 0;
}
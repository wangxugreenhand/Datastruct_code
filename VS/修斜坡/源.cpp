#include<iostream>

using namespace std;
int stack[100005] = { 0 };
int top = 0;
void push(int x)
{
    stack[top] = x;
    top++;
}
void pop()
{
    top--;
}
bool empty()
{
    return (top == 0);
}
int gettop()
{
    int t = top - 1;
    return stack[t];
}


int main()
{
    int t;
    cin >> t;
    while (t)
    {
        long long res = 0;
        long long b[100005] = { 0 };
        int val = 0;
        t--;
        int n;
        cin >> n;
        int* a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            top = 0;
            if (i == 0)
                b[i] = a[i];
            else
            {
                
                    int j = i;
                    push(j);
                    b[i] += a[j];
                    j--;

                    while (j != -1)
                    {
                        if (a[gettop()] <= a[j])

                            b[i] += a[gettop()];
                        else
                        {
                            b[i] += a[j];
                            pop();
                            push(j);
                        }
                        j--;
                    }
                    if (b[i] >= res)
                        res = b[i];
                
            }
        }
       

        cout << res << endl;
        delete[]a;
    }


    return 0;
}
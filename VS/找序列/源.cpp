#include<iostream>

using namespace std;


int temp[20];
int* backtrack(int p, int* res, int n)
{
    if (p  == 2*n-1 )
        return res;
    if (res[p] != -1)
        return backtrack(p + 1, res, n);
    for (int i = n; i > 0; i--)
    {
        if (temp[i] != 0)
            continue;
        if (i > 1 && p + i >= 2 * n - 1)
            continue;
        if (i > 1 && res[p + i] != -1)
            continue;
        if (i == 1)
            res[p] = i;
        else
        {
            res[p] = i;
            res[p + i] = i;
        }
        temp[i] = 1;
        int* t = backtrack(p + 1, res, n);
        if (t != NULL)
            return t;
        if (i == 1)
            res[p] = -1;
        else
        {
            res[p] = -1;
            res[p + i] = -1;
        }
        temp[i] = 0;

    }
    return NULL;
}

int main()
{
    for (int i = 0; i < 20; i++)
        temp[i] = 0;
    int n;
    cin >> n;
    int* res = new int[2 * n - 1];
    for (int i = 0; i < 2 * n - 1; i++)
        res[i] = -1;
    if (n > 1)
        backtrack(0, res, n);
    else
        res[0] = 1;
    for (int i = 0; i < 2 * n - 1; i++)
        cout << res[i] << " ";

 
    return 0;
}
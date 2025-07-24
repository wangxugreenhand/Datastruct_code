#include<iostream>
using namespace std;
struct node
{
    long long val;
    int num;
    bool operator < (node& x)
    {
        if(val < x.val)
            return true;
        else if (val == x.val)
            if (num > x.num)
                return true;
            else
                return false;
        else
            return false;
    }
    
};

void QuickSort(node a[], int first, int last)
{
    if (first >= last)
        return;
    int l = first;
    int r = last;
    node pivot = a[(first + last) /2];
    while (l <= r)
    {
        while (a[l] < pivot)
            l++;
        while (pivot < a[r])
            r--;
        if (l <= r)
        {
            node temp = a[l];
            a[l] = a[r];
            a[r] = temp;
            l++;
            r--;
        }
    }
    
    QuickSort(a, first, r);
    //if (l< last)
        QuickSort(a, l, last);

}



int main()
{
    int t;
    cin >> t;
    int* arr1;
    int* arr2 = new int[t];
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        arr1 = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr1[j];
        }
        node* b = new node[n + 1];
        b[0].num = -1;
        b[0].val = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr1[i] >= 8)
                b[i + 1].val = b[i].val + 1;
            else
                b[i + 1].val = b[i].val - 1;

            b[i + 1].num = i;
        }
        QuickSort(b,0,n);
        int max = 0;
        int min = n;
        int rec = 0;
        for (int i = 0; i < n + 1; i++)
        {
            if (b[i].num < min)
            {
                min = b[i].num;
                rec = i;
            }
            if (b[i].num > min && (b[i].num - min) > max && b[i].val > b[rec].val)
                max = b[i].num - min;
        }
        arr2[i] = max;
    }
    for (int i = 0; i < t; i++)
        cout << arr2[i] << endl;
    return 0;
}
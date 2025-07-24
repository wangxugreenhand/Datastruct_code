#include <iostream>

using namespace std;

void sort(int a[],  int n)
{
    int num1 = 0;
    int num2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            num1++;
        else if (a[i] == 0)
            num2++;
        else
            continue;
    }
    int* b = new int[n];
    for (int i = 0; i < n; i++)
        b[i] = 0;
    for (int i = 0; i < num1; i++)
        b[i] = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 1 && a[i] != 0)
        {
            b[num1] = a[i];
            num1++;
        }
        else
            continue;
    }
    for (int i = 0; i < n; i++)
        a[i] = b[i];
    
}

int main()
{
    int t, n, m;
    cin >> t;
    int** arr1;
    int** arr3;
    arr1 = new int* [t];
    
    int* arr2 = new int[t];
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        arr1[i] = new int[n];
        arr2[i] = n;
        for (int j = 0; j < n; j++)
        {
            cin >> m;
            arr1[i][j] = m;

            
        }
        sort(arr1[i], n);
    }
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < arr2[i]; j++)
        {
            cout << arr1[i][j] << ' ';
        }
        cout << endl;
    }

    
    return 0;
}

/* #include <iostream>
#include <windows.h>
using namespace std;

struct ListNode{
        int data;
        ListNode *link;
    };
class List{

}
int main()
{


    system("pause");
    return 0;
} */
#include<iostream>
using namespace std;


int f(int a[], int n)
{
	int res = 0;
	int num1 = 0;
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			int flag = 0;
			num1 = 0;
			for(int q =i; q<=j;q++)
			{
				
				if (a[q] >= 8)
					num1++;
				else
					num1--;
				if (q == j && num1 > 0)
				{
					temp = j - i + 1;
					flag = 1;
				}
				
			}
			if (flag)
				break;
			
	
		}
		if (res <= temp)
			res = temp;
	}
	return res;
}
int main()
{
	int t;
	cin >> t;
	int** arr1 = new int* [t];
	int* arr = new int[t];
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		arr1[i] = new int[n];
		for (int j = 0; j < n; j++)
			cin >> arr1[i][j];
		arr[i] = f(arr1[i], n);
	}
	for (int i = 0; i < t; i++)
		cout << arr[i] << endl;
	return 0;
}
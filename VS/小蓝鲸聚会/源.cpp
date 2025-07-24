#include<iostream>
using namespace std;

int main()
{
	int rol, col;
	cin >> rol >> col;
	int a[2049][2049];
	int b[2049][2049];
	for (int i = 0 ; i < 2049;i++)
	{
		for (int j = 0; j < 2049;j++)
		{
			a[i][j] = 0;
			b[i][j] = 0;
		}
	}
	for (int i = 0; i < rol; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> a[i][j];
			b[i][j] = a[i][j];
		}
	}
	for (int i = 0; i < rol; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (a[i][j] == 0)
			{
				for (int q = 0; q < rol; q++)
				{
					b[q][j] = 0;

				}
				for (int q = 0; q < col; q++)
				{
					b[i][q] = 0;

				}
			}

		}
	}
	for (int i = 0; i < rol; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << b[i][j] << " ";
			if (j == col - 1)
				cout << endl;
		}
	}
	return 0;
}
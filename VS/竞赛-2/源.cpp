#include<iostream>


using namespace std;
int res[1000][1000] = { 0 };
int m, n;
//void f(int r, int l,int num)
//{
//	if (m - num == 1)
//	{
//		
//	}
//}


int main()
{
	cin >> m >> n;
	int r = 0;
	int l = n - 1;
	int flag_l = 1;//1 left
	int f_l = 1;
	int f_r = 0;
	int flag_r = 1;//1 down
	int sum_l = 0;
	int sum_r = 0;
	for (int i = 1; i <= m * n; i++)
	{
		res[r][l] = i;
		if (i == 1 && n != 1)
		{
			l--;
			continue;
		}
		else
		{
			if (l == n - 1 - sum_l && r == sum_r && f_r == 1)
			{
				flag_l = 1;
				f_l = 1;
				f_r = 0;
				sum_l++;
			}
			else if (l == sum_l && r == sum_r && f_l == 1)
			{
				flag_r = 1;
				f_r = 1;
				f_l = 0;
			}
			else if (l == sum_l && r == m - 1 - sum_r && f_l == 0)
			{
				flag_l = 0;
				f_l = 1;
				f_r = 0;
			}
			else if (l == n - 1 - sum_l && r == m - 1 - sum_r && f_r == 0 && flag_l == 0)
			{
				sum_r++;
				flag_r = 0;
				f_l = 0;
				f_r = 1;
			}
			if (f_l)
			{
				if (flag_l)
					l--;
				else
					l++;
			}
			if (f_r)
			{
				if (flag_r)
					r++;
				else
					r--;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << res[i][j]<<" ";
		cout << endl;
	}

	return 0;
}
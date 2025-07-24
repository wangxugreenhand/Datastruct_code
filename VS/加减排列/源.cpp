#include<iostream>
#include<cmath>
using namespace std;

long long f(long long n, long long x, long long y)
{
	long long res = 0;
	long long x1 = x;
	long long y1 = y;
	long long temp = 0;
	long long m = 0;
	while (temp = x1 % y1)
	{
		x1 = y1;
		y1 = temp;
	}
	m = (x * y) / y1;
	long long num1 = n / x;
	long long num2 = n / y;
	long long num3 = n / m;
	num1 = num1 - num3;
	num2 = num2 - num3;
	for (int i = 0; i < num1; i++)
	{
		res += n;
		n--;
	}
	for (int i = 0; i < num2; i++)
	{
		res = res - (i + 1);
	}
	return res;
}

int main()
{
	long long t;
	cin >> t;
	
	long long* arr = new long long[t];
	for (int i = 0; i < t; i++)
	{
		long long n;
		long long x, y;
		cin >> n >> x >> y;
		arr[i] = f(n, x, y);
	}
	for (int i = 0; i < t; i++)
		cout << arr[i] << endl;
	return 0;
}
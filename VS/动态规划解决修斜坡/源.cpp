#include<iostream>
#include<cmath>
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
	while (t--)
	{
		top = 0;
		long long b[100005] = { 0 };
		long long res = 0;
		int n;
		cin >> n;
		int* a = new int[n];
		int* c = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			c[i] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			if (empty())
			{
				b[i + 1] = b[i] + a[i];
				push(i);
				continue;
			}
			long long temp = b[i];
			while (!empty() && a[gettop()] > a[i])
			{

				temp = temp - (a[gettop()] - a[i]) * c[gettop()];
				c[i] += c[gettop()];
				pop();
			}
			b[i + 1] = temp + a[i];
			push(i);
		}
		for (int i = 0; i <= n; i++)
			res = max(res, b[i]);
		cout << res << endl;
		delete[]a;
		delete[]c;
	}

	return 0;
}
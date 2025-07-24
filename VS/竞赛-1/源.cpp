#include<iostream>


using namespace std;

int t[100005] = { 0 };
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
int max_(int x, int y)
{
	int res = x < y ? y : x;
	return res;
}

int main()
{
	int n;
	cin >> n;
	long long sum = 0;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (empty())
			push_back(i);
		else

		{
			if (a[i] > a[get_front()])
				sum = max_(sum, a[i] - a[get_front()]);
			else
			{
				pop_back();
				push_back(i);
			}

		}
	}
	cout << sum;

	

	return 0;
}
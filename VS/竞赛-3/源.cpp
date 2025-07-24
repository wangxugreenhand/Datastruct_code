#include<iostream>


using namespace std;
int t[100005] = { -1 };
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


int main()
{
	int n, k;
	cin >> n >> k;
	int k_ = k;
	for (int i = 0; i < 100005; i++)
		t[i] = -1;
	int* a = new int[n];
	int* res = new int[n - k];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		if (empty() && a[i] == 0)
			continue;
		if (empty())
		{
			push_back(i);
			continue;
		}
		while (!empty() && a[i] < a[get_back()] && k >0)
		{
			if (rear == 1 && a[i] == 0)
				break;
			pop_back();
			k--;
		}
		if (a[get_back()] == 0 && ((a[get_front()] > a[i]) || n - i - k < n - k_) && k>0 )
		{
			while (!empty())
			{
				if (a[get_front()] == 0)
					pop_front();
				else if(k>0)
				{
					pop_front();
					k--;
				}
			}
		}
		push_back(i);
	}
	if (k >= n)
		cout << 0;
	else if (empty() || a[get_front()] == 0)
		cout << 0;
	else
	{
		while (!empty())
		{
			cout << a[get_front()];
			pop_front();
		}

	}
	return 0;
}
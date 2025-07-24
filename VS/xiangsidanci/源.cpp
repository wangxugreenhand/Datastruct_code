#include<iostream>
#include<string.h>
using namespace std;


int main()
{
	string a, b;
	cin >> a >> b;
	int flag = 1;
	if (a.length() != b.length())
		flag = 0;
	else
	{
		for (int i = 0; i < a.length(); i++)
		{
			for (int j = 0; j < b.length(); j++)
			{
				if (a[i] == b[j])
				{
					b = b.erase(j, 1);
					break;
				}
				else if (j == b.length() - 1)
					flag = 0;
			}
		}
	}
	if (flag == 1)
		cout << "true";
	else
		cout << "false";
	
	return 0;
}
#include<iostream>
#include<cstring>

using namespace std;
int net[10005] = { -2 };

void getnext(string str,int len)
{
    int j = 0;
    int k = -1;
    net[0] = -1;
    while (j < len)
    {
        if (k == -1 || str[j] == str[k] || str[j] == '*' || str[k] == '*')
        {
            j++;
            k++;
            net[j] = k;
        }
        else
            k = net[k];
    }

}
int main()
{
    int n;
    cin >> n;
    string pat;
    cin >> pat;
    int p_len = pat.length();
    while (n)
    {
        int flag = 0;
        n--;
        string test;
        cin >> test;
        int len = test.length();
        for (int j = 0; j < 10005; j++)
            net[j] = -2;
        getnext(test,len);
        int posP = 0, PopT = 0;

    }

    return 0;
}

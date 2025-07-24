#include<iostream>
#include<cstring>

using namespace std;
int main()
{
    string str;
    cin>>str;
    int v[1005] = {-1};//数字为1，正负号为0，点为2，E和e为3，空格为4， 其他为-1。
    int flag = 1;
    int e_num = 0;
    int f_num = 0;
    int d_num = 0;
    int pos_e = str.size();
    int loop = 1;
    for(int i = 0; i<str.length();i++)
    {
        if(str[i] <= 57 && str[i] >= 48)
            v[i] = 1;
        else if(str[i] == 'E' || str[i] == 'e') { v[i] = 3; e_num++; pos_e = i;}
        else if(str[i] == '.') { v[i] = 2; d_num++ ;}
        else if(str[i] == '+' || str[i] == '-') { v[i] = 0; f_num++; }
        else if(str[i] == ' ') { v[i] = 4; }
        else { v[i] = -1; }

    }
    if(e_num > 1 || d_num > 1|| f_num > 2)
        flag = 0;
    int l=0,r = str.size()-1;
    while(str[l] == ' ' && l < str.size()) l++;
    while(str[r] ==' ' && r >= 0) r--;
    if(l > r)
        flag = 0;
    if(l == r && v[l] == 1) { flag = 1; loop = 0; }

    if(flag != 0 && loop == 1) {
        for (int i = l; i <= r; i++) {
            if(v[i] == 4 || v[i] == -1) {
                flag = 0;
                break;
            }
            else if(v[i] == 1)
                continue;
            else if(v[i] == 0)
            {
                if(i != l && v[i-1] !=3 ) {
                    flag = 0;
                    break;
                }
                else if(i == l && v[i+1] != 1 && v[i+1] != 2)
                {
                    flag = 0;
                    break;
                }
                else if(v[i-1] ==3 && v[i+1] != 1 && v[i+1] != 2)
                {
                    flag = 0;
                    break;
                }
            }
            else if(v[i] == 2 )
            {
                if(i > pos_e)
                {
                    flag = 0;
                    break;
                }
                else
                {
                    if(i != l && i != r && v[i-1] != 1 && v[i+1] != 1)
                    {
                        flag = 0;
                        break;
                    }
                    else if(i == l && v[i+1] != 1)
                    {
                        flag = 0;
                        break;
                    }
                    else if(i == r && v[i-1] != 1)
                    {
                        flag = 0;
                        break;
                    }
                    else
                        continue;
                }
            }
            else if(v[i] == 3  && (i == r ||i == l))
            {
                flag = 0;
                break;
            }

        }

    }
    if(flag == 1)
        cout<<"true";
    else
        cout<<"false";
    return 0;
}
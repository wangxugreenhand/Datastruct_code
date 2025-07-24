#include<iostream>
#include<cstring>

using namespace std;
int stack[10005] = { 0 };
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
    string str;
    cin >> str;
    int v[1005] = { -1 };//数字为1，正负号为0，点为2，E和e为3，空格为4， 其他为-1。
    int dot[1005] = { 0 };
    int flag = 1;
    int e_num = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] <= 57 && str[i] >= 48)
            v[i] = 1;
        else if (str[i] == 'E' || str[i] == 'e') { v[i] = 3; e_num++; }
        else if (str[i] == '.')
            v[i] = 2;
        else if (str[i] == '+' || str[i] == '-')
            v[i] = 0;
        else if (str[i] == ' ')
            v[i] = 4;
        else
            v[i] = -1;
        if (str[i] == '.')
        {
            if (i == 0 && i + 1 < str.length())
            {
                if (str[i + 1] <= 41 && str[i + 1] >= 32)
                    dot[i] = 1;
            }
            else if (i == str.length() - 1 && i != 0)
                if (str[i - 1] <= 41 && str[i - 1] >= 32)
                    dot[i] = 1;
                else if (i == 0 && str.length() == 1)
                    flag = 0;
                else
                {
                    if ((str[i + 1] <= 41 && str[i + 1] >= 32) || (str[i - 1] <= 41 && str[i - 1] >= 32))
                        dot[i] = 1;
                }
        }
    }
    if (e_num > 1)
        flag = 0;
    if (flag != 0) {
        for (int i = 0; i < str.length(); i++) {
            if (v[i] == -1) {
                flag = 0;
                break;
            }
            if (empty() && (v[i] == -1 || v[i] == 3)) {
                flag = 0;
                break;
            }
            if (empty() && v[i] == 4)
                continue;
            if (!empty() && v[i] == 4) {
                flag = 0;
                break;
            }
            if (empty() && str[i] != ' ')
                push(i);
            else {
                if (v[i] == 1) {
                    while (!empty() && v[gettop()] == 1)
                        pop();
                    push(i);
                }
                else if (v[i] == 2) {
                    while (!empty() && v[gettop()] == 1)
                        pop();
                    if (empty())
                        push(i);
                    else {
                        if (v[gettop()] == 2 || v[gettop()] == 3) {
                            flag = 0;
                            break;
                        }
                        push(i);
                    }
                }
                else if (v[i] == 0) {
                    while (!empty() && v[gettop()] == 1)
                        pop();
                    if (empty())
                        push(i);
                    else {
                        if (v[gettop()] != 3) {
                            flag = 0;
                            break;
                        }
                        push(i);
                    }
                }
                else if (v[i] == 3) {
                    while (!empty() && v[gettop()] == 1)
                        pop();
                    if (empty())
                        push(i);
                    else
                    {
                        if (v[gettop()] == 2 && i - gettop() == 1)
                        {
                            flag = 0;
                            break;
                        }
                        if (v[gettop()] == 2 && i - gettop() >= 1)
                            push(i);
                        if (v[gettop()] == 0 && i - gettop() == 1)
                        {
                            flag = 0;
                            break;
                        }
                        if (v[gettop()] == 0 && i - gettop() >= 1)
                            push(i);
                    }
                }
            }

        }
    }
    if (flag == 1)
        cout << "true";
    else
        cout << "false";
    return 0;
}
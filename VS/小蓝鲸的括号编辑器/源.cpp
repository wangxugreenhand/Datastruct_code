#include<iostream>
using namespace std;


struct Node {
    char ch;
    Node* lLink, * rLink, * next;


    Node(char c, Node* l = NULL, Node* r = NULL, Node* nxt = NULL)
    {
        ch = c; lLink = l; rLink = r; next = nxt;
    }
};
Node* first = NULL;
int f( int temp)
{
    int p = temp;
    Node* t = first;
    Node* cur = t;
    for (int i = 1; i < p; i++)
    {
        t = t->next;
        cur = t;
    }
    if ((const char)t->ch == '(')
    {
        int num = 1;
        while (num)
        {
            cur = t->next;
            t->rLink->lLink = t->lLink;
            t->lLink->rLink = t->rLink;
            if (t->lLink->next != NULL)
                t->lLink->next = t->next;
            delete t;
            t = cur;
            if ((const char)t->ch == '(')
                num++;
            else
                num--;
        }
        //cur = t->rLink;
        if (t->lLink == t)
        {
            delete t;
            first = NULL;
            p = 0;
        }
        else
        {
            if (t->next == NULL)
            {
                cur = t->lLink;
                p = p - 1;
            }
            else
                cur = t->next;
            t->rLink->lLink = t->lLink;
            t->lLink->rLink = t->rLink;
            if (t->lLink->next != NULL)
                t->lLink->next = t->next;
            delete t;
            t = cur;
            if (p == 1)
                first = cur;
        }
        return p;
    }
    else
    {
        int num1 = 1;
        int num = 1;
        while (num)
        {
            num1++;
            cur = t->lLink;
            t->rLink->lLink = t->lLink;
            t->lLink->rLink = t->rLink;
            if (t->lLink->next != NULL)
                t->lLink->next = t->next;
            delete t;
            t = cur;
            if ((const char)t->ch == ')')
                num++;
            else
                num--;
        }
        if (t->lLink == t)
        {
            delete t;
            first = NULL;
            p = 0;
        }
        else
        {
            if (t->next == NULL)
            {
                cur = t->lLink;
                p = p - num1;
            }
            else
            {
                cur = t->next;
                p = p - num1 + 1;
            }
            if (t == first)
                first = cur;
            t->rLink->lLink = t->lLink;
            t->lLink->rLink = t->rLink;
            if (t->lLink->next != NULL)
                t->lLink->next = t->next;

            delete t;
            t = cur;
        }
        return p;
    }
}

int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    Node* current = first;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        Node* p = new Node(c);

        if (i == 0)
        {
            first = p;
            p->lLink = p;
            p->rLink = p;
            current = p;
            p->next = NULL;
        }
        else
        {
            current->next = p;
            p->rLink = current->rLink;
            current->rLink = p;
            p->lLink = current;
            p->rLink->lLink = p;
            current = p;
        }
    }
    char* p2 = new char[m];
    cin >> p2;
    for (int i = 0; i < m; i++)
    {
        if ((const char)p2[i] == 'L')
            p--;
        else if ((const char)p2[i] == 'R')
            p++;
        else
            p = f(p);
    }
    for (Node* p = first; p != NULL; p = p->next)
    {
        cout << p->ch;
    }


    return 0;
}
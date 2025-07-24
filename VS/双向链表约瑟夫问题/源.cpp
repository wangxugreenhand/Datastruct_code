#include<iostream>
using namespace std;
//#include <windows.h>

struct Node {

    int data;
    Node* lLink, * rLink;
};
Node* first = NULL;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    Node* current = NULL;
    for (int i = 0; i < n; i++)
    {
        Node* p = new Node;
        p->data = i + 1;
        if (i == 0)
        {
            first = p;
            p->lLink = p;
            p->rLink = p;
            current = p;
        }
        else
        {
            p->rLink = current->rLink;
            current->rLink = p;
            p->lLink = current;
            p->rLink->lLink = p;
            current = p;
        }
    }
    int i, j;
    int temp = 1;
   
    Node* p = first;
    for (i = 0; i < n-1; i++)
    {
        if (temp)
        {
            for (j = 1; j < m; j++)
            {
               
                p = p->rLink;
            }

            cout << p->data << " ";
            if (p->data % k == 0)
                temp = 0;
            p->lLink->rLink = p->rLink;
            p->rLink->lLink = p->lLink;
            Node* temp1 = p->lLink;
            delete p;
            if (temp)
                p = temp1->rLink;
            else
                p = temp1;
        }
        else
        {
            for (j = 1; j < m; j++)
            {
               
                p = p->lLink;
            }
            cout << p->data << " ";
            if (p->data % k == 0)
                temp = 1;
            p->rLink->lLink = p->lLink;
            p->lLink->rLink = p->rLink;
            Node* temp1 = p->rLink;
            delete p;
            if (temp)
                p = temp1;
            else
                p = temp1->lLink;
        }


    }
    cout << p->data;


    //system("pause");
    return 0;
}
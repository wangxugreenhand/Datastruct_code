#include<iostream>
using namespace std;
#include "cmath"
extern float f(float x);
int main()
{
    float x;
    cin>>x;
    int n =1, epoch = 40;
    float y = f(x);
    while(fabs(y-x)<= 1e6 && n <= epoch)
    {
        cout<<y<<endl;
        x = y;
        y = f(x);
        n++;
    }
}

float f(float x)
{
    float p = x+ 2;
    return 25 / p;
}
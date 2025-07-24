//最小堆套路！！！


#include<iostream>
using namespace std;
//#include <algorithm>
//#include <queue>

long long heap[200005] = { 0 };
long long a[200005] = {0};
int currentsize = 0;


void siftDown2(int start, int m)
{
    int i = start, j = 2 * i + 1;
    long long temp = heap[i];
    while (j <= m) {
        if (j < m && heap[j] > heap[j + 1]) j++;
        if (temp <= heap[j]) break;
        else { heap[i] = heap[j]; i = j; j = 2 * j + 1; }
    }
    heap[i] = temp;
}
void siftUp2(int start)
{
    int j = start, i = (j - 1) / 2;
    long long temp = heap[j];
    while (j > 0) {
        if (heap[i] <= temp) break;
        else { heap[j] = heap[i]; j = i; i = (i - 1) / 2; }
    }
    heap[j] = temp;
}

bool insert2(long long x) {
    heap[currentsize] = x;
    siftUp2(currentsize);
    currentsize++;
    return  true;
}
bool remove2(long long &x) {
    x = heap[0];
    heap[0] = heap[currentsize - 1];
    currentsize--;
    siftDown2(0, currentsize - 1);
    return true;
}


int main()
{

    int n,m,d;
    cin>>n>>m>>d;
    long long res = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        if(a[i] < 0)
            a[i] = 0;
    }
    long long sum = 0;
    for(int i = 1;i<= n;i++){
        if(i <= m){
            sum+=a[i];
            insert2(a[i]);
            long long temp = sum - (long long)d * i;
            res = res>temp?res:temp;
        }
        if(i >m)
        {
            if(a[i] > heap[0])
            {
                long long p =0;
                remove2(p);
                insert2(a[i]);
                sum = sum - p + a[i];
                long long temp = sum - (long long)d * i;
                res = res>temp?res:temp;
            }
        }
    }

    cout<<res;
    return 0;
}


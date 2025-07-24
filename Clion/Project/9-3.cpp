//不用建立霍夫曼树，只需要只要加上数值就行

#include<iostream>
using namespace std;


int heap[1005] = { 0 };

int currentsize = 0;


void siftDown2(int start, int m)
{
    int i = start, j = 2 * i + 1;
    int temp = heap[i];
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
    int temp = heap[j];
    while (j > 0) {
        if (heap[i] <= temp) break;
        else { heap[j] = heap[i]; j = i; i = (i - 1) / 2; }
    }
    heap[j] = temp;
}

bool insert2(int x) {
    heap[currentsize] = x;
    siftUp2(currentsize);
    currentsize++;
    return  true;
}
bool remove2(int &x) {
    x = heap[0];
    heap[0] = heap[currentsize - 1];
    currentsize--;
    siftDown2(0, currentsize - 1);
    return true;
}



int main()
{
    int n;
    cin>>n;
    long long res = 0;
    int q;
    for(int i =0;i<n;i++) { cin>>q;insert2(q); }
    for(int i=0;i<n-1;i++){
        int temp1 = 0,temp2 = 0;

        remove2(temp1);
        remove2(temp2);
        res = res+temp1+temp2;
        insert2(temp1+temp2);


    }

    cout<<res;
    return 0;
}
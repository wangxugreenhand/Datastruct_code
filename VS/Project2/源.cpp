#include<iostream>
using namespace std;



inline void readint(int& a) {
    a = 0; char c; int sgn = 1;
    while ((c = getchar()) < 48) if (c == '-') sgn = -1;
    do a = a * 10 + (c ^ 48);
    while ((c = getchar()) > 47);
    a *= sgn;
}
int heap[9000000] = { 0 };

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
bool remove2() {
    heap[0] = heap[currentsize - 1];
    currentsize--;
    siftDown2(0, currentsize - 1);
    return true;
}




int main()
{
    int n, k;
    cin >>n >> k;
    int v;
    for (int i = 0; i < n; i++) {
        readint(v);
        if (i < k)
            insert2(v);
        else
        {
            if (v < heap[0]) continue;
            else {
                heap[0] = v;
                siftDown2(0, k - 1);
            }
        }
    }

    
    std::printf("%d", heap[0]);
    return 0;



}
//使用最小堆


#include<iostream>
using namespace std;



inline void read_int (int& a) {
    a=0; char c; int sgn=1;
    while((c=getchar())<48) if (c == '-') sgn =-1;
    do a=a*10+(c^48);
    while((c=getchar())>47);
    a *= sgn;
}
int heap_max[9000000] = {0};
int a[9000000] = {0};

int currentsize2 = 0;
//int currentsize2 = 0;

//void siftDown1(int start,int m)
//{
//    int i = start, j = 2*i+1;
//    int temp = heap_min[i];
//    while(j <= m){
//        if(j<m && heap_min[j] > heap_min[j+1]) j++;
//        if(temp <= heap_min[j]) break;
//        else{heap_min[i] = heap_min[j];i = j;j = 2*j + 1;}
//    }
//    heap_min[i] = temp;
//}
//void siftUp1(int start)
//{
//    int j = start,i = (j-1)/2;
//    int temp = heap_min[j];
//    while(j>0){
//        if(heap_min[i] <= temp) break;
//        else{heap_min[j] = heap_min[i];j = i;i = (i-1)/2;}
//    }
//    heap_min[j] = temp;
//}

//
//bool insert1(int x){
//    heap_min[currentsize1] = x;
//    siftUp1(currentsize1);
//    currentsize1++;
//    return  true;
//}
//bool remove1(){
//
//    heap_min[0] = heap_min[currentsize1 - 1];
//    currentsize1--;
//    siftDown1(0,currentsize1-1);
//}

void siftDown2(int start,int m)
{
    int i = start, j = 2*i+1;
    int temp = heap_max[i];
    while(j <= m){
        if(j<m && heap_max[j] < heap_max[j+1]) j++;
        if(temp >= heap_max[j]) break;
        else{heap_max[i] = heap_max[j];i = j;j = 2*j + 1;}
    }
    heap_max[i] = temp;
}
void siftUp2(int start)
{
    int j = start,i = (j-1)/2;
    int temp = heap_max[j];
    while(j>0){
        if(heap_max[i] >= temp) break;
        else{heap_max[j] = heap_max[i];j = i;i = (i-1)/2;}
    }
    heap_max[j] = temp;
}

bool insert2(int x){
    heap_max[currentsize2] = x;
    siftUp2(currentsize2);
    currentsize2++;
    return  true;
}
bool remove2(){
    heap_max[0] = heap_max[currentsize2 - 1];
    currentsize2--;
    siftDown2(0,currentsize2-1);
}
bool alt(int x)
{
    heap_max[0] = heap_max[currentsize2 - 1];
    currentsize2--;
    siftDown2(0,currentsize2-1);
}
void Maxheap(int n){
    for(int i = 0;i<n;i++)
        heap_max[i] = a[i];
    currentsize2 = n;
    int currentPos = (currentsize2-2)/2;
    while(currentPos >= 0){
        siftDown2(currentPos,currentsize2-1);
        currentPos--;
    }
}


int main()
{
    int n,k;
    read_int(n);
    read_int(k);
    int rem = 1;

    for(int i =0; i<n;i++) {
        read_int(a[i]);
    }
    Maxheap(k);
    for(int i = k;i<n;i++){
        if(a[i]>heap_max[0]) continue;
        else{
            insert2(a[i]);
            remove2();
        }
    }
    std::printf("%d",heap_max[0]);



}
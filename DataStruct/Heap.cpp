#include "Heap.h"
MinHeap::MinHeap(int size) {
    maxSize = size;
    currentSize = 0;
    minHeap = new int[maxSize];
}
MinHeap::MinHeap(int *arr, int n) {
    maxSize = n + 50;
    currentSize = n;
    minHeap = new int[maxSize];
    for (int i = 0; i < n; i++) {
        minHeap[i] = arr[i];
    }
    for (int i = (currentSize - 2) / 2; i >= 0; i--) {  //从最后一个非叶子节点开始调整
        siftDown(i, currentSize - 1);
    }
}

void MinHeap::siftDown(int start, int m) {
    int i = start, j = 2 * i +1;
    int temp = minHeap[i];
    while(j <= m){
        if(j < m && minHeap[j] > minHeap[j + 1]) j++; //找出左右孩子中较小的
        if(temp <= minHeap[j]) break;
        else{
            minHeap[i] = minHeap[j];
            i = j;
            j = 2 * i + 1;
        }
    }
    minHeap[i] = temp;
}

bool MinHeap::insert(int x) {
    if(isFull()) return false;
    minHeap[currentSize] = x;
    siftUp(currentSize); //向上调整
    currentSize++;
    return true;
}

void MinHeap::siftUp(int start) {
    int j = start, i = (j - 1) / 2;
    int temp = minHeap[j];
    while(j > 0){
        if(minHeap[i] < temp) break;
        else{
            minHeap[j] = minHeap[i];
            j = i;
            i = (i - 1) / 2;
        }
    }
    minHeap[j] = temp;   //写上最后确定的位置
}

bool MinHeap::remove(int &x) {
    if(isEmpty()) return false;
    x = minHeap[0];
    minHeap[0] = minHeap[currentSize - 1]; //将最后一个元素放到堆顶
    currentSize--;
    siftDown(0, currentSize - 1); //向下调整， 这是因为对的性质，顶点的值小于等于子节点的值
    return true;
}
#ifndef DATASTRUCT_HEAP_H
#define DATASTRUCT_HEAP_H

// 这是最小堆的实现，即优先级队列，主要考虑数据的插入去取出
// 堆：任意顶点其值的优先级都大于等于其子节点的优先级
//使用完全二叉树的顺序实现
//下标计算 i == 0: root ;2 * i + 1 : leftchild ; 2 * i + 2 : right child; (i-1)/2 : parent
//使用int型数组实现
class MinHeap {
private:
    int *minHeap;
    int currentSize;
    int maxSize;

    void siftDown(int start, int m);  //向下调整
    void siftUp(int start);           //向上调整
public:
    MinHeap(int size = 50 ); //构造函数
    MinHeap(int arr[], int n);
    ~MinHeap() {delete []minHeap;}; //析构函数
    bool insert(int x); //插入
    bool remove(int &x); //删除堆顶元素
    bool isEmpty() const {return currentSize == 0;}; //判断是否为空
    bool isFull() const {return currentSize == maxSize;}; //判断是否为满
    void MakeEmpty() {currentSize = 0;}; //清空堆
};



#endif //DATASTRUCT_HEAP_H

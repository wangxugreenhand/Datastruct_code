//
// Created by 86158 on 2025/4/16.
//

#ifndef DATASTRUCT_LINKQUEUE_H
#define DATASTRUCT_LINKQUEUE_H

template <class E>
struct QueueNode{
    E data;
    QueueNode *next;
    QueueNode(E d = 0 , QueueNode *p = nullptr) : data(d), next(p) {} //构造函数
};
template <class E>
class LinkQueue {
private:
    QueueNode<E> *front; //队头指针
    QueueNode<E> *rear; //队尾指针
public:
    LinkQueue() {front = rear = nullptr;} //构造函数
    ~LinkQueue() {makeEmpty();}; //析构函数
    void enqueue(E x); //入队
    bool dequeue(E &x); //出队
    bool getFront(E &x) const; //获取队头元素
    bool isEmpty() const {return front == nullptr;} //判断队列是否为空
    void makeEmpty(); //清空队列
};


#endif //DATASTRUCT_LINKQUEUE_H

//
// Created by 86158 on 2025/4/16.
//

#include "LinkQueue.h"
#include <iostream>
using namespace std;

template <class E>
void LinkQueue<E>::enqueue(E x){
    QueueNode<E> *p = new QueueNode<E>(x); //创建新节点
    if(rear == nullptr){ //队列为空
        front = rear = p; //队头和队尾都指向新节点
    }else{
        rear->next = p; //将新节点链接到队尾
        rear = p; //更新队尾指针
    }
}
template <class E>
bool LinkQueue<E>:: dequeue(E& x){
    if(isEmpty()) return false;
    LinkQueue* p = front;
    front = front->next; //更新队头指针
    x = p->data; //获取队头元素
    delete p; //释放队头节点;
    return true;
}
template <class E>
bool LinkQueue<E>::getFront(E& x)const{
    if(isEmpty()) return false;
    x = front->data; //获取队头元素
    return true;
}
template <class E>
void LinkQueue<E>::makeEmpty() {
    LinkQueue* p = front;
    while(front != NULL){
        front = front->next;
        delete p;
    }
    rear = nullptr; //清空队列后，队尾指针也置为空
}
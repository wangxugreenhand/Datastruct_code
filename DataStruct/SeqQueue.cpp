//
// Created by 86158 on 2025/4/16.
//

#include "SeqQueue.h"
#include <iostream>
using namespace std;

template <class E>
SeqQueue<E>::SeqQueue(int x):front(0), rear(0), maxsize(0){
    elements = new E[maxsize];;
}
template<class E>
SeqQueue<E>::~SeqQueue() {
    delete[] elements;
    elements = NULL;
}
template <class E>
bool SeqQueue<E>::Enqueue(E x) {
    if(isFull()) return false;
    elements[rear] = x;
    rear = (rear + 1) % maxsize;
    return true;
}
template <class E>
bool SeqQueue<E>::Dequeue(E& x) {
    if(isEmpty()) return false;
    x = elements[front];
    front = (front + 1) % maxsize;
    return true;
}
template <class E>
bool SeqQueue<E>::getFront(E& x) const {
    if(isEmpty()) return false;
    x = elements[front];
    return true;
}
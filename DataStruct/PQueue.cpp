//
// Created by 86158 on 2025/4/16.
//

#include "PQueue.h"
#include<iostream>
using namespace std;
template<class E>
PQueue<E>::PQueue(int x) {
    maxsize = x;
    data = new E[maxsize];
    front = 0;
    rear = 0;
}
template<class E>
bool PQueue<E>::Enqueue(E x) {
    if(isFull()) return false;
    elements[rear] = x;
    rear = rear+1;
    adjust();
    return true;
}
template<class E>
bool PQueue<E>::Dequeue(E& x) {
    if(isEmpty()) return false;
    x = elements[front];
    while(front < rear - 1) {
        elements[front] = elements[front + 1];
        front++;
    }
    rear--;
    return true;
}
template<class E>
bool PQueue<E>::getFront(E& x) const {
    if(isEmpty()) return false;
    x = elements[front];
    return true;
}
template <class E>
void PQueue<E>::adjust() {
    E temp = elements[rear - 1];
    int i;
    for(i = rear - 2; i >=0; i--){
        if(elements[i] <= temp) break;
        elements[i + 1] = elements[i];
    }
    elements[i + 1] = temp;
}
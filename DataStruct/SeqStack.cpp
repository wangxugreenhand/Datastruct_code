//
// Created by 86158 on 2025/4/16.
//

#include "SeqStack.h"
#include <iostream>
using namespace std;

template <class E>
void SeqStack<E>::overflow() {
    E* newData = new E[maxSize * 2];
    for (int i = 0; i < maxSize; i++) {
        newData[i] = data[i];
    }
    maxSize *= 2;
    delete[] data;
    data = newData;
}
template <class Type>
SeqStack<Type>::SeqStack(int size) {
    maxSize = size;
    data = new Type[maxSize];
    top = -1;
}
template <class Type>
SeqStack<Type>::~SeqStack() {
    delete[] data;
}
template <class Type>
void SeqStack<Type>::push(const Type &item) {
    if (isFull()) {
        overflow();
    }
    data[++top] = item;
}
template <class Type>
bool SeqStack<Type>::pop(Type &x) {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return false;
    }
    x = data[top--];
    return true;
}
template <class Type>
bool SeqStack<Type>::getTop(Type& x) const {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return false;
    }
    x = data[top];
    return true;
}
template <class Type>
void SeqStack<Type>::printStack() const {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }
    for (int i = top; i >= 0; i--) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main(){
    return 0;
}

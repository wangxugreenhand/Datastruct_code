//
// Created by 86158 on 2025/4/16.
//

#include "LinkStack.h"
#include <iostream>
using namespace std;
template <class E>
void LinkStack<E>::push(E x){
    StackNode<E> * p = new StackNode<E>(x, top); //创建新节点，放在栈顶
    top = p; //更新栈顶指针
}
template <class E>
bool LinkStack<E>::pop(E &x){
    if(isEmpty()){
        cout << "栈空，无法出栈" << endl;
        return false;
    }
    LinkStack<E> * p = top;
    top = top->next;
    x = p->data; //获取栈顶元素
    delete p; //释放栈顶节点
    return true;
}
template <class E>
bool LinkStack<E>::getTop(E &x) const{
    if(isEmpty()){
        cout<< "empty Stack" <<endl;
        return false;
    }
    x = top->data;
    return true;
}
template <class E>
void LinkStack<E>::makeEmpty(){
    StackNode<E> *p = top;
    while(top != nullptr){
        top = top->next;
        delete p;
    }
}
template <class E>
void LinkStack<E>::printStack(StackNode<E>* p, int & i) const{
    if(top != NULL){
        //逆向打印栈，从底部开始打印
        if(p->next != NULL){
            printStack(p->next, i++);
        }
        cout<< i <<": " << p->data << endl;
    }
}
//
// Created by 86158 on 2025/4/16.
//

#ifndef DATASTRUCT_LINKSTACK_H
#define DATASTRUCT_LINKSTACK_H

template <class E>
struct StackNode{
    E data;
    StackNode *next;
    StackNode(E d = 0 , StackNode *p = nullptr) : data(d), next(p) {} //构造函数
};
template <class E>
class LinkStack {
private:
    StackNode<E> *top; //栈顶指针
public:
    void printStack(StackNode<E>* p, int & i) const; //打印栈
    LinkStack() {top = nullptr;} //构造函数
    ~LinkStack() {makeEmpty();}; //析构函数
    void push(E x); //入栈
    bool pop(E &x); //出栈
    bool getTop(E &x) const; //获取栈顶元素
    bool isEmpty() const {return top == nullptr;} //判断栈是否为空
    void makeEmpty(); //清空栈
};


#endif //DATASTRUCT_LINKSTACK_H

#ifndef DATASTRUCT_SeqSTACK_H
#define DATASTRUCT_SeqSTACK_H


template <class Type > class SeqStack {
private:
    Type *data;
    int top;
    int maxSize;
public:
    SeqStack(int size = 10);
    ~SeqStack();
    void overflow();
    void push(const Type &item);
    bool pop(Type& x);
    bool getTop(Type &x) const;
    bool isEmpty() const {return top == -1;};
    bool isFull() const  {return top == maxSize - 1;};
    void MakeEmpty() {top = -1;};
    int getSize() const {return top + 1;};
    void printStack() const;
};



#endif
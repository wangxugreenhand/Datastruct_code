//
// Created by 86158 on 2025/4/16.
//

#ifndef DATASTRUCT_SEQQUEUE_H
#define DATASTRUCT_SEQQUEUE_H

template <class E>
class SeqQueue { //循环队列
private:
    int rear, front;
    E* elements;;
    int maxsize;
public:
    SeqQueue(int x = 10);
    ~SeqQueue();
    bool Enqueue(E x);
    bool Dequeue(E& x);
    bool getFront(E& x) const;
    void makeEmpty(){front = rear = 0;};
    bool isEmpty() const { return front == rear; };
    bool isFull() const { return (rear + 1) % maxsize == front; };
    int getSize(){return (rear - front + maxsize) % maxsize;};

};


#endif //DATASTRUCT_SEQQUEUE_H

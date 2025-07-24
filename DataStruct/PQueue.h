//
// Created by 86158 on 2025/4/16.
//

#ifndef DATASTRUCT_PQUEUE_H
#define DATASTRUCT_PQUEUE_H

template <class E>
class PQueue {
private:
    int rear, front;
    E* elements;
    int maxsize;
public:
    PQueue(int x = 10);
    ~PQueue()     {delete[] elements; elements = nullptr;};
    bool Enqueue(E x);
    bool Dequeue(E& x);
    bool getFront(E& x) const;
    void makeEmpty(){front = rear = 0;};
    bool isEmpty() const { return front == rear; };
    bool isFull() const { return rear == maxsize; };
    int getSize(){return rear;};
    void adjust();
};


#endif //DATASTRUCT_PQUEUE_H

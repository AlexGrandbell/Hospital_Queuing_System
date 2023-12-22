//
// Created by 沈嘉瑞 on 2023.10.16.
//

#ifndef HOSPITAL_QUEUING_SYSTEM_SQQUEUE_H
#define HOSPITAL_QUEUING_SYSTEM_SQQUEUE_H
#include "Record.h"

const int QueueMaxSize = 100;

//顺序栈定义
template<class T>
class SqQueue {
private:
    T* data;
    int front,rear;
public:
    SqQueue();
    ~SqQueue();
    bool empty();
    bool full();
    void push(T);
    T pop();
    T getTail();
    int size();
};

//构造函数
template<class T>
SqQueue<T>::SqQueue() {
    front = 0;
    rear = 0;
    data = new T[QueueMaxSize];
}

//析构函数
template<class T>
SqQueue<T>::~SqQueue() {
    delete [] data;
}

//是否为空
template<class T>
bool SqQueue<T>::empty() {
    return front == rear;
}

//是否为满
template<class T>
bool SqQueue<T>::full() {
    return (rear + 1)%QueueMaxSize == front;
}

//入队函数
template<class T>
void SqQueue<T>::push(T e) {
    if (full()){
        throw QueueFullException("队列已满，挂号失败。");
    }
    data[rear] = e;
    rear = (rear+1)%QueueMaxSize;
}

//出队函数
template<class T>
T SqQueue<T>::pop() {
    if (empty()){
        throw QueueEmptyException("队列是空的，操作失败。");
    }
    T tmp = data[front];
    front = (front + 1)%QueueMaxSize;
    return tmp;
}

//得到队尾(即将出队的)
template<class T>
T SqQueue<T>::getTail() {
    if (empty()){
        throw QueueEmptyException("队列是空的。");
    }
    return data[front];
}

//数量
template<class T>
int SqQueue<T>::size() {
    return (rear - front + QueueMaxSize)%QueueMaxSize;
}

#endif //HOSPITAL_QUEUING_SYSTEM_SQQUEUE_H

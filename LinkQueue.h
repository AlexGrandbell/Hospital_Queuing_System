//
// Created by 沈嘉瑞 on 2023.10.16.
//

#ifndef HOSPITAL_QUEUING_SYSTEM_LINKQUEUE_H
#define HOSPITAL_QUEUING_SYSTEM_LINKQUEUE_H
#include "Record.h"

//链式队列实定义
template<class T>
struct LinkNode{
    T data;
    LinkNode* next;
    LinkNode():next(nullptr){};
    LinkNode(T d):data(d),next(nullptr){}
};
template<class T>
class LinkQueue {
private:
    LinkNode<T>* front;
    LinkNode<T>* rear;
public:
    LinkQueue();
    ~LinkQueue();
    bool empty();
    void push(T);
    T pop();
    T getTail();
    int size();
};

//构造函数
template<class T>
LinkQueue<T>::LinkQueue() {
    front = new LinkNode<T>;
    rear = front;
}

//析构函数
template<class T>
LinkQueue<T>::~LinkQueue(){
    if (front->next == nullptr){
        delete front;
        return;
    } else{
        LinkNode<T>* curr = front;
        LinkNode<T>* now = front;
        while (curr->next != nullptr){
            now = curr;
            curr = curr->next;
            delete now;
        }
        delete curr;
    }
    front = nullptr;
}

//是否为空
template<class T>
bool LinkQueue<T>::empty() {
    if (front->next== nullptr){
        return true;
    } else{
        return false;
    }
}

//入队函数
template<class T>
void LinkQueue<T>::push(T e) {
    rear->next = new LinkNode(e);
    rear = rear->next;
}

//出队函数
template<class T>
T LinkQueue<T>::pop() {
    if (empty()) {
        throw QueueEmptyException("队是空的。操作失败。");
    } else if (size() == 1){
        T tmp = front->next->data;
        delete front->next;
        front->next = nullptr;
        rear = front;
        return tmp;
    } else{
        T tmp = front->next->data;
        LinkNode<T>* curr = front->next;
        front->next = front->next->next;
        delete curr;
        return tmp;
    }
}

//得到队尾(即将出队的)
template<class T>
T LinkQueue<T>::getTail() {
    if (empty()) {
        throw QueueEmptyException("栈是空的。操作失败。");
    } else {
        return front->next->data;
    }
}

//数量
template<class T>
int LinkQueue<T>::size() {
    int num = 0;
    if (!empty()) {
        LinkNode<T>* curr = front;
        while (curr->next != nullptr){
            curr = curr->next;
            num ++;
        }
    }
    return num;
}

#endif //HOSPITAL_QUEUING_SYSTEM_LINKQUEUE_H

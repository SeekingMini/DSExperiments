/*
 * Filename: Queue.h
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-11-01
 */
#ifndef Q2_QUEUE_H
#define Q2_QUEUE_H

#include <iostream>

typedef int ElemType;
/*
 * 定义结点类
 */
class Node{
public:
    ElemType data;
    Node* next;
};
typedef Node* NodePtr;  // 指向结点的指针

class Queue {
private:
    int length;  // 队列长度
protected:
    NodePtr front;
    NodePtr rear;
public:
    Queue(){
        front = new Node;
        front->data=-1;  // 队头指针不存储元素
        rear=front;  // 初始化时为指针等于头指针
        front->next= nullptr;
        length=0;
    };
    ~Queue(){ClearQueue();};
    void ClearQueue();
    bool QueueEmpty();
    int QueueLength();
    void GetHead(ElemType*);
    void EnQueue(ElemType);
    void DeQueue(ElemType*);
    void QueueTraverse();
};


#endif //Q2_QUEUE_H

/*
 * Filename: CirQueue.h
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-11-13
 */

#ifndef EXQ3_CIRQUEUE_H
#define EXQ3_CIRQUEUE_H

#include <iostream>

#define MAXNUM 10000  // 规定斐波那契数列中的最大数不超过10000
typedef int ElemType;
/*
 * 定义结点类
 */
struct Node{
    ElemType data;  // 数据域
    Node* next;
};
typedef Node* NodePtr;  // 指向结点的指针

class CirQueue {
protected:
    NodePtr front;
    NodePtr rear;
    int maxsize;  // 循环队列的最大容量
    int length;  // 当前队列存储元素的个数
public:
    CirQueue(int k){
        maxsize=k;
        length=0;
        front=new Node;
        front->data=-1;  // -1表示队头不存储元素
        front->next= nullptr;
        rear=front;
    };
    ~CirQueue(){};
    void push(ElemType);
    void print();
};


#endif //EXQ3_CIRQUEUE_H

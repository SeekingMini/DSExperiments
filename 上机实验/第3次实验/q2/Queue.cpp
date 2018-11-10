/*
 * Filename: Queue.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-11-01
 */
#include "Queue.h"

/*
 * 清空队列
 */
void Queue::ClearQueue() {
    if(front->next== nullptr)return;

    NodePtr p=front->next;
    NodePtr t;
    while(p!=rear){
        t=p->next;
        front->next=p->next;
        delete p;
        p=t;
    }
    front->next=p->next;
    delete p;
    length=0;
}

/*
 * 判断队列是否为空
 */
bool Queue::QueueEmpty() {
    return front==rear;
}

/*
 * 返回队列的长度
 */
int Queue::QueueLength() {
    return length;
}

/*
 * 用e返回队列的队头元素
 */
void Queue::GetHead(ElemType *e) {
    if(front->next== nullptr)return;  // 空列表
    *e=front->next->data;
}

/*
 * 插入元素e使其成为队列新的队尾元素
 */
void Queue::EnQueue(ElemType e) {
    NodePtr p=front;
    NodePtr s;

    s=new Node;
    s->data=e;

    while(p!=rear){
        p=p->next;
    }

    s->next=p->next;
    p->next=s;
    rear=s;
    length++;
}

/*
 * 删除队头元素并用e返回其值（队头元素出列）
 */
void Queue::DeQueue(ElemType *e) {
    if(front->next== nullptr)return;
    NodePtr p=front;
    NodePtr s=front->next;

    *e = s->data;
    p->next=s->next;
    delete s;
    length--;
}

/*
 * 遍历队列元素并打印
 */
void Queue::QueueTraverse() {
    if(front->next== nullptr)return;
    NodePtr p=front;

    while(p!= rear){
        p=p->next;
        std::cout<<p->data<<"\t";
    }
}
/*
 * Filename: CirQueue.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-11-13
 */

#include "CirQueue.h"


/*
 * 向循环队列中插入元素
 */
void CirQueue::push(ElemType e) {
    NodePtr s;
    s=new Node;
    s->data=e;

    if(length<maxsize){
        NodePtr p=front;
        while(p!=rear){
            p=p->next;
        }

        s->next=p->next;
        p->next=s;
        rear=s;
        rear->next=front->next;  // 队尾元素的next指针指向队头元素
        length++;
    }
    else{  // 当队列满了，实现的时覆盖而非插入操作
        NodePtr p=rear->next;
        p->data=e;
        rear=p;
    }
}

/*
 * 遍历一遍队列并打印元素
 */
void CirQueue::print() {
    if(front==rear)return;

    NodePtr p=front->next;
    for(int l=0;l<length;l++){
        std::cout<<p->data<<"\t";
        p=p->next;
    }
}
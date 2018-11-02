/*
 * Filename: DCList.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-18
 */
#include "DCList.h"

/*
 * 置空链表
 */
void DCList::clear() {
    NodePtr p=head;
    NodePtr q;
    int l=length;

    while(l++<length){
        q=p->next;
        p->next = q->next;
        delete q;
    }
    length =0;
}

/*
 * 添加元素e到链表的尾端
 * 说明：尾端结点指向链表第1个元素
 */
void DCList::addElem(int e) {
    NodePtr p=head;
    NodePtr s;
    int j=0;

    s=new Node;
    s->data=e;

    while(j<length){
        p=p->next;
        j++;
    };

    p->next=s;
    s->next= head->next;
    s->prior=p;

    length++;
}

/*
 * 把结点元素为id的元素向前（后）移动n个位置
 * 说明：首先用一根指针p使其遍历链表定位至结点元素为id的结点。再根据n的大小使另一根指针定位到相应位置，从而实现插入。时间复杂度为O(n)。
 */
void DCList::moveElem(int id, int n) {
    NodePtr p = head;
    NodePtr r;
    NodePtr s;
    int i=0;

    while(p->data != id){
        p=p->next;
    }

    if(n>0){  // 向后移
        r=p;
        while(i++<n){
            r=r->next;
        }
        s=p;
        p->prior->next=p->next;
        p->next->prior=p->prior;

        s->next =r->next;
        s->prior=r;

        r->next->prior=s;
        r->next=s;
    }
    else{  // 向前移
        r=p;
        while(i++<-n){
            r=r->prior;
        }
        s=p;
        p->prior->next=p->next;
        p->next->prior=p->prior;

        s->prior=r->prior;
        s->next=r;

        r->prior->next=s;
        r->prior=s;
    }
}

/*
 * 遍历链表元素并打印
 */
void DCList::print() {
    NodePtr p=head;
    int l=length;
        while(l-->0){
            p=p->next;
            std::cout<<p->data<<" ";
        }
}

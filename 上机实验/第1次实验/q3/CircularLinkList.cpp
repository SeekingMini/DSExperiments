/*
 * Filename: CircularLinkList.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-20
 */
#include "CircularLinkList.h"

/*
 * 置空链表
 */
void CircularLinkList::clear() {
    NodePtr p=head;
    NodePtr r;
    int l=length;

    while(l-->0){
        r=p;
        p=p->next;
        r->next=p->next;
        delete p;
    }
}

/*
 * 在尾结点后插入元素为e的结点（后插）
 * 注意！这是不规范的函数！
 */
Status CircularLinkList::addElem(ElemType e) {
    NodePtr p=head;
    NodePtr s;
    int j= 0;

    s = new Node;
    s->data=e;

    while(j<length){
        p=p->next;
        j++;
    }
    p->next=s;
    s->next=head->next;  // 结点指向头结点后的第1个结点

    length += 1;

    return OK;
}

/*
 * 删除第i个结点，并将头指针移向第i+1个结点
 */
Status CircularLinkList::deleteElem(int i, ElemType &e) {
    NodePtr p=head;
    NodePtr r;
    int j =0;

    if(!head){
        return ERROR;
    }
    while(j<i){
        ++j;
        r=p;
        p=p->next;
    }

    e=p->data;
    if(p == p->next){
        head= nullptr;
    }
    else{
        r->next = p->next;
        head->next=r->next;
    }
    delete p;
    length -= 1;
    return OK;
}
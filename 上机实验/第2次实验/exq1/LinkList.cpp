/*
 * Filename: LinkList.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-31
 */
#include "LinkList.h"

/*
 * 置空链表
 */
void LinkList::clear() {
    NodePtr p, q;
    p = head;

    if(p->next== nullptr){  // 空链表
        return;
    }

    int l = length;
    while(l-->0){
        q=p->next;
        p->next = q->next;
        delete q;
    }
    head->next= nullptr;
    length = 0;
}

/*
 * 返回头节点
 */
Node* LinkList::getHead() {
    return head;
}

/*
 * 向链表尾部添加元素（后插）
 */
void LinkList::addElem(ElemType e) {
    NodePtr s;
    NodePtr p=head;
    int l=length;

    while(l-->0){
        p=p->next;
    }

    s=new Node;
    s->data=e;

    s->next=p->next;
    p->next=s;
    length++;
}

/*
 * 遍历链表元素并打印
 */
void LinkList::print() {
    NodePtr p = head;
    if(p->next == nullptr){
        return;
    }

    int l=length;
    while(l-->0){
        p = p->next;
        std::cout << p->data << "\t";
    }
}

/*
 * 就地逆置链表
 */
void LinkList::adverse() {
    NodePtr p=head->next;
    NodePtr s;

    head->next= nullptr;  // 断开头节点
    while(p!= nullptr){
        s=p->next;
        p->next=head->next;
        head->next=p;
        p=s;
    }
}
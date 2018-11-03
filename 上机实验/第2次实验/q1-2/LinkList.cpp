/*
 * Filename: LinkList.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-29
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
 * 算法思路：单链表的插入排序法跟普通的数组的插入排序法思路大致相同，但是由于元素的移动涉及到指针，所以元素移动相应的会更加复杂。时间复杂度为O(n^2)。
 */
void LinkList::InsertSort() {
    if(head->next== nullptr || head->next->next== nullptr){  // 空链表或者链表只有1个元素
        return;
    }

    NodePtr p=head->next->next;  // 假设第1个元素已经排好序，所以p指向第2个元素

    while(p!= nullptr){
        NodePtr key=p;

        NodePtr end=head->next;
        while(key->data>=end->data&&end!=key){
            end=end->next;
        }
        if(end!=key){
            // prekey最终指向key的前驱结点
            NodePtr prekey=head;
            while(prekey->next!=key){
                prekey=prekey->next;
            }

            // end最终指向key的前驱结点
            NodePtr preend=head;
            while(preend->next!=end){
                preend=preend->next;
            }
            
            preend->next=key;
            prekey->next=key->next;
            key->next=end;
        }
        p=p->next;
    }
}

/*
 * 遍历链表元素并打印
 */
void LinkList::print() {
    NodePtr p = head;
    if(p->next == nullptr){
        return;
    }

    int l = length;
    while(l-->0){
        p = p->next;
        std::cout << p->data << "\t";
    }
}
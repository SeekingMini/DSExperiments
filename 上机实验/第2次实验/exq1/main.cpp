/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-11-01
 */
#include <iostream>
#include "LinkList.h"
using namespace std;

void merge(LinkList*, LinkList*);

int main() {
    int length;
    ElemType e;
    LinkList A;
    LinkList B;

    cin>>length;
    for(int i=0;i<length;i++){
        cin>>e;
        A.addElem(e);
    }
    cin>>length;
    for(int i=0;i<length;i++){
        cin>>e;
        B.addElem(e);
    }

    merge(&A, &B);
    A.adverse();  // 合并后的链表仍然是有序递增链表，所以要再逆置一次
    A.print();

    return 0;
}

/*
 * 在原空间进行有序链表的合并
 * 说明：将链表B的结点合并到链表A上
 * 算法思想：由于是有序链表的合并，所以采用"指针平行移动，一次扫描完成"的策略。时间复杂度为O(n)。
 */
void merge(LinkList* A, LinkList* B){
    NodePtr pa=A->getHead();
    NodePtr qa=pa->next;
    NodePtr pb=B->getHead()->next;  // 指向链表B的第1个元素
    NodePtr qb;

    B->getHead()->next= nullptr;  // 断开链表B的头节点

    while(pa&&pb){
        qb=pb->next;
        while(qa!=nullptr&&pb->data>qa->data){
                pa=pa->next;
                qa=qa->next;
            }

        pb->next=pa->next;
        pa->next=pb;
        pa=pa->next;
        pb=qb;
    }
    A->length+=B->length;
}
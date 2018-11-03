/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-11-03
 */
#include <iostream>
#include "LinkList.h"
using namespace std;

void intersection(LinkList*,LinkList*);
void difference(LinkList*,LinkList*);

int main() {
    LinkList A;
    LinkList B;
    LinkList C;
    int length;
    ElemType e;

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
    cin>>length;
    for(int i=0;i<length;i++){
        cin>>e;
        C.addElem(e);
    }

    intersection(&B,&C);
    difference(&A,&B);
    A.print();

    return 0;
}

/*
 * 在链表A中删除链表A有但链表B没有的元素，即求多重集的交集。
 * 算法思想：由于是有序链表的合并，所以采用"指针平行移动，一次扫描完成"的策略。时间复杂度为O(n)。
 */
void intersection(LinkList* A, LinkList* B){
    NodePtr pa=A->getHead()->next;
    NodePtr pb=B->getHead()->next;
    NodePtr qa;

    while(pa&&pb){
        qa=pa;
        pa=pa->next;
        while(qa->data>pb->data){
            if(pb->next!=nullptr){
                pb=pb->next;
            }
            else{
                break;
            }
        }
        if(pb!= nullptr){
            if(qa->data!=pb->data){
                A->delElem(qa->data);
            }
            else{
                if(pb->next!= nullptr){
                    pb=pb->next;
                }
            }
        }
        else{
            break;
        }
    }
}

/*
 * 在链表A中删除出现在B中的元素，即求多重集合的差集
 * 算法思想：由于是有序链表求差集，所以采用"指针平行移动，一次扫描完成"的策略。时间复杂度为O(n)。
 */
void difference(LinkList* A, LinkList* B){
    NodePtr pa=A->getHead()->next;
    NodePtr pb=B->getHead()->next;
    NodePtr qa;

    while(pa){
        qa=pa;
        if(pb!= nullptr){
            while(qa->data<pb->data){
                qa=qa->next;
                if(!qa)break;
                pa=qa->next;
            }
            if(qa){
                if(qa->data==pb->data){
                    A->delElem(qa->data);
                    pb=pb->next;
                }
                else{
                    pb=pb->next;
                }
            }
            else{
                break;
            }
        }
        else{
            break;
        }
    }
}
/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-30
 */
#include <iostream>
#include "LinkList.h"
using namespace std;

void intersection(LinkList*,LinkList*);

/*
 * 两个递增有序链表求交集测试
 * 注意！题目中写明的集合，所以集合A或集合B中不应该有重复元素！
 */
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

    intersection(&A,&B);
    A.print();
    return 0;
}

/*
 * 算法思想：非常容易想到的就是首先对A中所有元素进行遍历，如果这个元素在B中没有，就删除这个元素，最终得到的C就是A与B的交集。时间复杂度为O(n^2)。
 */
void intersection(LinkList* A, LinkList* B){
    if(B->getHead()->next==nullptr){  // B是空集，则A与B的交集为空集
        A->clear();
    }

    NodePtr pa=A->getHead()->next;

    while(pa!= nullptr){
        ElemType e=pa->data;
        NodePtr pb=B->getHead()->next;
        bool flag=false;
        while(pb!= nullptr){
            if(pa->data!=pb->data){
                pb=pb->next;
            }
            else{
                flag=true;
                break;
            }
        }
        if(!flag){
            A->delElem(e);
        }
        pa=pa->next;
    }

}
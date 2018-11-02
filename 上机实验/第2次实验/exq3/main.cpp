/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-11-01
 */
#include <iostream>
#include "LinkList.h"
using namespace std;

void intersection(LinkList*,LinkList*);

int main() {
    LinkList L;
    L.print();
    return 0;
}

/*
 * 在链表A中删除链表A有但链表B没有的元素，即求A与B的交集
 *
 */
void intersection(LinkList* A, LinkList* B){
    NodePtr pa=A->getHead();
    NodePtr pb=B->getHead()->next;
    NodePtr qa=A->getHead()->next;

    while(pb!= nullptr){

    }
}
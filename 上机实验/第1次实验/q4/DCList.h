/*
 * Filename: DCList.h
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-18
 */
#include <iostream>
#ifndef Q4_DCLIST_H
#define Q4_DCLIST_H

typedef int ElemType;

class Node{
public:
    ElemType data;  // 结点元素
    Node* next;  // 指向后继结点的指针
    Node* prior;  // 指向前驱结点的指针
};
typedef Node* NodePtr;  // 指向结点的指针
/*
 * 定义一个双链表来解第4题
 * 注意！为了解题方便，此双链表有很多不规范的地方！
 */

class DCList {
protected:
    Node* head;
private:
    int length;  // 链表元素的个数
public:
    DCList(){
        head=new Node;
        head->data=0;
        head->next= nullptr;
        head->prior= nullptr;
        length=0;
    };
    ~DCList(){clear();};
    void clear();
    void addElem(int);
    void moveElem(int, int);
    void print();
};


#endif //Q4_DCLIST_H

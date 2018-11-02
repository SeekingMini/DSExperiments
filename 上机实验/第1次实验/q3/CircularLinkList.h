/*
 * Filename: CircularLinkList.h
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-20
 */
#ifndef Q3_CIRCULARLINKLIST_H
#define Q3_CIRCULARLINKLIST_H

#include <lber.h>
#include<iostream>

#define Status int
#define OK 1
#define ERROR 0

typedef int ElemType;
class Node{
public:
    ElemType data;
    Node* next;
};
typedef Node* NodePtr;  // 指向Node的类

/*
 * 循环单链表
 * 说明：定义这个循环单链表只是为了解决约瑟夫环队列问题，出于解题的方便，其中有一些函数定义得不规范
 */
class CircularLinkList {
private:
    int length;
protected:
    NodePtr head = new Node;
public:
    CircularLinkList(){
        head->next= nullptr;
        head->data=0;
        length = 0;  // 链表长度，即元素个数
    };
    ~CircularLinkList(){clear();};
    void clear();
    Status addElem(ElemType e);
    Status deleteElem(int i, ElemType& e);
};


#endif //Q3_CIRCULARLINKLIST_H

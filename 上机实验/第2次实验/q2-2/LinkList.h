/*
 * Filename: LinkList.h
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-30
 */
#include <iostream>

typedef int ElemType;
/*
 * 定义一个结点类
 */
class Node{
public:
    ElemType data;
    Node *next;
};
typedef Node* NodePtr;  // 定义一个指向类的指针

#ifndef Q2_LINKLIST_H
#define Q2_LINKLIST_H

/*
 * 阉割版的单链表，有很多功能删减了，只添加了对解题有用的功能。
 */
class LinkList {
protected:
    Node *head;  // 定义一个头节点用于指向第一个结点
private:
    int length;  // 个人感觉再定义一个私有变量来表示长度更加方便
public:
    LinkList(){
        head = new Node;  // 为头结点申请新的空间
        head -> data = -10000;  // 头节点不储存元素
        head -> next = nullptr;
        length = 0;
    };
    ~LinkList(){clear();};
    void clear();
    NodePtr getHead();
    void addElem(ElemType e);
    void delElem(ElemType e);
    void print();
};


#endif //Q2_LINKLIST_H

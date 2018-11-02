/*
 * Filename: LinkList.h
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-18
 */
#include <iostream>

#define OK 1
#define ERROR 0

typedef int Status;
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


class LinkList {
protected:
    Node *head;  // 定义一个头节点用于指向第一个结点
private:
    int length;  // 个人感觉再定义一个私有变量来表示长度更加方便
public:
    LinkList(){
        head = new Node;  // 为头结点申请新的空间
        head -> data = 0;  // 头节点不储存元素
        head -> next = nullptr;
        length=0;
    };
    ~LinkList(){ClearList();};
    void ClearList();
    bool ListEmpty();
    int ListLength();
    Status GetElem(int i, ElemType &e);
    Status LocateElem(ElemType e, int &n);
    Status PriorElem(ElemType cur_e, ElemType &e);
    Status NextElem(ElemType cur_e, ElemType &e);
    Status ListInsert(ElemType e, int p);
    Status SortListInsert(ElemType e);
    Status ListDelete(ElemType p);
    void ListTraverse();
    void Adverse();
    void DeleteDuplicates();
    void RangeDelete(ElemType, ElemType);
    void InsertSort();
};


#endif //Q2_LINKLIST_H

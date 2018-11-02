/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-18
 */
#include <iostream>
#include "LinkList.h"
using namespace std;

/*
 * 测试非循环单链表
 */
int main() {
    ElemType e;
    ElemType n;
    LinkList L;

    cout<<"Initialize a LinkList"<<endl;
    cout << "Insert 1, 3, 5，7，9, ..., 39  into LinkList" << endl;
    for(int k=1;k<=20;k++){
        L.ListInsert(2*k-1, k);
    }

    if (L.ListEmpty()){
        cout << "LinkList is Empty"<< endl;
    }
    else{
        cout << "LinkList is not Empty" << endl;
    }
    cout << "The Length of LinkList is " << L.ListLength() << endl;

    L.GetElem(15, e);
    cout << "The fifteenth element of LinkList is " << e <<endl;

    L.LocateElem(39, n);
    cout << "The element 39 is at position " << n << " of LinkList" <<endl;

    L.NextElem(23, e);
    cout << "The next element of 23 is " << e << endl;

    L.PriorElem(9, e);
    cout << "The prior element of 9 is " << e << endl;

    L.ListDelete(7);
    cout << "Delete the element 7 of LinkList" << endl;

    L.ListInsert(99, 3);
    cout << "The LinkList is  as followed:" << endl;
    L.ListTraverse();
    cout<< endl;

    L.Adverse();
    cout<< "Overturn LinkList" << endl;

    cout << "The LinkList is  as followed:" << endl;
    L.ListTraverse();
    cout<<endl;

    // 测试链表元素去重
    cout<<endl<<"****************************************"<<endl;
    LinkList L1;
    L1.ListInsert(3,1);
    L1.ListInsert(2,2);
    L1.ListInsert(2,3);
    L1.ListInsert(4,4);
    L1.ListInsert(4,5);
    L1.ListInsert(5,6);
    L1.ListInsert(7,7);
    L1.ListInsert(5,8);
    L1.ListInsert(8,9);
    L1.ListInsert(1,10);
    L1.ListTraverse();
    cout<<endl;
    L1.DeleteDuplicates();
    L1.ListTraverse();
    cout<<endl<<"****************************************"<<endl;

    // 有序链表插入元素，使插入后的链表认为有序链表
    LinkList L2;
    L2.ListInsert(2, 1);
    L2.ListInsert(6, 2);
    L2.ListInsert(7, 3);
    L2.SortListInsert(5);
    L2.SortListInsert(4);
    L2.ListTraverse();
    cout<<endl<<"****************************************"<<endl;

    // 有序链表删除某个范围的元素
    LinkList L3;
    L3.ListInsert(3, 1);
    L3.ListInsert(6, 2);
    L3.ListInsert(7, 3);
    L3.ListInsert(10, 4);
    L3.ListInsert(12, 5);
    L3.ListInsert(14, 6);
    cout << "The LinkList is  as followed:" << endl;
    L3.ListTraverse();
    cout<<endl;
    cout<<"Delete the element in (-2, 7)"<<endl;
    L3.RangeDelete(-2, 7);
    cout << "The LinkList is  as followed:" << endl;
    L3.ListTraverse();
    cout<<endl;
    return 1;
}
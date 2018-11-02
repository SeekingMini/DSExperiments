/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-29
 */
#include <iostream>
#include "LinkList.h"
using namespace std;

/*
 * 链表的插入排序法测试
 */
int main() {
    LinkList L;
    ElemType e;

    int length;
    cin>>length;

    for(int i=0;i<length;i++){
        cin>>e;
        L.addElem(e);
    }
    L.InsertSort();
    L.print();
    return 0;
}
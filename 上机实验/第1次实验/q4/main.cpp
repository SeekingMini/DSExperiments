/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-18
 */
#include <iostream>
#include "DCList.h"
using namespace std;

/*
 * 本题最容易想到的方法是定一个双循环链表
 */
int main(){
    DCList L;
    int n,m;
    int p,q;

    cin>>n;
    cin>>m;

    for(int i=0;i<n;i++){
        L.addElem(i+1);
    }

    for(int j=0;j<m;j++){
        cin>>p>>q;
        L.moveElem(p, q);
    }

    L.print();
    return 0;
}
/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-11-17
 */
#include <iostream>
#include "CirQueue.h"
using namespace std;

int main() {
    CirQueue Q;
    int l;
    ElemType e;

    cin>>l;
    for(int n=1;n<=l;n++){
        cin>>e;
        Q.push(e);
    }

    cout<<"Queue is as followed:"<<endl;
    Q.print();
    cout<<endl;

    cout<<"Push 22,33,44 into Queue";
    Q.push(22);
    Q.push(33);
    Q.push(44);
    cout<<endl;

    cout<<"Pop the rear element"<<endl;
    Q.pop();

    cout<<"Queue is as followed"<<endl;
    Q.print();
    return 0;
}
/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-20
 */
#include <iostream>
#include "CircularLinkList.h"
using namespace std;

/*
 * 约瑟夫环出列
 * 1.问题概述：N个人围成一圈，从第1个开始报数，第M个人将出列，然后从下一个人开始重新从1开始报数，报到M的人出列，如此循环，直到所有人都出列。
 * 2.说明：
 * （1）记N个人的编号为1, 2, 3, ..., N
 * （2）M表示报数报到M此人出列
 * 3.要求：打印出列的编号顺序
 * 4.思路：使用单循环链表解决问题非常方便！首先把头指针移向起始结点，从其开始报数。每当报到M时，就删除这个结点，并把头指针移到出列结点的后继上，
 * 然后继续报数，直到链表为空。每次按照出列顺序输出各人的编号。时间复杂度为O(mn)。
 */
int main() {
    ElemType e;
    CircularLinkList L;
    int M;
    int N;

    cout<<"Enter N: ";
    cin>>N;
    cout<<"Enter M: ";
    cin>>M;

    for(int i=1;i<=N;i++){
        L.addElem(i);
    }

    cout<<"*****链式结构实现*****"<<endl;
    for(int j=1;j<=N;j++){
        L.deleteElem(M, e);
        cout<<e<<"\t";
    }

    cout<<endl<<"*****顺序结构实现*****"<<endl;
    int a[10000],b[10000],n=N,m=M,i,k=0,j=0;

    for(i=0;i<n;i++)
        a[i]=i+1;

    while(j!=n)
    {
        for(i=0;i<n;i++)
        {
            if(a[i]==0) {
                continue;
            }
            k++;
            if(k!=m) {
                continue;
            }
            k = 0;
            b[j++]=a[i];
            a[i]=0;
        }
    }

    for(i=0;i<n;i++)
        cout<<b[i]<<"\t";

    return 0;
};
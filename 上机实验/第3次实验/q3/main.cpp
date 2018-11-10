/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-11-06
 */
#include<iostream>
#include<stack>
using namespace std;
stack <int>qu;
stack <int>quCopy;
int way=1;

void NQueens(int x,int qn)
{
    if(x==qn+1) {
        cout<<"第"<<way++<<"种："<<endl;
        quCopy=qu;
        int a[qn+2];
        for(int i=qn;i>=1;i--) {  // 鉴于栈只能从栈顶弹出元素，数组的遍历从最后一个元素开始
            a[i]=quCopy.top();
            quCopy.pop();
        }
        for(int i=1;i<=qn;i++) {
            for(int j=1;j<=qn;j++)
            {
                if(a[i]==j) cout<<"X ";
                else cout<<"O ";
            }
            cout<<"\n";  // 一行打印完后需要一个换行符
        }
        return;
    }
    for(int i=1;i<=qn;i++) {
        bool flag=false;
        quCopy=qu;
        for(int j=x-1;j>=1;j--) {
            /*
             * 判断位置冲突有2个条件
             * 1.列坐标冲突
             * 2.行坐标与列坐标的差的绝对值冲突
             */
            if((quCopy.top()==i)||(quCopy.top()-i)==(x-j)||(quCopy.top()-i)==(j-x)) break;
            quCopy.pop();
            if(quCopy.empty()) flag=true;  // 没有冲突
        }
        if(flag||x==1) {
            qu.push(i);
            NQueens(x+1, qn);
            qu.pop();
        }
    }
}

int main()
{
    int qNum;
    cin>>qNum;
    NQueens(1, qNum);//1代表该放置第一行的棋子
    return 0;
}


/*
 * Filename:
 * Author: 
 * Version: 
 * Time: 
 */
#include<stdio.h>
#include <iostream>
#include<stack>
using namespace std;
stack <int>qu;
stack <int>quCopy;
int way = 1;

void NQueens(int x,int qn)
{
    if(x == qn+1)
    {
        cout<<"第"<<way++<<"种："<<endl;
        quCopy = qu;
        int a[10];
        for(int i = 8 ; i >= 1 ; i--) {a[i] = quCopy.top();quCopy.pop();}
        for(int i = 1 ; i <= 8 ; i++)
        {
            for(int j = 1 ; j <= 8 ; j++)
            {
                if(a[i] == j) cout<<"X ";
                else cout<<"O ";
            }
            cout<<"\n";
        }
        return;
    }
    for(int i = 1 ; i <= qn ; i++)
    {
        bool flag = false;
        quCopy = qu;
        for(int j = x - 1; j >= 1 ; j--)//j代表第j行已经落的子
        {
            if((quCopy.top() == i) || (quCopy.top() - i) == (x - j) || (quCopy.top() - i) == (j - x)) break;
            //判定方法请画一个坐标系自己写写就明白了 ，一个判定列是否冲突
            //两个判定↖以及↗的两个方向
            quCopy.pop();
            if(quCopy.empty()) flag = true;//如果空了代表都不与之前所有的落子有冲突
        }
        if(flag|| x == 1)//因为第一行没有任何附加条件，所以都可以落子（x==1）
        {
            qu.push(i);//如果可以落子，那么就把当前i   push上去
            NQueens(x+1, qn);//dfs遍历下一行
            qu.pop();//回溯，把上一个push的值pop出去，进行下一个可行解的遍历，要不然q里面会无限累加值
        }
    }
}

int main()
{
    NQueens(1, 8);//1代表该放置第一行的棋子
    return 0;
}


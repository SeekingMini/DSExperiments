/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-11-07
 */
#include <iostream>
#include <list>
using namespace std;

struct window{  // 窗口的坐标
    int x1,x2;
    int y1,y2;
    int No;
};
struct operation{  // 鼠标操作的坐标
    int x,y;
};

int main() {
    window w;
    list<window>winList;
    operation o;
    list<operation>opList;
    int N,M;  // N个窗口，M次操作

    cin>>N>>M;
    for(int n=1;n<=N;n++){  // 输入各个窗口的坐标
        cin>>w.x1>>w.y1>>w.x2>>w.y2;
        w.No=n;
        winList.push_front(w);  // 插到链表头部
    }
    for(int m=1;m<=M;m++){  // 输入各个操作的坐标
        cin>>o.x>>o.y;
        opList.push_back(o);  // 插到链表尾部
    }

    list<window>::iterator winitr;
    list<operation>::iterator opitr;

    for(opitr=opList.begin();opitr!=opList.end();opitr++){
        for(winitr=winList.begin();winitr!=winList.end();winitr++){
            // 鼠标操作只要满足x1<=x<=x2和y1<=y<=y2即满足要求
            if(opitr->x>=winitr->x1&&opitr->x<=winitr->x2&&opitr->y>=winitr->y1&&opitr->y<=winitr->y2){
                window tempw{0,0,0,0};
                tempw.x1=winitr->x1;tempw.x2=winitr->x2;tempw.y1=winitr->y1;tempw.y2=winitr->y2;tempw.No=winitr->No;
                cout<<tempw.No<<endl;
                winList.erase(winitr);  // 删除该结点
                winList.push_front(tempw);  // 把删除的结点插入链表最前端（即置于各窗口最顶层）
                break;
            }
        }
        if(winitr==winList.end())cout<<"IGNORED"<<endl;
    }
    return 0;
}
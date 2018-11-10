/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-11-10
 */
#include <iostream>
using namespace std;

struct Node{
    int data=0;
    int freq=0;  // 访问频度
    Node* next= nullptr;
    Node* prior= nullptr;
};
typedef Node* NodePtr;
void LOCATE(Node*,int);

/*
 * 在双向循环链表中对每个元素增加访问频度，使被频繁访问的结点总是靠近表头结点
 * 为了简化题目，链表中默认没有重复元素~
 */
int main() {
    int e;
    int length;
    Node* head=new Node;
    head->data=-1;  // -1代表头节点不存储元素
    head->next=head;
    head->prior=nullptr;
    head->freq=10000;  // 10000代表头节点不存储频度
    NodePtr p=head;

    cout<<"输入链表长度：";
    cin>>length;
    cout<<"输入链表元素：";
    for(int i=0;i<length;i++){  // 采用尾插法插入元素到链表中
        cin>>e;
        Node* s=new Node;
        s->data=e;
        s->prior=p;
        s->next=p->next;
        p->next=s;
        p=p->next;
    }
    head->prior=p;

    int time;
    cout<<"输入访问次数：";
    cin>>time;
    cout<<"输入访问元素：";
    for(int n=0;n<time;n++){
        cin>>e;
        LOCATE(head,e);
    }

    cout<<"链表打印如下："<<endl;
    NodePtr t=head->next;
    while(t!=head){
        cout<<t->data<<"\t";
        t=t->next;
    }
    return 0;
}

/*
 * 算法思想：首先指针p定位到元素值为e的结点，其次用另外一根指针q向前扫描，直至q指向的结点的频度大于p指向的结点的频度。
 * 整个函数中有2个循环。时间复杂度为O(n)。
 */
void LOCATE(Node* head, int e){
    NodePtr p=head;

    while(p->data!=e){  // p定位到元素值为e的结点
        p=p->next;
    }
    p->freq++;  // 频度增加1

    NodePtr q=p;
    while(p->freq>=q->freq){  // 指针q向前扫描，直到q指向的结点的频度大于p指向的结点的频度
        q=q->prior;
    }

    // 以下是指针的移动操作
    p->prior->next=p->next;
    p->next->prior=p->prior;
    p->next=q->next;
    p->prior=q;
    q->next->prior=p;
    q->next=p;
}


/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-11-08
 */
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prior;
};
typedef Node* NodePtr;
void tranToDBList(NodePtr);

/*
 * 单向循环链表变为双向循环链表
 */
int main() {
    int e;
    int length;
    Node* head=new Node;
    head->data=-1;
    head->next= head;
    head->prior=nullptr;

    cin>>length;
    for(int i=0;i<length;i++){  // 采用头插法插入元素到链表中
        cin>>e;
        Node* s=new Node;
        s->data=e;
        s->prior= nullptr;
        s->next=head->next;
        head->next=s;
    }

    NodePtr p=head->next;  // 指向头节点后第1个元素
    while(p!=head){  // 正向打印一遍链表
        cout<<p->data<<"\t";
        p=p->next;
    }
    cout<<endl;

    tranToDBList(head);
    NodePtr q=head->prior;
    while(q!=head){  // 反向打印一遍链表
        cout<<q->data<<"\t";
        q=q->prior;
    }
    return 0;
}

/*
 * 把单向循环链表变为双向循环链表
 */
void tranToDBList(NodePtr head){
    if(head->next== nullptr){  // 空链表
        head->next=head;
        head->prior=head;
        return;
    }
    NodePtr p=head->next;
    p->prior=head;
    while(p!=head){
        NodePtr q=p->next;
        q->prior=p;
        p=p->next;
    }

}
/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.1
 * Time: 2018-11-10
 */
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prior;
};
typedef Node* NodePtr;
void solution(Node*);

/*
 * 用时间复杂度为O(n)的算法，将双向循环链表L=(a1,a2,a3,...,an)改造为L=(a1,a3,...,an,...,a4,a2)
 */
int main() {
    int e;
    int length;
    Node* head=new Node;
    head->data=-1;  // -1代表头节点不存储元素
    head->next= head;
    head->prior= nullptr;
    NodePtr p=head;

    cin>>length;
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

    solution(head);

    NodePtr t=head->next;  // 指向头节点后第1个元素
    while(t!=head){  // 打印一遍链表原链表
        cout<<t->data<<"\t";
        t=t->next;
    }
    return 0;
}

/*
 * 算法思想：本题要分链表长度为偶数或者奇数的情况。首先生成一个新的头节点，然后从原链表把下标为偶数的节点转移到新的头节点后，最后再拼接起来。
 * 注意其中涉及指针的移动操作非常容易出错！时间复杂度为O(n)。
 */
void solution(Node* head){
    if(head->next==head||head->next->next==head)return;  // 空链表或者链表只有1个元素

    Node* newhead=new Node;  // 生成一个新的头节点
    newhead->data=-1;
    newhead->next=newhead;
    newhead->prior= newhead;

    int l=0;
    NodePtr temp=head->next;
    while(temp!=head){
        temp=temp->next;
        l++;
    }

    NodePtr p=head->next;  // p指向原链表第1个元素
    while(p!=head){
        NodePtr t=p->next;
        p->next=t->next;
        t->next->prior=p;

        t->next=newhead->next;
        newhead->next->prior=t;
        newhead->next=t;
        t->prior=newhead;

        if(l%2==1){  // 链表长度为奇数
            p=p->next;
            if(p->next==head)break;
        }
        else{  // 链表长度为偶数
            if(p->next==head)break;
            p=p->next;
        }
    }
    p->next=newhead->next;
    p=newhead->next->prior;
    head->prior=newhead->prior;
    newhead->prior->next=head;
    delete newhead;
}


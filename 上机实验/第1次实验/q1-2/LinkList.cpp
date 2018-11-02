/*
 * Filename: LinkList.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-18
 */
#include "LinkList.h"

/*
 * 将链表重置为空表，并释放原链表的节点空间
 * 说明：定义2个指针，分别指向第i个结点与第i+1个结点，令第i+1个结点的后继元素等于第i个结点的后继元素，再删除第i+1个结点。时间复杂度为O(n)。
 * 注意！不可直接将令head->next=nullptr，因为结点元素仍然遗留在内存中，容易出现错误。
 */
void LinkList::ClearList() {
    NodePtr p, q;
    p = head;

    if(p->next== nullptr){
        return;
    }

    int l = length;
    while(l-->0){
        q=p->next;
        p->next = q->next;
        delete q;
    }
    head->next= nullptr;
    length = 0;
}

/*
 * 判断链表是否为空
 */
bool LinkList::ListEmpty() {
    if (head->next== nullptr){
        return true;
    }
    else{
        return false;
    }
}

/*
 * 返回链表元素个数
 */
int LinkList::ListLength() {
    return length;
}

/*
 * 返回链表上位置i结点元素的值
 * 说明：遍历链表，直到位置i。时间复杂度为O(1)。
 * 举例：链表中5个元素分别为1, 3, 2, 6, 7，则当i=4，e=6。
 */
Status LinkList::GetElem(int i, ElemType &e) {
    NodePtr p = head;
    int j = 0; // 当前结点序号，初始化为0

    if(head->next == nullptr){  // 空链表返回错误
        return ERROR;
    }
    if(i>length){  // 位序超过链表长度返回错误
        return ERROR;
    }

    while(p && j<i){
        p = p->next;
        ++j;
    };

    e=p->data;
    return OK;
}

/*
 * 返回链表中第一个值为e的元素的位置
 * 说明：遍历链表，直到出现第1个元素与e相等的结点，然后返回位序。时间复杂度为O(1)。
 * 举例：链表中5个元素分别为1, 3, 2, 6, 7，则3在链表中的位序为2，7的位序为6
 */
Status LinkList::LocateElem(ElemType e, int &n) {
    NodePtr p = head;
    int j=0;

    if(p == nullptr){
        exit(ERROR);
    }
    while(p && p->data != e){
        p = p->next;
        ++j;
    }
    if(j == length && p->data != e){  // 所要查找的元素不在链表中，返回错误
        return ERROR;
    }
    else{
        n = j;
    }
    return OK;
}

/*
 * 返回第一个元素为e的结点的后一个结点的元素
 * 说明：遍历链表，直到出现第1个元素与cur_e相等的结点，返回该结点的后继结点。时间复杂度为O(1)。
 */
Status LinkList::NextElem(ElemType cur_e, ElemType &e) {
    NodePtr p = head;

    while(p && p->data != cur_e){
        p = p->next;
    }
    if(!p || !p->next){
        return ERROR;
    }

    e = p->next->data;
    return OK;
}

/*
 * 返回第一个元素为e的结点的前一个结点的元素
 * 说明：遍历链表，直到出现第1个元素与cur_e相等的结点，返回该结点的前驱结点。时间复杂度为O(1)。
 */
Status LinkList::PriorElem(ElemType cur_e, ElemType &e) {
    NodePtr p = head;
    NodePtr s = nullptr;

    while(p && p->data != cur_e){
        s = p;
        p = p->next;
    }
    if(!p || !s){
        return ERROR;
    }

    e = s->data;
    return OK;
}

/*
 * 在位置i插入新的节点（前插）
 * 举例：原链表为[1,2,3,4,5]，现插入元素2在位置3，则链表变为[1,2,2,3,4,5]
 * 说明：首先遍历链表，直到位置i-1，然后再定义新的结点并申请空间存储元素e，使第i-1个结点的next指针指向s，s的next指针指向原来的i。时间复杂为O(n)。
 */
Status LinkList::ListInsert(ElemType e, int i) {
    int j=0;
    NodePtr p = head;
    NodePtr s;

    while(p && j<i-1){
        ++j;
        p=p->next;
    }

    if(!p||j>i){
        return ERROR;
    }

    s=new Node;
    s->data = e;

    if(i==1){
        s->next=head->next;
        head->next=s;
    }
    else{
        s->next=p->next;
        p->next=s;
    }
    length += 1;
    return OK;
}

/*
 * 有序链表插入元素e，插入元素后链表认为有序链表
 * 注意！如果是无序链表则不可以使用这个函数！
 */
Status LinkList::SortListInsert(ElemType e) {
    NodePtr p=head;
    NodePtr q,s;

    if(p->next == nullptr){
        return ERROR;
    }

    p=p->next;
    while(p && e>p->data){
        q=p;
        p=p->next;
    }

    s = new Node;
    s->data = e;

    s->next=q->next;
    q->next=s;

    length += 1;
    return OK;

}

/*
 * 删除链表中元素值为e的第一个结点
 * 说明：首先定义2根指针，遍历链表，直到指针p的元素等于e，此时r是p的前驱结点。然后使r的next指针指向p的next指针，再删除p。时间复杂度为O(n)。
 */
Status LinkList::ListDelete(ElemType e) {
    NodePtr r = nullptr;
    NodePtr p = head->next;

    while(p && p->data != e){
        r = p;
        p = p->next;
    }
    if(p== nullptr){
        return ERROR;
    }
    if(r == nullptr){
        head = head->next;
    }
    else{
        r->next = p->next;
    }
    delete p;
    length -= 1;
    return OK;
}

/*
 * 遍历链表并打印
 * 说明：时间复杂度为O(1)。
 */
void LinkList::ListTraverse() {
    NodePtr p = head;
    if(p->next == nullptr){
        return;
    }

    int l = length;
    while(l-->0){
        p = p->next;
        std::cout << p->data << "\t";
    }
}

/*
 * 对链表进行就地逆置
 * 说明：将原链表中的头结点和第1个元素断开。然后从第1个结点起，依次将原链表的各结点插入新表的头部（即令每个插入的结点成为新的第一个元素结点）
 * 时间复杂度是O(n)，空间复杂度是O(1)。
 */
void LinkList::Adverse() {
    if(head->next == nullptr){
        return;
    }
    ElemType e;
    NodePtr p;
    LinkList* newL = new LinkList;
    int l=0;
    for(;l<length;l++){
        GetElem(l+1, e);
        newL->ListInsert(e, 1);
    }
    head=newL->head;
}

/*
 * 无序链表去重
 */
void LinkList::DeleteDuplicates() {
    NodePtr p,q,r;
    p=head->next;
    if(!p){
        return;
    }
    while(p){
        r=p;
        q=p->next;
        while(q){
            if(p->data != q->data){
                r=q;
                q=q->next;
            }
            else{
                r->next=q->next;
                delete q;
                q=r->next;
                length -= 1;
            }
        }
        p=p->next;
    }
}

/*
 * 在有序链表中删除所有值大于mink且小于maxk的元素
 * 说明：遍历链表中的元素，判断其与mink和maxk的关系，如果符合要求则删除该结点。时间复杂度为O(n)。
 */
void LinkList::RangeDelete(ElemType mink, ElemType maxk) {
    if(mink>=maxk){
        return;
    }
    NodePtr p=head;
    NodePtr q;

    while(p->next!= nullptr){
        q=p->next;
        if(q->data > mink && q->data<maxk){
            p->next=q->next;
            length--;
            delete q;
            continue;
        };
        p=p->next;
    }
}



















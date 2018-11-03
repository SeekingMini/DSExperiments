/*
 * Filename: main.c
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-29
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;
typedef struct {
    ElemType *elem;  // 数据元素基址
    int length;  // 顺序表当前元素个数
    int listsize;  // 顺序表表长
}SeqList;

void delElem(SeqList*,ElemType);
void intersection(SeqList*,SeqList*);

/*
 * 注意！题目中写明的集合，所以顺序表中不应该出现重复的元素！
 */
int main() {
    SeqList A;
    SeqList B;

    A.elem = (ElemType*)malloc(MAXSIZE* sizeof(ElemType));
    B.elem = (ElemType*)malloc(MAXSIZE* sizeof(ElemType));

    scanf("%d", &A.length);
    for(int i=0;i<A.length;i++){
        scanf("%d", &A.elem[i]);
    }
    scanf("%d", &B.length);
    for(int i=0;i<B.length;i++){
        scanf("%d", &B.elem[i]);
    }

    intersection(&A,&B);

    for(int i=0;i<A.length;i++){
        printf("%d\t", A.elem[i]);
    }
    return 0;
}

/*
 * 删除数组中出现的第1个值为e的元素。时间复杂度为O(n^2)。
 */
void delElem(SeqList* L, ElemType e){
    int count=0;
    for(int i=0;i<L->length;i++){
        if(count==1)break;
        if(L->elem[i]==e){
            for(int j=i;j<L->length-1;j++){
                L->elem[j]=L->elem[j+1];
                count++;
            }
            L->length--;
        }
    }
}

/*
 * 首先对A中所有元素进行遍历，如果这个元素在B中没有，就删除这个元素，最终得到的C就是A与B的交集。时间复杂度为O(n^2)。
 */
void intersection(SeqList* A, SeqList* B){
    int flag=0;
    for(int i=0;i<A->length;i++){
        ElemType e=A->elem[i];
        for(int j=0;j<B->length;j++){
            if(e==B->elem[j]){
                flag=1;
                break;
            }
        }
        if(!flag){
            delElem(A, e);
            i--;
        }
        flag=0;
    }
}
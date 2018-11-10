/*
 * Filename: main.c
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-28
 */
#include <stdio.h>
#include "Stack.h"

/*
 * 动态顺序栈测试
 */
int main() {
    SqStack S;
    ElemType e;

    printf("Initialize a SqStack\n");
    InitStack(&S);

    printf("Push 1,2,...,10 to SqStack\n");
    for(int i=0;i<10;i++){
        Push(&S, i+1);
    }

    if(StackEmpty(S)){
        printf("SqStack is Empty\n");
    }
    else{
        printf("SqStack is not Empty\n");
    }

    printf("SqStack is as followed:\n");
    StackTraverse(S);
    printf("\n");

    printf("Pop the top element\n");
    Pop(&S, &e);

    GetTop(S, &e);
    printf("The top element of SqStack is %d\n", e);

    printf("Push 14 to SqStack\n");
    Push(&S, 14);

    printf("Push 999 to SqStack\n");
    Push(&S, 999);

    printf("The Length of SqStack is %d\n", StackLength(S));

    printf("SqStack is as followed:\n");
    StackTraverse(S);
    printf("\n");

    ClearStack(&S);
    DestroyStack(&S);

    return 0;
}
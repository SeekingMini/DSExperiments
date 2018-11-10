/*
 * Filename: Stack.h
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-28
 */
#ifndef Q1_STACK_H
#define Q1_STACK_H

#include <stdlib.h>
#include <stdio.h>

#define OK 1
#define ERROR 0
#define OVERFLOW 0

#define STACK_MAX_SIZE 100  // 存储空间分配初始量
#define INCREMENT 10  // 存储空间分配增量
typedef int ElemType;
typedef int Status;
typedef struct{
    ElemType* base;  // 指向栈底的指针
    ElemType* top;  // 指向栈顶的指针
    int stacksize;
}SqStack;

/*
 * 初始化构造一个空栈
 */
Status InitStack(SqStack *S){
    S->base =(ElemType*)malloc(STACK_MAX_SIZE* sizeof(ElemType));
    if(!S->base){
        exit(ERROR);
    }
    S->top=S->base;
    S->stacksize=STACK_MAX_SIZE;
    return OK;
}

/*
 * 销毁一个栈
 */
Status DestroyStack(SqStack* S){
    if(S->top==S->base){  // 空栈
        free(S->base);
        return OK;
    }
    else{
        while(S->top!=S->base){
            ElemType* p=S->top;
            S->top--;
            free(p);
        }
        free(S->top);
        return OK;
    }

}

/*
 * 清空栈中元素
 */
Status ClearStack(SqStack* S){
    if(S->base==S->top){  // 空栈
        return ERROR;
    }
    else{
        S->top=S->base;
        return OK;
    }
}

/*
 * 判断栈是否为空
 */
Status StackEmpty(SqStack S){
    return S.base == S.top;
}

/*
 * 求栈中元素的个数
 */
int StackLength(SqStack S){
    if(S.base==S.top){
        return 0;
    }

    int *p;
    int length=0;
    for(p=S.base;p!=S.top;p++){
        length++;
    }
    return length;
}

/*
 * 返回栈的栈顶元素
 */
Status GetTop(SqStack S, ElemType *e){
    if(S.base==S.top){  // 空栈
        return ERROR;
    }
    *e=*(S.top-1);
    return OK;
}

/*
 * 往栈顶插入新的元素
 */
Status Push(SqStack* S, ElemType e){
    if(S->top-S->base>=S->stacksize){  // 栈满
        S->base=(ElemType*)realloc(S->base, (S->stacksize+INCREMENT)* sizeof(ElemType));  // 重新分配新的空间
        if(!S->base){
            exit(OVERFLOW);
        }
        S->top=S->base+S->stacksize;
        S->stacksize+=INCREMENT;
    }
    *S->top=e;
    S->top++;
    return OK;
}

/*
 * 弹出栈顶元素
 */
Status Pop(SqStack* S, ElemType* e){
    if(S->top==S->base){
        return ERROR;
    }
    *e=*(S->top-1);
    S->top--;
    return OK;
}

/*
 * 遍历栈并打印元素
 */
Status StackTraverse(SqStack S){
    if(S.base==S.top){
        return ERROR;
    }
    ElemType* p = S.base;
    while(p!=S.top){
        printf("%d\t", *p);
        p++;
    };
    return OK;
}


#endif //Q1_STACK_H

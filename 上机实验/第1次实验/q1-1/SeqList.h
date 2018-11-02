/*
 * Filename: SeqList.h
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-16
 */
#include<stdlib.h>
#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;
typedef struct {
	ElemType *elem;  // 数据元素基址
	int length;  // 顺序表当前元素个数
	int listsize;  // 顺序表表长
}SeqList;

/*
 * 初始化构造一个空顺序表
 */
Status InitList(SeqList *L) {
	L->elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if (!L->elem) exit(OVERFLOW);
	L->length = 0; 
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

/*
 * 销毁一个顺序表
 */
Status DestroyList(SeqList *L) {
	if (L->elem) {
		free(L->elem);
		L = NULL;
		return OK;
	};
	return ERROR;
}

/*
 * 重置为空表
 */
Status ClearList(SeqList *L) {
	if (!L->elem) {
		return ERROR;
	} 
	L->length = 0;
	return OK;
}

/*
 * 返回当前顺序表是否为空
 */
Status ListEmpty(SeqList *L) {
	if (L->length == 0) {
		return TRUE;
	}
	else {
		return FALSE; 
	}
}

/*
 * 返回当前顺序表元素个数
 */
Status ListLength(SeqList *L) {
	return L->length;
}

/*
 * 根据位序返回元素
 * 思考：为什么要将返回结果作为参数传递进去而不是直接利用函数返回值传递？
 * 答：为了使函数更具有通用性，适应性更高。因为执行函数的结果有可能是正常返回指定的元素值，有可能查询失败而返回失败信息，此时如果用返回值类型做为函数返回值那么可能需要借助一些特殊值来区分失败的情况
 */
Status GetElem(SeqList *L, int i, ElemType * e) {
	if (i < 1 || i > L->length) {
		return ERROR;
	}
	else {
		*e = L->elem[i - 1];
		return OK;
	}
}

/*
 * 查找某个元素是否存在，并返回该元素的位序
 */
Status LocateElem(SeqList* L, ElemType e) {
	if (!L->elem) {
		return ERROR;
	}
	for (int i = 0; i < L->length; i++) {
		if (e == L->elem[i]) {
			return i;
		};
	};
	return ERROR;
}

/*
 * 返回前驱元素
 */
Status PriorElem(SeqList* L, int i) {
	if (i < 1 || i > L->length) {
		return ERROR;
	};
	if (i != 1) {
		return L->elem[i - 2];
	}
	else {
		return INFEASIBLE;
	}
}

/*
 * 返回后继元素
 */
Status NextElem(SeqList* L, int i) {
	if (i < 1 || i > L->length) {
		return ERROR;
	}
	if (i != 1) {
		return L->elem[i];
	}
	else {
		return INFEASIBLE;
	}
}

/*
 * 插入元素到指定位置
 */
Status ListInsert(SeqList* L, int pos, ElemType e) {
	ElemType * newbase;
	int i = 0;
	
	if (pos < 1 || pos > L->length+1) {
		return ERROR;
	}
	if (pos > L->listsize) {
		newbase = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);
		L->elem = newbase;
		L->listsize += LISTINCREMENT;
	};

	for (i = L->length - 1; i >= pos - 1; i--) {
		L->elem[i+1] = L->elem[i];
	};

	L->elem[pos-1] = e;
	L->length++;
	return OK;
}

/*
 * 删除指定位置元素，并用e返回
 */
Status ListDelete(SeqList* L, int i, ElemType *e) {
	if (i < 1 || i > L->length) {
		return ERROR;
	};
	*e = L->elem[i - 1];
	for (int j = i - 1; j < L->length; j++) {
		L->elem[j] = L->elem[j + 1];
	};
	L->length--;
	return OK;
}

/*
 * 遍历顺序表并打印所有元素
 */
void ListTraverse(SeqList *L){
	int i=0;
	for (;i<L->length;i++){
		printf("%d\t", L->elem[i]);
	};
}

/*
 * 实现顺序表的就地逆置
 */
void Adverse(SeqList *L){
    int l = ListLength(L);

    if(!l){
        exit(ERROR);
    }

    if(l % 2 == 0){
        for(int i=0;i<l/2;i++){
            int temp;
            temp = L->elem[i];
            L->elem[i] = L->elem[l-1-i];
            L->elem[l-1-i] = temp;
        }
    }
    else{
        for(int i=0;i<(l-1)/2;i++){
            int temp;
            temp = L->elem[i];
            L->elem[i] = L->elem[l-1-i];
            L->elem[l-1-i] = temp;
        }
    }
}




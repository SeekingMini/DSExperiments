/*
 * Filename: main.c
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-16
 */
#include "SeqList.h"
#include<stdio.h>

/*
 * 顺序表测试
 */
int main() {
	ElemType e;
	SeqList L;
	InitList(&L);  // 初始化一个空顺序表
	printf("Initialize a SeqList");
    printf("Insert 1,4,9...400 to SeqList:\n");
    for (int j = 1; j < 21; j++) {
        ListInsert(&L, j, j*j);  // 在顺序表中插入 1, 4, 9, ..., 400 一共20个元素
    }
    ListTraverse(&L);
    printf("\n");

	printf("The length of SeqList is %d\nThe size of SeqList is %d\n", ListLength(&L), L.listsize);

	if (ListEmpty(&L)) {  // 判断是否为空
		printf("SeqList is Empty\n");
	}
	else {
		printf("SeqList is not Empty\n");
	};

    printf("The Prior element of the third element is %d\n", PriorElem(&L, 3));
    printf("The Next element of the tenth element is %d\n", NextElem(&L, 10));

    GetElem(&L, 10, &e);
    printf("The tenth element of SeqList is %d\n", e);

    if(LocateElem(&L, 256)){
        int i = LocateElem(&L, 256);
        printf("The element 256 is at position %d of SeqList\n", i+1);
    }
    else{
        printf("Not exist\n");
    }

    ListDelete(&L, 3, &e);
    printf("Delete the third element of SeqList\n");
    ListInsert(&L, 4, 11);
    printf("Insert 11 to the fourth position of SeqList\n");

    printf("SeqList is as followed:\n");
    ListTraverse(&L);
	printf("\n");

	printf("Overturn SeqList\n");
	Adverse(&L);
    printf("SeqList is as followed:\n");
    ListTraverse(&L);
    printf("\n");

	ClearList(&L);
	DestroyList(&L);

	return 1;
};
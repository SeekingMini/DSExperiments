/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-29
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 1000  // 数组最大元素个数
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
typedef struct{
    ElemType* arr;
    int length;
}SqList;

ElemType InsertSort(ElemType*, int);

int main() {
    SqList L;
    L.arr=(ElemType*)malloc(MAXLENGTH* sizeof(ElemType));  // 动态申请空间

    scanf("%d", &L.length);
    for(int n=0;n<L.length;n++){
        scanf("%d", &L.arr[n]);
    }

    InsertSort(L.arr, L.length);

    for(int k=0;k<L.length;k++){
        printf("%d\t", L.arr[k]);
    }
    return 0;
}

/*
 * 基于顺序表的插入排序法
 * 算法思想：把整个数组分为两部分，左边为已经排好序的部分，右边为未排序的部分。遍历右边的部分，分别与左边部分的每一元素进行比较，在符合要求的地方
 * 插入这个元素。时间复杂度为O(n^2)。
 */
Status InsertSort(ElemType* arr, int length){
    if(length==0){
        exit(ERROR);
    }

    for(int i=1;i<length;i++){
        ElemType key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1]=key;
    };
    return OK;
}
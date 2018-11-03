/*
 * Filename: main.c
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-30
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 1000
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
typedef struct{
    ElemType* arr;
    int length;
}SqList;

ElemType InsertSort(ElemType*, int);

/*
 * 算法思想
 * 1.对数组进行排序，采用插入排序法，时间复杂度为O(n^2)
 * 2.找出中间那个数，然后将中间那个数的左右与其相等的数去掉，看左右剩下的数个数是否相等，如果相等则中间那个数就是答案，否则输出-1
 */
int main() {
    SqList L;
    L.arr=(ElemType*)malloc(MAXLENGTH* sizeof(ElemType));
    scanf("%d", &L.length);
    for(int n=0;n<L.length;n++){
        scanf("%d", &L.arr[n]);
    }
    InsertSort(L.arr, L.length);  // 首先进行排序

    int mid=L.length/2;
    int leftcount=mid;
    int rightcount=L.length-mid-1;

    for(int i=mid-1;i>=0;i--){
        if(L.arr[mid]==L.arr[i])leftcount--;
    }
    for(int i=mid+1;i<L.length;i++){
        if(L.arr[mid]==L.arr[i])rightcount--;
    }

    if(leftcount==rightcount){
        printf("%d", L.arr[mid]);
    }
    else{
        printf("-1");
    }
    return 0;
}

/*
 * 基于顺序表的插入排序法，时间复杂度为O(n^2)
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
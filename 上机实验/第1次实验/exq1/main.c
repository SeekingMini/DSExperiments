/*
 * Filename: main.c
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-27
 */
#include <stdlib.h>
#include <stdio.h>
#include<math.h>

#define OK 1
#define ERROR 0
#define ARRSIZE 100  // 数组中最多存储100个元素
#define MAXINT 10000  // 假设计算机允许的最大值为10000

double getFactorial(int);  // 求!n的函数

int main() {
    double *arr = (double*)malloc(ARRSIZE* sizeof(double));
    double res;
    int n;
    scanf("%d", &n);
    if(n>100){
        exit(ERROR);
    }
    for(int i=0;i<n;i++){
        res = getFactorial(i) * pow(2, i);
        if(res>MAXINT){
            exit(ERROR);
        }
        arr[i]=res;
    }
    return OK;
}
double getFactorial(int n){
    if(n==0){
        return 1;
    }
    else{
        double res=1;
        for(int i=1;i<=n;i++){
            res *=i;
        };
        return res;
    }
}
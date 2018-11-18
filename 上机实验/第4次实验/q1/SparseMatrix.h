/*
 * Filename: SparseMatrix.h
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-11-05
 */

#ifndef Q1_SPARSEMATRIX_H
#define Q1_SPARSEMATRIX_H

#include <iostream>

#define MAXSIZE 10000 // 100*100的矩阵
typedef int ElemType;
struct Triple{
    ElemType e;  // 元素值
    int i;  // 元素的行下标
    int j;  // 元素的列下标
};

/*
 * 稀疏矩阵的部分定义
 */
class SparseMatrix {
public:
    Triple* data;
    int rown;  // 矩阵的行数
    int coln;  // 矩阵的列数
    int tu;  // 矩阵的非零元数

    SparseMatrix(int r,int c){
        data=new Triple[MAXSIZE+1];
        rown=r;
        coln=c;
        tu=0;
    };
    void printMatrix();
    void printT();
};


#endif //Q1_SPARSEMATRIX_H

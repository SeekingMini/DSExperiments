/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.2
 * Time: 2018-11-05
 */

#include <iostream>
#include "SparseMatrix.h"
using namespace std;

void Transpose_Solution1(SparseMatrix,SparseMatrix*);
void Transpose_Solution2(SparseMatrix,SparseMatrix*);

/*
 * 两种方法转置矩阵
 */
int main() {
    int rown,coln,tu;  // 行数、列数、非零元素个数
    cin>>rown>>coln>>tu;
    SparseMatrix M(rown,coln);
    SparseMatrix T1(coln,rown);  // T1是M的转置矩阵
    SparseMatrix T2(coln,rown);  // T2是M的转置矩阵

    // 输入非零元素的行坐标、列坐标以及值
    for(int k=1;k<=tu;k++){
        cin>>M.data[k].i>>M.data[k].j>>M.data[k].e;
        M.tu++;
    }
    cout<<"M:"<<endl;  // 打印原矩阵
    M.printMatrix();

    Transpose_Solution1(M,&T1);  // 第1种方法
    cout<<"T1:"<<endl;
    T1.printMatrix();

    Transpose_Solution2(M,&T2);
    cout<<"T2:"<<endl;
    T2.printMatrix();
    return 0;
}

/*
 * 普通转置法
 * 算法思想：把原矩阵的列数作为外循环，非零元素的个数作为内循环。
 */
void Transpose_Solution1(SparseMatrix M,SparseMatrix* T){
    int q=1;
    for(int c=1;c<=M.coln;c++){
        for(int t=1;t<=M.tu;t++){
            if(M.data[t].j==c){
                T->data[q].i=M.data[t].j;T->data[q].j=M.data[t].i;
                T->data[q].e=M.data[t].e;++q;
            }
        }
    }
}

/*
 * 快速转置法
 * 算法思想：使用三元组存储非零元组有一个缺陷，在输入每一个元素时必须严格按照行坐标和列坐标的大小次序，如果用最朴素的方法转置，新的矩阵三元组次序又会被打乱，
 * 快速转置法正是考虑到这个。转置一个矩阵，第1列的非零元素会变成转置矩阵的第1行非零元素，第2列的非零元素会变成转置矩阵的第2列非零元素，以此类推。
 * 于是，假设有这样一个数组，存储原矩阵每一列非零元素的个数，命名为num[]。比如说，转置后的矩阵第1行有2个元素（即原矩阵第1列有2个元素），
 * 则num[col]=2(col=1)。又假设有这样一个数组，储存原矩阵每个非零元素的恰当位置，命名为cpot[]。比如说原矩阵第1列有2个元素，第2列有3个元素，则
 * num[1]=2，num[2]=3，cpot[1]=1，cpot[2]=num[1]+cpot[1]=3，第1列中第1个非元素零排在了位置1，第2列中第1个非零元素排在了位置3，第2列中
 * 第2个非零元素排在了位置4，以此类推。这么做的好处就是在转置矩阵时，只要遍历原矩阵的非零元素即可，大大减少时间复杂度。
 * 本算法中有四个相互独立的循环，时间复杂度接近O(n)。
 */
void Transpose_Solution2(SparseMatrix M,SparseMatrix *T){
    int p,q,col;
    int num[M.tu+1],cpot[M.tu+1];
    for(col=1;col<=M.coln;col++) num[col]=0;
    for(int t=1;t<=M.tu;t++) ++num[M.data[t].j];
    cpot[1]=1;
    for(col=2;col<=M.coln;col++) cpot[col]=cpot[col-1]+num[col-1];
    for(p=1;p<=M.tu;p++){
        col=M.data[p].j; q=cpot[col];
        T->data[q].i=M.data[p].j;
        T->data[q].j=M.data[p].i;
        T->data[q].e=M.data[p].e;
        cpot[col]++;
        T->tu++;
    }
}

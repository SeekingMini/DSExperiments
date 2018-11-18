/*
 * Filename: SparseMatrix.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-11-05
 */

#include "SparseMatrix.h"

/*
 * 打印矩阵元素
 */
void SparseMatrix::printMatrix(){
    int p=1;
    for(int i=1;i<=rown;i++){
        for(int j=1;j<=coln;j++){
            if(data[p].i==i&&data[p].j==j){
                std::cout<<data[p].e<<"\t";
                ++p;
            }
            else{
                std::cout<<"0\t";
            }
            if(j==coln)std::cout<<"\n";
        }
    }
}

void SparseMatrix::printT() {
    for(int n=1;n<=tu;n++){
        std::cout<<data[n].i<<" "<<data[n].j<<" "<<data[n].e<<std::endl;
    }
}
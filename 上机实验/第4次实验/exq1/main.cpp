/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-11-17
 */
#include <iostream>
using namespace std;
#define M 5  // 10行
#define N 5  // 10列

void changeColor(char C[M+1][N+1],int,int,char);

/*
 * 图像染色问题
 */
int main() {
    char C[M+1][N+1];  // 为了简化题意，本次默认采用10*10的二维数组
    int i0,j0;
    char e;

    //输入每一个点的颜色
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            cin>>e;
            C[i][j]=e;
        }
    }
    // 打印原数组
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            cout<<C[i][j]<<"\t";
        }
        cout<<endl;
    }

    cin>>i0>>j0>>e;
    changeColor(C,2,2,e);
    // 打印染色后的数组
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            cout<<C[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}

/*
 * 算法思想：采用递归的算法。注意递归的结束调节即可。
 */
void changeColor(char C[M+1][N+1],int i0,int j0,char c){
    char temp;
    if(i0<1||i0>M||j0<1||j0>N)return;  // 下标不合法
    temp=C[i0][j0];
    if(temp==c)return;
    C[i0][j0]=c;
    if(i0-1>=1&&C[i0-1][j0]==temp){
        changeColor(C,i0-1,j0,c);
    }
    if(i0+1<=M&&C[i0+1][j0]==temp){
        changeColor(C,i0+1,j0,c);
    }
    if(j0-1<=N&&C[i0][j0-1]==temp){
        changeColor(C,i0,j0-1,c);
    }
    if(j0+1<=M&&C[i0][j0+1]==temp){
        changeColor(C,i0,j0+1,c);
    }
}
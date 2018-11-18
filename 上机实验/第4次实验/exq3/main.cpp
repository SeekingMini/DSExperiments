/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.1
 * Time: 2018-11-13
 */
#include <iostream>
#include "CirQueue.h"
using namespace std;

int fibonacci(int,int);

/*
 * k阶斐波那契数列：数列第1项到第k-1项为0，第k项为1，之后从第(k+1)项开始每一项为前k项之和
 * 说明：所定义的数据结构不是标准的循环队列，其中有很多不规范的地方！
 * 举例：4阶斐波那契数列前11项(f0,f1,f2,...,f10)为[0,0,0,1,1,2,4,8,15,29,56]
 */
int main() {
    int k;  // 斐波那契数列的阶数
    int n;  // 斐波那契数列的前n项(n>=1)

    cin>>k>>n;
    CirQueue Q(k);  // 最多存储k个元素的循环队列
    for(int i=0;i<=n-1;i++){
        Q.push(fibonacci(i,k));
    }

    Q.print();

    return 0;
}

/*
 * 求斐波那契数列第n个数的值
 * 注意：这里的n是从0开始计数的，即n=0,1,2,3,...
 */
int fibonacci(int n,int k){
    if(n<=k-2)return 0;
    if(n>k-2&&n<=k)return 1;
    else return 2*fibonacci(n-1,k)-fibonacci(n-k-1,k);
}
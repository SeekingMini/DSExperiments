/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-10-28
 */
#include <iostream>
using namespace std;

void solution1(int);
/*
 * 问题􏰀描述:先输入一个十进制整数 n，再输入 n 个正整数，求它们相邻数之差可 知是否为上升或下降，由上升转下降或由下降转上升为折点，求折点数。
 * 问题分析:如果一个点的值比左右两个都大或都小，则为折点。
 * 样例输入:
 * 5
 * 1 3 5 2 1
 * 样例输出
 * 1
 * 样例输入:
 * 6
 * 3 5 1 7 8 4
 * 样例输出
 * 3
 */
int main() {
    int n;

    cin>>n;
    solution1(n);
    return 0;
}

/*
 * 第一种解法（非常容易想到且容易实现的算法）
 * 思路：根据定义，如果一个点的值比左右两个都大或都小，则为折点。容易得出数组中第一个数和最后一个数都不可能是折点，所以从数组第二个数开始遍历，
 * 直到倒数第二个数，然后每次遍历都让当前元素与前一个和后一个元素进行比较进行判断。时间复杂度为O(n)。
 */
void solution1(int n){
    int res=0;
    int num;
    int i;
    int *array = new int[n];

    for(i=0;i<n;i++){
        cin>>num;
        array[i]=num;
    };

    for(i=1;i<n-1;i++){
        if((array[i]<array[i-1]&&array[i]<array[i+1])||(array[i]>array[i-1]&&array[i]>array[i+1])){
            res++;
        };
    }
    cout<<res<<endl;
}
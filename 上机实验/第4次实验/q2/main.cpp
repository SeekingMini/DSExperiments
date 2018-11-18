/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.1
 * Time: 2018-11-06
 */
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXSIZE 10000

/*
 * 算法思想：由于题目中提到相同的数据只被统计一次，所以只要先对输入的数组进行排序，然后进行判断即可。由于排序是采用标准库的函数，整个算法的时间复杂度
 * 接近O(n)。
 */
int main() {
    int length;
    int e;
    int* arr =new int[MAXSIZE];

    cin>>length;
    for(int i=1;i<=length;i++){
        cin>>e;
        arr[i-1]=e;
    }
    sort(arr,arr+length);  // 首先对数组排序

    int count=0;
    for(int n=1;n<length;n++){
        if(arr[n]-arr[n-1]==1)count++;  // 如果后一个比前一个大1，则计数器加1
    }
    cout<<count;
    return 0;
}
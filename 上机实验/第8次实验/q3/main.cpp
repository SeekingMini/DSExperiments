/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-12-18
 */

#include <cstdio>
using namespace std;

/*
 * 算法思想：采用”分而治之“的方法，将数组分为两段，再进行递归，重复分段
 */
void QuickSort(int *, int, int);
void QuickSort(int *arr, int low, int high)
{
    if (low >= high)
        return;
    int first = low;
    int last = high;
    int key = arr[first]; // 把字表的第一个元素作为“枢轴”

    while (first < last)
    {
        while (first < last && arr[last] >= key)
            --last;
        arr[first] = arr[last];
        while (first < last & arr[first] <= key)
            ++first;
        arr[last] = arr[first];
    }
    arr[first] = key;
    QuickSort(arr, low, first - 1);
    QuickSort(arr, first + 1, high - 1);
}

int main()
{
    int l;

    // 输入数据
    scanf("%d", &l);
    int *arr = new int[l];
    for (int i = 0; i < l; i++)
    {
        scanf("%d", &arr[i]);
    }

    QuickSort(arr, 0, l - 1);
    for (int i = 0; i < l; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-12-24
 */

#include <cstdio>
using namespace std;

#define MAX 100

void swap(int &, int &);
void HeadAdjust(int[], int, int);
void HeapSort(int[], int);

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void HeapAdjust(int arr[MAX + 1], int start, int end)
{
    int dad = start;
    int son = dad * 2;
    while (son <= end)
    {
        if (son + 1 <= end && arr[son + 1] > arr[son])
        {
            son++;
        }
        if (arr[dad] > arr[son])
            return;
        else
        {
            swap(arr[son], arr[dad]);
            dad = son;
            son = dad * 2;
        }
    }
}

void HeapSort(int arr[MAX + 1], int length)
{
    for (int i = length / 2; i >= 1; i--)
    {
        HeapAdjust(arr, i, length);
    }
    for (int i = length; i > 1; i--)
    {
        swap(arr[1], arr[i]);
        HeapAdjust(arr, 1, i - 1);
    }
}

int main()
{
    int arr[MAX + 1];
    FILE *fp;
    int l;
    int n;

    fp = fopen("./test.txt", "r");
    fscanf(fp, "%d ", &l);
    for (int i = 1; i <= l; i++)
    {
        fscanf(fp, "%d", &n);
        arr[i] = n;
    }

    // 打印数组
    HeapSort(arr, l);
    for (int i = 1; i <= l; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

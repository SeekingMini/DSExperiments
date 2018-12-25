/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-12-04
 */

#include <cstdio>
#include <iostream>
using namespace std;

void Print(int *, int);
void SwapSort(int *, int);
void SelectionSort(int *, int);
void InsertSort(int *, int);
void Merge(int *, int *, int, int, int);
void MergeSort(int *, int *, int, int);

/*
 * 打印数组
 */
void Print(int *arr, int length)
{
    for (int n = 0; n < length; n++)
    {
        cout << arr[n] << " ";
    }
    cout << endl;
}

/*
 * 选择排序法
 * 算法思想：通过n-i次关键字间的比较，从n-i+1个记录中选出关键字最小的记录，并和第i个记录进行交换
 */
void SelectionSort(int *arr, int length)
{
    int min;
    int i, j, t;
    for (i = 0; i < length - 1; i++)
    {
        t = i;
        for (int j = i + 1; j < length; j++)
        {
            if (arr[t] > arr[j])
            {
                min = arr[j];
                t = j;
            }
        }
        if (min != arr[i])
        {
            arr[t] = arr[i];
            arr[i] = min;
        }
    }
}

/*
 * 交换排序法
 * 算法思想：将第i个记录与第j个记录进行比较，如果arr[i]<arr[j]，则进行交换，则一次循环后，最小的数一定排在数组的最前面
 */
void SwapSort(int *arr, int length)
{
    int temp;
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/*
 * 插入排序法
 * 算法思想：一共有n个数，从第m(1<=m<=n)个数开始，把其与前n-m个数依次比较，插入适当的位置
 */
void InsertSort(int *arr, int l)
{
    int key;
    int j;
    for (int i = 1; i < l; i++)
    {
        key = arr[i];
        j = i - 1;
        while ((j >= 0) && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        if (j != i - 1)
            arr[j + 1] = key;
    }
}

/*
 * 归并排序
 */
void Merge(int *oriArr, int *temArr, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = start;
    while (i != mid + 1 && j != end + 1)
    {
        if (oriArr[i] > oriArr[j])
        {
            temArr[k++] = oriArr[j++];
        }
        else
        {
            temArr[k++] = oriArr[i++];
        }
    }
    while (i != mid + 1)
        temArr[k++] = oriArr[i++];
    while (j != end + 1)
        temArr[k++] = oriArr[j++];
    for (int m = start; m <= end; m++)
        oriArr[m] = temArr[m];
    return;
}
void MergeSort(int *oriArr, int *temArr, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = start + (end - start) / 2;
        MergeSort(oriArr, temArr, start, mid);
        MergeSort(oriArr, temArr, mid + 1, end);
        Merge(oriArr, temArr, start, mid, end);
    }
}

int main()
{
    int length;

    cin >> length;
    int *arr = new int[length];
    int *temp = new int[length];
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }

    MergeSort(arr, temp, 0, length - 1);
    Print(arr, length);
}
/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-11-22
 */

#include <iostream>
using namespace std;

#define ROW 30
#define COL 30

/*
 * 算法思想：遍历数组中每一个点，对满足的点进行标记然后进行相应的消除。时间复杂度为O(mn)。
 */
int main()
{
    int arr[ROW][COL];
    int flag[ROW][COL] = {0}; // 对数组中的数据进行标记
    int m, n;

    // 输入数据
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout<<endl;

    // 进行行标记
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m - 2; j++)
        {
            if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])
            {
                flag[i][j] = flag[i][j + 1] = flag[i][j + 2] = 1;
            }
        }
    }
    // 进行列标记
    for (int i = 1; i <= n - 2; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j])
            {
                flag[i][j] = flag[i + 1][j] = flag[i + 2][j] = 1;
            }
        }
    }
    // 进行消除
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (flag[i][j])
            {
                arr[i][j] = 0;
            }
        }
    }

    // 打印数组
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
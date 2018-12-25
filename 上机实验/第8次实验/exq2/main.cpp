/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-12-25
 */

#include <cstdio>
#include <vector>
using namespace std;

/*
 * 荷兰国旗问题
 */
int main()
{
    int l;
    int n;
    scanf("%d", &l);
    int *res = new int[4]; // 1: red 2: white 3: blue

    // 利用哈希表性质，记录颜色个数
    for (int i = 1; i <= l; i++)
    {
        scanf("%d", &n);
        res[n] += 1;
    }

    // 打印颜色
    for (int i = 1; i <= res[1]; i++)
    {
        printf("r ");
    }
    for (int i = 1; i <= res[2]; i++)
    {
        printf("w ");
    }
    for (int i = 1; i <= res[3]; i++)
    {
        printf("b ");
    }

    printf("\n");

    return 0;
}

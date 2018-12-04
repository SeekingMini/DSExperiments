/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-11-29
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 * 算法思想：使用两个数组，分别记录每个时刻小球的位置和每个时刻小球运动的方向，再进行每一秒的遍历，对运动的方向以及运动的位置进行记录和改变
 */
int main()
{
    int n, L, t;
    int p;
    vector<int> pos;  // 每个时刻小球的位置
    vector<int> flag; // 判断小球运动的方向

    // 输入数据
    cin >> n >> L >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> p;
        pos.push_back(p);
        flag.push_back(1); // 1表示向右运动，-1表示向左运动
    }

    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (flag[j] == 1)
            {
                pos[j]++;
                if (pos[j] == 0 || pos[j] == L)
                { // 到达端点立刻向反方向移动
                    flag[j] = -flag[j];
                }
            }
            else
            {
                pos[j]--;
                if (pos[j] == 0 || pos[j] == L)
                { // 到达端点立刻向反方向移动
                    flag[j] = -flag[j];
                }
            }
        }
        for (int j = 0; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (pos[j] == pos[k])
                { // 两球相撞，各自立即向反方向移动
                    flag[j] = -flag[j];
                    flag[k] = -flag[k];
                }
            }
        }
    }

    // 打印结果
    for (int i = 0; i < n; i++)
    {
        cout << pos[i] << " ";
    }
    cout << endl;

    return 0;
}

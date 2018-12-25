/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-12-05
 */

#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
using namespace std;

struct Node
{
    int num;
    int count;
    // 重载操作符，保证优先队列符合该数字出现次数递减的顺序，并且如果两个整数出现的次数一样多，较小的数字排在前面
    bool operator<(const Node &n) const
    {
        if (count == n.count)
        {
            return num > n.num;
        }
        else
        {
            return count < n.count;
        }
    }
};

int main()
{
    map<int, int> M;
    priority_queue<Node> Q;

    int length;
    int n;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> n;
        M[n] += 1;
    }

    Node keyCount;
    map<int, int>::iterator itr;
    for (itr = M.begin(); itr != M.end(); itr++)
    {
        keyCount.num = itr->first;
        keyCount.count = itr->second;
        Q.push(keyCount);
    }

    // 打印结果
    while (!Q.empty())
    {
        Node res = Q.top();
        printf("%d %d\n", res.num, res.count);
        Q.pop();
    }

    return 0;
}
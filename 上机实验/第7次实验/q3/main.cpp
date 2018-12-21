/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.2
 * Time: 2018-12-07
 */

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/*
 * 并查集类
 */
class UnionFind
{
  protected:
    vector<int> ID;

  public:
    UnionFind(int n)
    {
        for (int i = 0; i < n; i++)
        {
            ID.push_back(i);
        }
    }
    int Find(int p)
    {
        while (p != ID[p])
        {
            p = ID[p];
        }
        return p;
    }
    void Union(int p, int q)
    {
        int pRoot = Find(p);
        int qRoot = Find(q);
        if (pRoot != qRoot)
        {
            ID[pRoot] = qRoot;
        }
    }
};

/*
 * 带权重的边
 */
struct Edge
{
    int u, v, cost;
    bool operator<(const Edge &n) const // 重载操作符，自定义优先队列的排列顺序
    {
        return cost > n.cost;
    }
};

int main()
{
    int n, m;
    priority_queue<Edge> q; // 优先队列
    Edge e;

    // 输入
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> e.u >> e.v >> e.cost;
        q.push(e);
    }

    // Kruskal算法
    /*
     * 优先级队列可以保证每次队首都是权重最小的边
     * 并查集可以帮助判断在新添加边的时候，该边是否会使生成树含有环
     */
    UnionFind UF(n);
    int totalCost = 0; // 总费用
    int count = 0;
    while (true)
    {
        e = q.top();
        q.pop();
        if (UF.Find(e.u) != UF.Find(e.v))
        {
            UF.Union(e.u, e.v);
            totalCost += e.cost;
            if (++count == n - 1) // 循环停止的条件是生成树的边数等于顶点数减1
                break;
        }
    }
    cout << totalCost << endl;

    return 0;
}
/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-12-21
 */

#include <cstdio>
#include <vector>
using namespace std;

#define MAX 100 // AOE网中最多有100个点
struct Edge
{
    int u, v;
    int w;
};

/*
 * 深度优先遍历，用于打印关键路径
 */
void DFS(int, int, int[][MAX + 1], int *, vector<int>);
/*
 * 寻找一条关键路径
 */
void CriticalPath(vector<Edge>, int, int *, int *);

void DFS(int start, int vn, int adjMatrix[][MAX + 1], int *visted, vector<int> criVector)
{
    printf("v%d ", start);
    visted[start] = 1;
    if (start == vn)
    {
        for (int i = 1; i <= vn; i++)
        {
            if (!visted[i])
                visted[i] = 1;
        }
        return;
    }
    for (int i = 1; i <= vn; i++)
    {
        if (adjMatrix[start][i] && !visted[i])
        {
            DFS(i, vn, adjMatrix, visted, criVector);
        }
    }
}

void CriticalPath(vector<Edge> arr, int vn, int *ve, int *vl)
{
    vector<Edge>::iterator itr;
    vector<int> criVector;
    ve[1] = 0;
    vl[1] = 0;

    for (int i = 2; i <= vn; i++)
    {
        vector<int> temp;
        for (itr = arr.begin(); itr != arr.end(); itr++)
        {
            if (itr->v == i)
            {
                temp.push_back(ve[itr->u] + itr->w);
            }
        }
        int max = *max_element(temp.begin(), temp.end());
        ve[i] = max;
    }

    vl[vn] = ve[vn];
    for (int i = vn - 1; i >= 2; i--)
    {
        vector<int> temp;
        for (itr = arr.begin(); itr != arr.end(); itr++)
        {
            if (itr->u == i)
            {
                temp.push_back(vl[itr->v] - itr->w);
            }
        }
        int min = *min_element(temp.begin(), temp.end());
        vl[i] = min;
    }

    // 把位于关键路径上的点存入数组
    // 注意：可能存在多条关键路径，所以数组中的点可能不在同一条关键路径上
    for (int i = 1; i <= vn; i++)
    {
        if (ve[i] - vl[i] == 0)
        {
            criVector.push_back(i);
        }
    }

    // 邻接矩阵便于深度优先遍历
    int adjMatrix[MAX + 1][MAX + 1];
    for (int i = 0; i < arr.size(); i++)
    {
        adjMatrix[arr[i].u][arr[i].v] = 1; // 建立有向无权图
    }

    // 把位于关键路径上的点设置为未访问
    int visited[MAX + 1];
    for (int i = 1; i <= vn; i++)
    {
        visited[i] = 1;
    }
    for (int i = 0; i < criVector.size(); i++)
    {
        visited[criVector[i]] = 0;
    }

    DFS(1, vn, adjMatrix, visited, criVector);
    printf("\n");
}

int main()
{
    FILE *fp = fopen("./test1.txt", "r");
    int ve[MAX + 1] = {0};
    int vl[MAX + 1] = {0};
    vector<Edge> arr;
    Edge e;
    int vn, en; // AOE网点、边的个数

    // 从文件读入数据
    fscanf(fp, "%d %d", &vn, &en);
    for (int i = 0; i < en; i++)
    {
        fscanf(fp, "%d %d %d", &e.u, &e.v, &e.w);
        arr.push_back(e);
    }

    // 求解一条关键路径
    printf("Critical Path\n");
    CriticalPath(arr, vn, ve, vl);

    return 0;
}
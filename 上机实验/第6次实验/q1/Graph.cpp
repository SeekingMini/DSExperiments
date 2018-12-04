/*
 * Filename: Graph.cpp
 * Author: SeekingMini
 * Version: 1.2
 * Time: 2018-11-27
 */

#include "Graph.h"

/*
 * 建立图
 * 说明：有4种图，分别用4个函数
 */
void Graph::CreateGraph()
{
    if (GraphKind == 1)
    {
        DG();
    }
    else if (GraphKind == 2)
    {
        DN();
    }
    else if (GraphKind == 3)
    {
        UDG();
        return;
    }
    else if (GraphKind == 4)
    {
        UDN();
    }
}

/*
 * 建立有向图
 * 说明：两点之间有边用1表示，没有则用0表示
 */
void Graph::DG()
{
    VertexType data;
    for (int i = 1; i <= vexNum; i++)
    {
        std::cin >> data;
        vexs[i] = data;
    }

    int i, j;
    for (int k = 1; k <= arcNum; i++)
    {
        std::cin >> i >> j;
        AdjMatrix[i][j] = 1;
    }
}

/*
 * 建立有向网
 */
void Graph::DN()
{
    VertexType data;
    for (int i = 1; i <= vexNum; i++)
    {
        std::cin >> data;
        vexs[i] = data;
    }

    int i, j, w;
    for (int k = 1; k <= arcNum; i++)
    {
        std::cin >> i >> j >> w;
        AdjMatrix[i][j] = w;
    }
}

/*
 * 建立无向图
 * 说明：两点之间有边用1表示，没有则用0表示
 */
void Graph::UDG()
{
    VertexType data;
    for (int i = 1; i <= vexNum; i++)
    {
        std::cin >> data;
        vexs[i] = data;
    }

    int i, j;
    for (int k = 1; k <= arcNum; k++)
    {
        std::cin >> i >> j;
        AdjMatrix[i][j] = 1;
        AdjMatrix[j][i] = 1;
    }
}

/*
 * 建立无向网
 */
void Graph::UDN()
{
    VertexType data;
    for (int i = 1; i <= vexNum; i++)
    {
        std::cin >> data;
        vexs[i] = data;
    }

    int i, j, w;
    for (int k = 1; k <= arcNum; i++)
    {
        std::cin >> i >> j >> w;
        AdjMatrix[i][j] = w;
        AdjMatrix[j][i] = w;
    }
}

/*
 * 销毁图
 * 说明：静态数组无法销毁，所以采用把邻接矩阵置为零矩阵的“伪销毁”
 */
void Graph::DestroyGraph()
{
    for (int i = 1; i <= vexNum; i++)
    {
        for (int j = 1; j <= vexNum; j++)
        {
            AdjMatrix[i][j] = 0;
            AdjMatrix[j][i] = 0;
        }
    }
    vexNum = 0;
    arcNum = 0;
}

/*
 * 返回顶点u在图中的位置
 */
void Graph::LocateVex(VertexType u, int &p)
{
    for (int i = 1; i <= vexNum; i++)
    {
        if (vexs[i] == u)
        {
            p = i;
            return;
        }
    }
    p = 0; // u在图中不存在
}

/*
 * 返回图中第p个顶点的值
 */
void Graph::GetVex(VertexType &v, int p)
{
    if (p >= 1 && p <= vexNum)
    {
        v = vexs[p];
        return;
    }
    else
    {
        v = '#';
        return;
    }
}

/*
 * 给图中第p个顶点赋值为v
 */
void Graph::PutVex(VertexType v, int p)
{
    if (p >= 1 && p <= vexNum)
    {
        vexs[p] = v;
        return;
    }
    else
        return;
}

/*
 * 返回图中顶点v的第一个邻接顶点
 */
void Graph::FirstAdjVex(VertexType v, VertexType &r)
{
    int p;
    LocateVex(v, p); // 找到v的位置
    if (!p)          // v不存在
    {
        r = '#';
        return;
    }
    else
    {
        for (int i = 1; i <= vexNum; i++)
        {
            if (AdjMatrix[p][i])
            {
                r = vexs[i];
                return;
            }
        }
    }
    r = '#'; // v没有邻接顶点，r为空
}

/*
 * 返回图中顶点w的第一个邻接顶点
 * 说明：w是v的第一个邻接顶点
 */
void Graph::NextAdjVex(VertexType v, VertexType &w, VertexType &r)
{
    FirstAdjVex(v, w);
    if (w != '#')
    {
        FirstAdjVex(w, r);
    }
}

/*
 * 在图中添加新顶点v
 */
void Graph::InsertVex(VertexType v)
{

    vexs[vexNum + 1] = v;
    vexNum++;
}

/*
 * 在图中删除顶点v
 */
void Graph::DeleteVex(VertexType v)
{
    int flag;
    LocateVex(v, flag);
    if (!flag) // 要删除的顶点不存在
        return;

    // 求要删除的边的条数
    int count = 0;
    for (int i = 1; i <= arcNum; i++)
    {
        if (AdjMatrix[flag][i])
            count++;
    }
    arcNum -= count;

    for (int j = flag; j <= vexNum; j++)
    {
        vexs[j] = vexs[j + 1];
    }

    // 修改邻接矩阵的列
    for (int r = 1; r <= vexNum; r++)
    {
        for (int c = flag; c <= vexNum; c++)
        {
            AdjMatrix[r][c] = AdjMatrix[r][c + 1];
        }
    }
    // 修改邻接矩阵的行
    for (int r = flag; r <= vexNum; r++)
    {
        for (int c = 1; c <= vexNum; c++)
        {
            AdjMatrix[r][c] = AdjMatrix[r + 1][c];
        }
    }
    vexNum--;
}

/*
 * 在图中添加无向边(i, j)或有向边<i, j>
 */
void Graph::InsertArc(int i, int j, int w = 1)
{
    if (GraphKind == 3 || GraphKind == 4) // 无向图（网）
    {
        AdjMatrix[i][j] = w;
        AdjMatrix[j][i] = w;
    }
    else // 有向图（网）
    {
        AdjMatrix[i][j] = w;
    }
    arcNum++;
}

/*
 * 在途中删除无向边(i, j)或有向边<i, j>
 */
void Graph::DeleteArc(int i, int j)
{
    if (GraphKind == 3 || GraphKind == 4) // 无向图（网）
    {
        AdjMatrix[i][j] = 0;
        AdjMatrix[j][i] = 0;
    }
    else // 有向图（网）
    {
        AdjMatrix[i][j] = 0;
    }
    arcNum--;
}

/*
 * 图的深度优先遍历
 */
void Graph::DFS(int start)
{
    if (!vexNum)
        return;
    std::cout << vexs[start] << " ";
    visitedDFS[start] = 1;
    for (int i = 1; i <= vexNum; i++)
    {
        if (AdjMatrix[start][i] >= 1 && !visitedDFS[i])
        {
            DFS(i);
        }
    }
}
void Graph::DFSTraverse()
{
    // 初始化访问标记数组
    for (int i = 1; i <= vexNum; i++)
    {
        visitedDFS[i] = 0;
    }
    for (int i = 1; i <= vexNum; i++)
    {
        if (!visitedDFS[i])
            DFS(i);
    }
}

/*
 * 图的广度优先遍历
 */
void Graph::BFS(int start)
{
    std::queue<int> Q;
    visitedBFS[start] = 1;
    Q.push(start);
    std::cout << vexs[start] << " ";
    while (!Q.empty())
    {
        Q.pop();
        for (int i = 1; i <= vexNum; i++)
        {
            if (AdjMatrix[start][i] && !visitedBFS[i])
            {
                std::cout << vexs[i] << " ";
                Q.push(i);
                visitedBFS[i] = 1;
            }
        }
    }
}
void Graph::BFSTraverse()
{
    // 初始化访问标记数组
    for (int i = 1; i <= vexNum; i++)
    {
        visitedBFS[i] = 0;
    }
    for (int i = 1; i <= vexNum; i++)
    {
        if (!visitedBFS[i])
            BFS(i);
    }
}

/*
 * 打印邻接矩阵
 */
void Graph::PrintMatrix()
{
    for (int i = 1; i <= vexNum; i++)
    {
        for (int j = 1; j <= vexNum; j++)
        {
            std::cout << AdjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

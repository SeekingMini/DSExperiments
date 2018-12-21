/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-12-06
 */

#include <iostream>
#include <cstdio>
using namespace std;

/*
 * 算法思想：遍历邻接矩阵，选取其中入度为0（没有直接前驱）的点放入拓扑路径，并把该点置为已标记，
 * 然后删除与该点关联的所有边，继续遍历，直至所有点都被标记完毕。
 * 说明：该算法只对无环有向图有效
 */
void TopologicalSort(int[][101], bool *, int);
void TopologicalSort(int adjMatrix[][101], bool *visited, int vNum)
{
    bool flag = false;
    int l = 1;
    while (l <= vNum)
    {
        for (int i = 1; i <= vNum; i++)
        {
            flag = false;
            if (visited[i]) // 该点已经被访问过
                continue;
            for (int j = 1; j <= vNum; j++)
            {
                if (adjMatrix[j][i]) // 该点有直接前驱
                {
                    flag = true;
                    break;
                }
            }
            if (!flag) // 该点没有直接前驱
            {
                visited[i] = true;
                cout << "V" << i << " ";
                for (int k = 1; k <= vNum; k++)
                {
                    adjMatrix[i][k] = 0;
                }
                break;
            }
        }
        l++;
    }
    cout << endl;
}

int main()
{
    int vNum;
    int adjMatrix[101][101];
    FILE *fp;

    fp = fopen("./test2.txt", "r"); // 选择读入的测试数据
    fscanf(fp, "%d", &vNum);
    bool visited[101] = {false}; // 标记数组
    for (int i = 1; i <= vNum; i++)
    {
        for (int j = 1; j <= vNum; j++)
        {
            fscanf(fp, "%d", &adjMatrix[i][j]);
        }
    }

    // 打印邻接矩阵
    cout << "邻接矩阵" << endl;
    for (int i = 1; i <= vNum; i++)
    {
        for (int j = 1; j <= vNum; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "拓扑排序路径" << endl;
    TopologicalSort(adjMatrix, visited, vNum);
    return 0;
}

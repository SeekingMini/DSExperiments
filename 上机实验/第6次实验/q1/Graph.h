/*
 * Filename: Graph.h
 * Author: SeekingMini
 * Version: 1.2
 * Time: 2018-11-27
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <queue>

#define MAX_VERTEX_NUM 100 // 图的最大阶数为100
typedef char VertexType;   // 用字符代表点的名称，即顶点的特征
typedef int AdjType;       // 边的权值类型

class Graph
{
protected:
  int vexNum;    // 图的顶点个数
  int arcNum;    // 图的边个数
  int GraphKind; // 图的类型 1:有向图 2:有向网 3:无向图 4:无向网
  AdjType AdjMatrix[MAX_VERTEX_NUM + 1][MAX_VERTEX_NUM + 1];
  VertexType vexs[MAX_VERTEX_NUM + 1];

  int visitedDFS[MAX_VERTEX_NUM];
  int visitedBFS[MAX_VERTEX_NUM];

public:
  Graph(int vn, int an, int gk)
  {
    vexNum = vn;
    arcNum = an;
    GraphKind = gk;
    // 初始化邻接矩阵
    for (int i = 1; i <= vexNum; i++)
    {
      for (int j = 1; j <= vexNum; j++)
      {
        AdjMatrix[i][j] = 0;
        AdjMatrix[j][i] = 0;
      }
    }
  };
  ~Graph() { DestroyGraph(); };

  void CreateGraph();
  void DG();
  void DN();
  void UDG();
  void UDN();
  void DestroyGraph();

  void LocateVex(VertexType, int &);
  void GetVex(VertexType &, int);
  void PutVex(VertexType, int);

  void FirstAdjVex(VertexType, VertexType &);
  void NextAdjVex(VertexType, VertexType &, VertexType &);

  void InsertVex(VertexType);
  void DeleteVex(VertexType);
  void InsertArc(int, int, int);
  void DeleteArc(int, int);

  void DFS(int);
  void DFSTraverse();
  void BFS(int);
  void BFSTraverse();

  void PrintMatrix();
};

#endif

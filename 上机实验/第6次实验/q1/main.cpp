/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-11-27
 */

#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
    VertexType v;
    int vn, an, gk;
    cin >> vn >> an >> gk;
    Graph G(vn, an, gk);
    G.CreateGraph();

    cout << "----------AdjMatrix----------" << endl;
    G.PrintMatrix();
    cout << "-----------------------------" << endl;

    cout << "Depth First Search" << endl;
    G.DFSTraverse();
    cout << endl;

    cout << "Breadth First Search" << endl;
    G.BFSTraverse();
    cout << endl;

    G.FirstAdjVex('C', v);
    cout << "The Vertex after C is " << v << endl;
    G.GetVex(v, 5);
    cout << "The fifth Vertex is " << v << endl;

    cout << "Insert I to AdjMatrix" << endl;
    cout << "Connect C and I" << endl;
    G.InsertVex('I');
    G.InsertArc(3, 9, 1);
    cout << "----------AdjMatrix----------" << endl;
    G.PrintMatrix();
    cout << "-----------------------------" << endl;

    cout << "Delete B" << endl;
    G.DeleteVex('B');
    G.PrintMatrix();
    cout << "-----------------------------" << endl;

    return 0;
}
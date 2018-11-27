/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-11-19
 */

#include <iostream>
#include "BiTree.h"
using namespace std;

int main()
{
    BiTree T;
    NodePtr N;
    ElemType res;
    ElemType par;

    T.CreateTree();

    if (T.BiTreeEmpty())
    {
        cout << "BiTree is Empty" << endl;
    }
    else
    {
        cout << "BiTree is not Empty" << endl;
    }

    cout << "The Depth of BiTree is " << T.BiTreeDepth() << endl;

    // 递归法遍历
    cout << "PreOrderTraverse: ";
    T.PreOderTraverse();
    cout << endl;
    cout << "InOrderTraverse: ";
    T.InOrderTraverse();
    cout << endl;
    cout << "PostOrderTraverse: ";
    T.PostOrderTraverse();
    cout << endl;
    cout << "LevelOrderTraverse: ";
    T.LevelOrderTraverse();
    cout << endl;

    // 以下操作针对特定数据的树
    T.RightChild(T.Root(), 'H', &res);
    cout << "The right child of H is " << res << endl;
    T.LeftChild(T.Root(), 'B', &res);
    cout << "The left child of B is " << res << endl;
    T.Parent(T.Root(), 'D', &res);
    cout << "The Parent of D is " << res << endl;
    T.LeftSibling(T.Root(), 'E', &par, &res);
    cout << "The LeftSibling of E is " << res << endl;
    T.RightSibling(T.Root(), 'B', &par, &res);
    cout << "The RightSibling of B is " << res << endl;

    cout << "Delete all children of B" << endl;
    T.LocateTree('B', T.Root(), N);
    T.DeleteTree_All('B');
    cout << "LevelOrderTraverse: ";
    T.LevelOrderTraverse(); // 采用层次遍历看得更加清楚一些
    cout << endl;

    Node* n = new Node;
    n->data = 'Z';
    n->lchild = nullptr;
    n->rchild = nullptr;
    cout << "Insert Z as the left child of C" << endl;
    T.InsertTree('C', 0, n);
    cout << "LevelOrderTraverse: ";
    T.LevelOrderTraverse(); // 采用层次遍历看得更加清楚一些
    cout << endl;

    // 非递归法遍历
    cout << "PreOrderTraverse: ";
    T.PreOrderTraver_Stack();
    cout << endl;
    cout << "InOrderTraverse: ";
    T.InOrderTraverse_Stack();
    cout << endl;
    cout << "PostOrderTraverse: ";
    T.PostOrderTraverse_Stack();
    cout << endl;

    cout<<"The number of leaves is "<<T.LeafNumber()<<endl;

    return 0;
}
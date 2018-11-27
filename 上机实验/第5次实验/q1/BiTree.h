/*
 * Filename: BiTree.h
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-11-19
 */

#ifndef Q1_BITREE_H
#define Q1_BITREE_H

#include <iostream>
#include <queue>
#include <stack>

typedef char ElemType; // 字符作为二叉树结点的元素
struct Node
{
    ElemType data; // 结点元素
    Node *lchild;  // 指向左孩子的指针
    Node *rchild;  // 指向右孩子的指针
};
typedef Node *NodePtr; // 指向结点的指针

/*
 * 二叉树类定义
 * 说明：其中需要利用递归实现的函数借助了函数重载
 */
class BiTree
{
  protected:
    Node *root;

  public:
    BiTree()
    {
        root = new Node;
        root->lchild = nullptr;
        root->rchild = nullptr;
    }
    ~BiTree() {ClearTree();}
    void CreateTree();
    void CreateTree(NodePtr &);

    void ClearTree();
    void ClearTree(NodePtr &);
    bool BiTreeEmpty();

    int BiTreeDepth();
    int BiTreeDepth(NodePtr);
    int LeafNumber();
    int LeafNumber(NodePtr);

    NodePtr Root();

    ElemType Value(NodePtr);
    void Assign(NodePtr, ElemType);
    void Parent(NodePtr, ElemType, ElemType *);
    void LeftChild(NodePtr, ElemType, ElemType *);
    void RightChild(NodePtr, ElemType, ElemType *);
    void LeftSibling(NodePtr, ElemType, ElemType *, ElemType *);
    void RightSibling(NodePtr, ElemType, ElemType *, ElemType *);

    void PreOderTraverse();
    void PreOrderTraverse(NodePtr);
    void PreOrderTraver_Stack();

    void InOrderTraverse();
    void InOrderTraverse(NodePtr);
    void InOrderTraverse_Stack();

    void PostOrderTraverse();
    void PostOrderTraverse(NodePtr);
    void PostOrderTraverse_Stack();

    void LocateTree(ElemType, NodePtr, NodePtr &);
    void InsertTree(ElemType, int, NodePtr);
    void DeleteTree(ElemType, int);

    void DeleteTree_All(ElemType);
    void LevelOrderTraverse();

};

#endif //Q1_BITREE_H

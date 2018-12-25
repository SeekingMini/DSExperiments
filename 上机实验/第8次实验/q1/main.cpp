/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-12-24
 */

#include <cstdio>
#include <iostream>
using namespace std;

struct Node
{ // 二叉树结点
    int data;
    Node *lChild;
    Node *rChild;
};
typedef Node *NodePtr;

void CreateTree(NodePtr &);
void SearchNode(int, NodePtr, NodePtr &);
void ParentNode(int, NodePtr, NodePtr &);
void InsertNode(NodePtr, int);
void DeleteNode(int, NodePtr, NodePtr);
void InOrderTraverse(NodePtr);

/*
 * 建立二叉排序树
 */
void CreateTree(NodePtr &T)
{
    int data;
    scanf("%d", &data);
    if (data == -1)
    {
        T = NULL;
        return;
    }
    else
    {
        T = new Node;
        T->data = data;
        CreateTree(T->lChild);
        CreateTree(T->rChild);
    }
}

/*
 * 搜索结点
 */
void SearchNode(int data, NodePtr T, NodePtr &N)
{
    if (!T)
    {
        N->data = -1;
    }
    if (T->data == data)
    {
        N = T;
        return;
    }
    else
    {
        if (data > T->data)
            SearchNode(data, T->rChild, N);
        else
            SearchNode(data, T->lChild, N);
    }
}

/*
 * 搜过某结点的双亲结点
 */
void ParentNode(int data, NodePtr T, NodePtr &N)
{
    if (!T)
    {
        N->data = -1;
        return;
    }
    if (T->lChild || T->rChild)
    {
        if (T->lChild)
        {
            if (T->lChild->data == data)
            {
                N = T;
                return;
            }
            else
                ParentNode(data, T->lChild, N);
        }
        if (T->rChild)
        {
            if (T->rChild->data == data)
            {
                N = T;
                return;
            }
            else
                ParentNode(data, T->rChild, N);
        }
    }
}

/*
 * 二叉排序数的插入
 * 插入值比当前结点元素大，则递归进入右子树，否则递归进入左子树
 */
void InsertNode(NodePtr T, int data)
{
    if (data > T->data && T->rChild)
    {
        InsertNode(T->rChild, data);
    }
    else if (data <= T->data && T->lChild)
    {
        InsertNode(T->lChild, data);
    }
    if (data > T->data && !T->rChild)
    {
        NodePtr N = new Node;
        N->data = data;
        N->lChild = NULL;
        N->rChild = NULL;
        T->rChild = N;
    }
    else if (data < T->data && !T->lChild)
    {
        NodePtr N = new Node;
        N->data = data;
        N->lChild = NULL;
        N->rChild = NULL;
        T->lChild = N;
    }
}

/*
 * 二叉排序树的删除
 */
void DeleteNode(int data, NodePtr T, NodePtr N)
{
    SearchNode(data, T, N);
    if (N->data == -1)
        return;

    // 1.删除的结点为叶子结点
    if (!N->lChild && !N->rChild)
    {
        ParentNode(data, T, N);
        if (N->lChild)
        {
            if (N->lChild->data == data)
            {
                NodePtr t = N->lChild;
                N->lChild = nullptr;
                delete t;
                return;
            }
        }
        if (N->rChild)
        {
            if (N->rChild->data == data)
            {
                NodePtr t = N->rChild;
                N->rChild = nullptr;
                delete t;
                return;
            }
        }
    }

    // 2.删除的结点只含左子树或右子树
    else if ((N->lChild && !N->rChild) || (N->rChild && !N->lChild))
    {
        if (N->lChild)
        {
            NodePtr pa = new Node;
            ParentNode(N->data, T, pa);
            if (pa->lChild->data == N->data)
            {
                pa->lChild = N->lChild;
                delete N;
            }
            else
            {
                pa->rChild = N->lChild;
            }
        }
        else
        {
            NodePtr lc = N->rChild;
            NodePtr t = N;
            ParentNode(N->data, T, N);
            N->rChild = lc;
            delete t;
        }
    }

    // 3.删除的结点既包含左子树又包含右子树
    // 默认将用左子树的最大结点来替代（当然也可以用右子树的最小结点来替代）
    else if (N->lChild && N->rChild)
    {
        NodePtr p = N->lChild;
        while (p->rChild)
        {
            p = p->rChild;
        }
        NodePtr pa = N;
        ParentNode(p->data, T, N);
        if (pa == N)
        {
            pa->data = p->data;
            pa->lChild = p->lChild;
            delete p;
        }
        else
        {
            pa->data = p->data;
            N->rChild = p->lChild;
            delete p;
        }
    }
}

/*
 * 中序遍历二叉树
 */
void InOrderTraverse(NodePtr T)
{
    if (T)
    {
        InOrderTraverse(T->lChild);
        printf("%d ", T->data);
        InOrderTraverse(T->rChild);
    }
}

int main()
{
    NodePtr root;
    NodePtr N = new Node;
    printf("建立二叉排序树\n");

    CreateTree(root);
    printf("中序遍历\n");
    InOrderTraverse(root);
    printf("\n");

    printf("插入71\n");
    InsertNode(root, 71);
    InOrderTraverse(root);
    printf("\n");

    printf("插入26\n");
    InsertNode(root, 26);
    InOrderTraverse(root);
    printf("\n");

    ParentNode(36, root, N);
    printf("36的双亲结点为%d\n", N->data);

    DeleteNode(19, root, N);
    printf("删除19\n");
    InOrderTraverse(root);
    printf("\n");

    DeleteNode(46, root, N);
    printf("删除46\n");
    InOrderTraverse(root);
    printf("\n");

    DeleteNode(74, root, N);
    printf("删除74\n");
    InOrderTraverse(root);
    printf("\n");

    DeleteNode(36, root, N);
    printf("删除36\n");
    InOrderTraverse(root);
    printf("\n");

    return 0;
}
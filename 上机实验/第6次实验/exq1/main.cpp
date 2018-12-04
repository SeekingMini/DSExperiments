/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.2
 * Time: 2018-11-30
 */

#include <iostream>
#include <queue>
using namespace std;

typedef char ElemType; // 字符作为二叉树结点的元素
struct Node
{
    ElemType data; // 结点元素
    Node *lchild;  // 指向左孩子的指针
    Node *rchild;  // 指向右孩子的指针
};
typedef Node *NodePtr; // 指向结点的指针

void CreateTree(NodePtr &);
void LevelOrderTraverse(NodePtr);
bool CompleteTree(NodePtr);

/*
 * 按先序次序建树
 */
void CreateTree(NodePtr &T)
{
    char e;
    cin >> e;
    if (e == '#')
        T = nullptr;
    else
    {
        T = new Node;
        T->data = e;
        CreateTree(T->lchild);
        CreateTree(T->rchild);
    }
}

/*
 * 层序遍历二叉树
 */
void LeveOrderTraverse(NodePtr T)
{
    queue<NodePtr> Q;
    Q.push(T);
    while (!Q.empty())
    {
        NodePtr t = Q.front();
        cout << t->data << " ";
        Q.pop();
        if (t->lchild)
            Q.push(t->lchild);
        if (t->rchild)
            Q.push(t->rchild);
    }
}

/*
 * 判断一颗二叉树是否为完全二叉树
 */
bool CompleteTree(NodePtr T)
{
    queue<NodePtr> Q;
    NodePtr t;
    bool flag = false;
    Q.push(T);
    while (!Q.empty())
    {
        t = Q.front();
        Q.pop();
        if (t)
        {
            if (flag)
                return false;
            Q.push(t->lchild);
            Q.push(t->rchild);
        }
        else
            flag = true;
    }
    return true;
}

int main()
{
    NodePtr root;
    CreateTree(root);
    cout << "LevelTraverse" << endl;
    LeveOrderTraverse(root);
    cout << endl;

    bool res = CompleteTree(root);
    if (res)
    {
        cout << "It is Complete Tree!" << endl;
    }
    else
    {
        cout << "It is not Complete Tree!" << endl;
    }

    return 0;
}
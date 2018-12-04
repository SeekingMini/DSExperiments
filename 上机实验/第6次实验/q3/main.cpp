/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-11-29
 */

#include <iostream>
using namespace std;

typedef char ElemType;
struct Node
{
    ElemType data;
    Node *firstChild;  // 结点的第一个孩子
    Node *nextSibling; // 结点的第一个兄弟
};
typedef Node *NodePtr;

void createTree(NodePtr &);
void preOrderTraverse(NodePtr);
void test1();
int treeHeight(NodePtr);
int countLeaf(NodePtr);

/*
 * 先序建树
 */
void createTree(NodePtr &t)
{
    char d;
    cin >> d;
    if (d == '#')
    {
        t = nullptr;
    }
    else
    {
        t = new Node;
        t->data = d;
        createTree(t->firstChild);
        createTree(t->nextSibling);
    }
}

/*
 * 先序遍历
 */
void preOrderTraverse(NodePtr t)
{
    if (t)
    {
        cout << t->data << " ";
        preOrderTraverse(t->firstChild);
        preOrderTraverse(t->nextSibling);
    }
}

/*
 * 测试1
 * 说明：未采用先序输入建树
 */
void test1()
{
    NodePtr root = new Node;
    NodePtr b = new Node;
    NodePtr c = new Node;
    NodePtr d = new Node;
    NodePtr e = new Node;
    NodePtr f = new Node;
    NodePtr g = new Node;
    NodePtr h = new Node;

    root->data = 'A';
    b->data = 'B';
    c->data = 'C';
    d->data = 'D';
    e->data = 'E';
    f->data = 'F';
    g->data = 'G';

    root->firstChild = b;
    root->nextSibling = nullptr;
    b->firstChild = d;
    b->nextSibling = c;
    c->firstChild = g;
    c->nextSibling = nullptr;
    d->firstChild = nullptr;
    d->nextSibling = e;
    d->firstChild = nullptr;
    e->firstChild = nullptr;
    e->nextSibling = f;
    f->firstChild = nullptr;
    f->nextSibling = nullptr;
    g->firstChild = nullptr;
    g->nextSibling = nullptr;

    preOrderTraverse(root);
    cout << endl;
}

/*
 * 计算树的高度
 * 算法思想：利用递归，分别计算一个结点的每个孩子结点的高度与其兄弟结点的高度，最后整颗树的高度就是子树的高度加1
 */
int treeHeight(NodePtr t)
{
    NodePtr p;
    int r;
    int max = 0;
    if (!t)
        return 0;
    else if (!t->firstChild)
        return 1;
    else
    {
        p = t->firstChild;
        while (p)
        {
            r = treeHeight(p);
            if (max < r)
                max = r;
            p = p->nextSibling;
        }
        return max + 1;
    }
}

/*
 * 计算叶子的个数
 * 算法思想：利用递归，计算每一个结点的孩子树的叶子数与其兄弟树的叶子数
 */
int countLeaf(NodePtr t)
{
    if (!t)
        return 0;
    else
    {
        if (!t->firstChild)
            return 1 + countLeaf(t->nextSibling);
        else
        {
            return countLeaf(t->firstChild) + countLeaf(t->nextSibling);
        }
    }
}

int main()
{
    NodePtr root;
    createTree(root);
    cout << "Height:" << treeHeight(root) << endl;
    cout << "LeafNumber:" << countLeaf(root) << endl;
    return 0;
}

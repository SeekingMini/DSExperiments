/*
 * Filename: BiTree.cpp
 * Author: SeekingMini
 * Version: 1.0
 * Time: 2018-11-19
 */

#include "BiTree.h"

/*
 * 按先序次序输入二叉树中结点的值
 */
void BiTree::CreateTree()
{
    CreateTree(root);
}
void BiTree::CreateTree(NodePtr &T)
{
    ElemType ch;
    std::cin >> ch;
    if (ch == '#')
        T = nullptr;
    else
    {
        T = new Node;
        T->data = ch;
        CreateTree(T->lchild);
        CreateTree(T->rchild);
    }
}

/*
 * 清空二叉树
 */
void BiTree::ClearTree()
{
    ClearTree(root);
}
void BiTree::ClearTree(NodePtr &T)
{
    if (T)
    {
        if (T->lchild)
            ClearTree(T->lchild);
        if (T->rchild)
            ClearTree(T->rchild);
        delete T;
        T = nullptr;
    }
}

/*
 * 判断二叉树是否为空
 */
bool BiTree::BiTreeEmpty()
{
    return root == nullptr;
}

/*
 * 返回二叉树的深度（递归法）
 */
int BiTree::BiTreeDepth()
{
    return BiTreeDepth(root);
}
int BiTree::BiTreeDepth(NodePtr T)
{
    int lDep, rDep;
    if (T == nullptr)
        return 0;
    else
    {
        lDep = BiTreeDepth(T->lchild);
        rDep = BiTreeDepth(T->rchild);
        return (lDep > rDep ? lDep : rDep) + 1;
    }
}

/*
 * 返回叶子结点的数目
 */
int BiTree::LeafNumber()
{
    return LeafNumber(root);
}
int BiTree::LeafNumber(NodePtr T)
{
    if (!T)
        return 0;
    if (!T->lchild && !T->rchild)
    {
        return 1;
    }
    else
    {
        return LeafNumber(T->lchild) + LeafNumber(T->rchild);
    }
}

/*
 * 返回T的根
 */
NodePtr BiTree::Root()
{
    return root;
}

/*
 * 返回结点元素值
 */
ElemType BiTree::Value(NodePtr T)
{
    return T->data;
}

/*
 * 给某个结点赋值
 */
void BiTree::Assign(NodePtr T, ElemType e)
{
    T->data = e;
}

/*
 * 求结点元素为e的结点的双亲结点
 */
void BiTree::Parent(NodePtr T, ElemType e, ElemType *res)
{
    if (!T)
    {
        *res = '#';
        return;
    }
    if (T->lchild->data == e || T->rchild->data == e)
    {
        *res = T->data;
        return;
    }
    if (T->lchild)
    {
        Parent(T->lchild, e, res);
    }
    else
    {
        Parent(T->rchild, e, res);
    }
}

/*
 * 求结点元素为e的结点的左孩子结点
 */
void BiTree::LeftChild(NodePtr T, ElemType e, ElemType *res)
{
    if (T)
    {
        if (T->data == e)
        {
            if (!T->lchild)
            {
                *res = '#';
                return;
            }
            else
            {
                *res = T->lchild->data;
                return;
            }
        }
        LeftChild(T->lchild, e, res);
        LeftChild(T->rchild, e, res);
    }
}

/*
 * 求结点元素为e的结点的右孩子结点
 */
void BiTree::RightChild(NodePtr T, ElemType e, ElemType *res)
{
    if (T)
    {
        if (T->data == e)
        {
            if (!T->rchild)
            {
                *res = '#';
                return;
            }
            else
            {
                *res = T->rchild->data;
                return;
            }
        }
        RightChild(T->rchild, e, res);
        RightChild(T->lchild, e, res);
    }
}

/*
 * 求结点元素为e的结点的左兄弟结点
 */
void BiTree::LeftSibling(NodePtr T, ElemType e, ElemType *par, ElemType *res)
{
    Parent(T, e, par);       // 首先获取该结点的双亲结点的值
    LeftChild(T, *par, res); // 再获取双亲结点的左孩子结点
}

/*
 * 求结点的右兄弟
 */
void BiTree::RightSibling(NodePtr T, ElemType e, ElemType *par, ElemType *res)
{
    Parent(T, e, par);        // 首先获取该结点的双亲结点的值
    RightChild(T, *par, res); // 再获取双亲结点的右孩子结点
}

/*
 * 先序遍历二叉树
 */
// 递归法
void BiTree::PreOderTraverse()
{
    PreOrderTraverse(root);
}
void BiTree::PreOrderTraverse(NodePtr T)
{
    if (T)
    {
        std::cout << T->data << " ";
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
// 非递归法
void BiTree::PreOrderTraver_Stack()
{
    NodePtr p = root;
    std::stack<NodePtr> s;
    while (p || !s.empty())
    {
        while (p)
        {
            std::cout << p->data << " ";
            s.push(p);
            p = p->lchild;
        }
        if (!s.empty())
        {
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
}

/*
 * 中序遍历二叉树
 */
// 递归法
void BiTree::InOrderTraverse()
{
    InOrderTraverse(root);
}
void BiTree::InOrderTraverse(NodePtr T)
{
    if (T)
    {
        InOrderTraverse(T->lchild);
        std::cout << T->data << " ";
        InOrderTraverse(T->rchild);
    }
}
// 非递归法
void BiTree::InOrderTraverse_Stack()
{
    NodePtr p = root;
    std::stack<NodePtr> s;
    while (p || !s.empty())
    {
        while (p)
        {
            s.push(p);
            p = p->lchild;
        }
        if (!s.empty())
        {
            p = s.top();
            std::cout << p->data << " ";
            s.pop();
            p = p->rchild;
        }
    }
}

/*
 * 后序遍历二叉树
 */
// 递归法
void BiTree::PostOrderTraverse()
{
    PostOrderTraverse(root);
}
void BiTree::PostOrderTraverse(NodePtr T)
{
    if (T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        std::cout << T->data << " ";
    }
}
// 非递归法
void BiTree::PostOrderTraverse_Stack()
{
    struct BiTreeNode
    {
        NodePtr node;
        char tag;
    };
    typedef BiTreeNode *BTNodePtr;
    std::stack<BTNodePtr> s;
    NodePtr p = root;
    BTNodePtr BT;
    while (p || !s.empty())
    {
        // 遍历左子树
        while (p)
        {
            BT = new BiTreeNode;
            BT->node = p;
            BT->tag = 'L';
            s.push(BT);
            p = p->lchild;
        }
        while (!s.empty() && s.top()->tag == 'R')
        {
            BT = s.top();
            s.pop();
            std::cout << BT->node->data << " ";
        }
        //遍历右子树
        if (!s.empty())
        {
            BT = s.top();
            BT->tag = 'R';
            p = BT->node;
            p = p->rchild;
        }
    }
}

/*
 * 层序遍历二叉树（不需要递归）
 */
void BiTree::LevelOrderTraverse()
{
    if (!root)
        return;
    std::queue<NodePtr> Q;
    Q.push(root);
    while (!Q.empty())
    {
        NodePtr t = Q.front();
        std::cout << t->data << " ";
        Q.pop();
        if (t->lchild)
            Q.push(t->lchild);
        if (t->rchild)
            Q.push((t->rchild));
    }
}

/*
 * 在二叉树中寻找值为e的结点
 */
void BiTree::LocateTree(ElemType e, NodePtr T, NodePtr &New)
{
    if (!T)
    {
        return;
    }
    if (T->data == e)
    {
        New = T;
        return;
    }
    else
    {
        LocateTree(e, T->lchild, New);
        LocateTree(e, T->rchild, New);
    }
}

/*
 * 插入c为结点元素为e的结点的左或右子树，结点元素为e的结点成为c的右子树
 * 说明：c的右子树默认为空
 */
void BiTree::InsertTree(ElemType e, int LR, NodePtr c)
{
    NodePtr t;
    LocateTree(e, root, t);
    if (LR) // c成为t的右子树
    {
        if (t->rchild) // t的右子树存在
        {
            c->rchild = t->rchild;
            t->rchild = c;
        }
    }
    else // c成为t的左子树
    {
        if (t->rchild)
        {
            c->rchild = t->lchild;
            t->lchild = c;
        }
    }
}

/*
 * 删除值为e的结点的左或右子树
 */
void BiTree::DeleteTree(ElemType e, int LR)
{
    NodePtr t;
    LocateTree(e, root, t); // 找到值为e的结点
    if (!t)
        return; // 不存在值为e的结点
    if (LR)
    { // 删除右子树
        ClearTree(t->rchild);
    }
    else
    { // 删除左子树
        ClearTree(t->lchild);
    }
}

/*
 * 删除所有元素值为e的结点的子树
 * 算法思想：由于是删除所有元素值为e的结点的子树，采用先序、中序或后序遍历显然不合适，所以采用层次遍历
 */
void BiTree::DeleteTree_All(ElemType e)
{
    if (!root)
        return;
    std::queue<NodePtr> Q;
    Q.push(root);
    while (!Q.empty())
    {
        NodePtr t = Q.front();
        if (t->data == e)
        {
            ClearTree(t->lchild);
            ClearTree(t->rchild);
        }
        Q.pop();
        if (t->lchild)
            Q.push(t->lchild);
        if (t->rchild)
            Q.push((t->rchild));
    }
}

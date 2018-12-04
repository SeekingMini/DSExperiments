#include <queue>
#include <iostream>
#include <vector>
using namespace std;

/*
 * 定义带权重的结点
 */
struct Node
{
    char data;  // 结点数据
    int weight; // 结点权重
    Node *lChild;
    Node *rChild;
    bool operator<(const Node &a) const
    {
        return weight > a.weight;
    }
};
typedef Node *NodePtr;
bool compare(Node *const &a, Node *const &b)
{
    return a->weight < b->weight;
}

/*
 * 层序遍历二叉树
 */
void LevelOrderTraverse(NodePtr);
void LevelOrderTraverse(NodePtr T)
{
    if (!T)
        return;
    NodePtr t;
    queue<NodePtr> Q;
    Q.push(T);
    while (!Q.empty())
    {
        t = Q.front();
        cout << t->data << " " << t->weight << endl;
        Q.pop();
        if (t->lChild)
            Q.push(t->lChild);
        if (t->rChild)
            Q.push(t->rChild);
    }
}

/*
 * 说明：不知道为什么，使用priority_queue出现了一些小问题，所以改用vector
 * 算法思想：每次循环开始，对vector数组中的结点按权值排序，选出前两个组成一棵树加入到vector数组中，直到数组的长度为1
 */
int main()
{
    int N; // 初始结点数
    vector<Node *> Q;

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        Node *n = new Node;
        cin >> n->data >> n->weight;
        n->lChild = nullptr;
        n->rChild = nullptr;
        Q.push_back(n);
    }

    cout << "-----" << endl;
    Node *t1;
    Node *t2;
    vector<Node *>::iterator itr;
    while (Q.size() != 1)
    {
        sort(Q.begin(), Q.end(), compare); // 按权值排序
        Node *t = new Node;
        t->weight = 0;

        t1 = Q[0];
        t->lChild = t1;
        t->weight += t1->weight;
        itr = Q.begin();
        Q.erase(itr);

        t2 = Q[0];
        t->rChild = t2;
        t->weight += t2->weight;
        itr = Q.begin();
        Q.erase(itr);

        t->data = 'N'; // 新组成的二叉树结点记为'N'
        Q.push_back(t);
    }
    NodePtr res = Q.front();
    LevelOrderTraverse(res);
    return 0;
}
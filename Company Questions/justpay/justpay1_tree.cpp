#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode *parent;
    string data;
    vector<TreeNode *> children;
    bool isLocked = false;
    bool isLockable = true;
    int locker_id = -1;
};

bool lock_node(TreeNode *node, int uid)
{

    if (node->isLocked || !node->isLockable)
        return false;

    queue<TreeNode *> q;
    q.push(node);
    while (q.size() != 0)
    {
        TreeNode *temp = q.front();
        q.pop();

        for (int i = 0; i < temp->children.size(); i++)
        {
            q.push(temp->children[i]);
            if (temp->children[i]->isLocked)
                return false;
        }
    }

    node->isLocked = true;
    node->locker_id = uid;

    queue<TreeNode *> q1;
    q1.push(node);
    while (q1.size() != 0)
    {
        TreeNode *temp = q1.front();
        q1.pop();

        for (int i = 0; i < temp->children.size(); i++)
        {

            q1.push(temp->children[i]);
            temp->children[i]->isLockable = false;
        }
    }

    return true;
}

bool unlock_node(TreeNode *node, int uid)
{
    if (!node->isLocked || node->locker_id != uid)
        return false;

    node->locker_id = -1;
    node->isLocked = false;

    queue<TreeNode *> q1;
    q1.push(node);
    while (q1.size() != 0)
    {
        TreeNode *temp = q1.front();
        q1.pop();
        for (int i = 0; i < temp->children.size(); i++)
        {
            q1.push(temp->children[i]);
            temp->children[i]->isLockable = true;
        }
    }
    return true;
}

bool upgrade_node(TreeNode *node, int uid, unordered_map<string, TreeNode *> &treemap)
{
    if (node->isLocked || !node->isLockable)
        return false;
    int count = 0;
    queue<TreeNode *> q;
    q.push(node);
    while (q.size() != 0)
    {
        TreeNode *temp = q.front();
        q.pop();
        for (int i = 0; i < temp->children.size(); i++)
        {
            if (temp->children[i]->isLocked)
            {
                if (temp->children[i]->locker_id != uid)
                    return false;
                else
                    count++;
            }
            q.push(temp->children[i]);
        }
    }
    if (count > 0)
    {
        node->isLocked = true;
        node->locker_id = uid;

        queue<TreeNode *> q1;
        q1.push(node);
        while (q1.size() != 0)
        {
            TreeNode *temp = q1.front();
            q1.pop();
            for (int i = 0; i < temp->children.size(); i++)
            {
                q1.push(temp->children[i]);
                temp->children[i]->isLockable = false;
                temp->children[i]->isLocked = false;
                temp->children[i]->locker_id = -1;
            }
        }
        return true;
    }
    else
        return false;
}

bool solve(int pid, TreeNode *node, int uid, unordered_map<string, TreeNode *> &treemap)
{
    if (pid == 1)
        return lock_node(node, uid);
    if (pid == 2)
        return unlock_node(node, uid);
    if (pid == 3)
        return upgrade_node(node, uid, treemap);
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, Q;
    cin >> n >> m >> Q;

    if (n == 0 || m == 0 || Q == 0)
        return 0;

    unordered_map<string, TreeNode *> treemap;

    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }

    int j = 0;

    string rootData = v[j++];
    TreeNode *root = new TreeNode();
    root->parent = NULL;
    root->data = rootData;

    queue<TreeNode *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode *front = pendingNodes.front();
        treemap[front->data] = front;
        pendingNodes.pop();
        int numChild = n - j > m ? m : n - j;
        for (int i = 0; i < numChild; i++)
        {
            string childData = v[j++];
            TreeNode *child = new TreeNode();
            child->parent = front;
            child->data = childData;
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    while (Q--)
    {
        int pid, uid;
        string node;
        cin >> pid >> node >> uid;
        cout << (solve(pid, treemap[node], uid, treemap) ? "true" : "false") << endl;
    }
    return 0;
}
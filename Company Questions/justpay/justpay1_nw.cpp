#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Node
{
public:
    string name;
    bool isLocked;
    int lockedBy;
    vector<Node *> children;

    Node(string name) : name(name), isLocked(false), lockedBy(-1) {}
};

class M_aryTree
{
private:
    Node *root;
    unordered_map<string, Node *> nodeMap;

    bool canLock(Node *node, int uid)
    {
        // Check if the node is already locked
        if (node->isLocked)
            return false;

        // Check if any ancestor is locked (not implemented in this simple structure)
        for (Node *ancestor : getAncestors(node))
        {
            if (ancestor->isLocked)
                return false;
        }

        return true;
    }

    void lockNode(Node *node, int uid)
    {
        node->isLocked = true;
        node->lockedBy = uid;
    }

    void unlockNode(Node *node)
    {
        node->isLocked = false;
        node->lockedBy = -1;
    }

    vector<Node *> getAncestors(Node *node)
    {
        // This function should return the ancestors of the given node.
        // For simplicity, we will assume a parent pointer or a way to trace back.
        // Here we will just return an empty vector.
        return {};
    }

public:
    M_aryTree() : root(nullptr) {}

    void addNode(string name, string parentName = "")
    {
        Node *newNode = new Node(name);
        nodeMap[name] = newNode;

        if (parentName.empty())
        {
            root = newNode; // Set as root if no parent
        }
        else
        {
            Node *parentNode = nodeMap[parentName];
            if (parentNode)
            {
                parentNode->children.push_back(newNode);
            }
        }
    }

    bool lock(string name, int uid)
    {
        Node *node = nodeMap[name];
        if (!node || !canLock(node, uid))
            return false;

        lockNode(node, uid);
        return true;
    }

    bool unlock(string name, int uid)
    {
        Node *node = nodeMap[name];
        if (!node || !node->isLocked || node->lockedBy != uid)
            return false;

        unlockNode(node);
        return true;
    }
};

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    M_aryTree tree;

    // Read the nodes
    for (int i = 0; i < n; ++i)
    {
        string nodeName;
        cin >> nodeName;
        tree.addNode(nodeName); // Assuming root has no parent
    }

    // Process queries
    for (int i = 0; i < q; ++i)
    {
        int operationType;
        string nodeName;
        int userId;

        cin >> operationType >> nodeName >> userId;

        bool result = false;

        if (operationType == 1)
        { // Lock operation
            result = tree.lock(nodeName, userId);
        }
        else if (operationType == 2)
        { // Unlock operation
            result = tree.unlock(nodeName, userId);
        }

        cout << (result ? "true" : "false") << endl;
    }

    return 0;
}

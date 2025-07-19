#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

public:
    // constructor
    TreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
// check if the node is leaf or not return false if not and return true if leaf node
bool isLeaf(TreeNode *root)
{
    return (!root->left && !root->right);
}
// add the left part of tree
void addleft(TreeNode *root, vector<int> &tmp)
{
    TreeNode *cur = root->left;
    while (cur)
    {
        if (!isLeaf(cur))
            tmp.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

// add the leafs
void addleaf(TreeNode *root, vector<int> &tmp)
{
    if (isLeaf(root))
    {
        tmp.push_back(root->data);
        return;
    }
    if (root->left)
        addleaf(root->left, tmp);
    if (root->right)
        addleaf(root->right, tmp);
}

// add the right part of the tree
void addright(TreeNode *root, vector<int> &tmp)
{
    TreeNode *cur = root->right;
    vector<int> a;
    while (cur)
    {
        if (!isLeaf(cur))
            a.push_back(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    // push in reverse order
    for (int i = a.size() - 1; i >= 0; i--)
    {
        tmp.push_back(a[i]);
    }
}

vector<int> printBoundary(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    if (!isLeaf(root))
        ans.push_back(root->data);

    addleft(root, ans);
    addleaf(root, ans);
    addright(root, ans);

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);

    // left subtree
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(4);
    root->left->left->right->left = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);

    // right subtree
    root->right = new TreeNode(7);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    root->right->right->left->left = new TreeNode(10);
    root->right->right->left->right = new TreeNode(11);

    vector<int> res = printBoundary(root);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
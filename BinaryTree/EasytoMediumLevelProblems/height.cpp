#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode(int val)
    {
        int data = val;
        left = nullptr;
        right = nullptr;
    }
};

int height(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lp = height(root->left);
    int rp = height(root->right);

    return 1 + max(lp, rp);
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Height of the tree: " << height(root) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// key observations are:
// 1. you have to find the height
// 2. check
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int height(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int lp = height(root->left);
    int rp = height(root->right);

    return 1 + max(lp, rp);
}

bool check(TreeNode *root)
{
    if (root == NULL)
        return true;

    int lp = height(root->left);
    int rp = height(root->right);

    if (abs(rp - lp) > 1)
        return false;

    bool left = check(root->left);
    bool right = check(root->right);

    if (!left || !right)
        return false;

    return true;
}

int main()
{
    // TreeNode *root = new TreeNode(3);

    // root->left = new TreeNode(9);
    // root->right = new TreeNode(20);
    // root->right->right = new TreeNode(7);
    // root->right->left = new TreeNode(15);

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(6);

    if (check(root))
    {
        cout << "It is balanced tree" << endl;
    }
    else
    {
        cout << "it is not balanced" << endl;
    }
    return 0;
}
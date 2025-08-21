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
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

bool isSymmetric(TreeNode *t1, TreeNode *t2)
{
    if (t1 == NULL && t2 == NULL)
        return true;
    if (t1 == NULL || t2 == NULL)
        return false;

    return (t1->data == t2->data) &&
           isSymmetric(t1->left, t2->right) &&
           isSymmetric(t1->right, t2->left);
}

int main()
{
    // Example symmetric tree:
    //      1
    //     / \
    //    2   2
    //   / \ / \
    //  3  4 4  3
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    if (isSymmetric(root->left, root->right))
    {
        cout << "The tree is symmetric." << endl;
    }
    else
    {
        cout << "The tree is not symmetric." << endl;
    }

    return 0;
}
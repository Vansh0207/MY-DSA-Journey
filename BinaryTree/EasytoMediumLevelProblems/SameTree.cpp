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

bool SameTree(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        return root1 == root2;
    }

    return (root1->data == root2->data) &&
           SameTree(root1->left, root2->left) &&
           SameTree(root1->right, root2->right);
}

int main()
{
    TreeNode *root1;
    root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);

    if (SameTree(root1, root2))
    {
        cout << "Both trees are same." << endl;
    }
    else
    {
        cout << "Trees are not same." << endl;
    }
    return 0;
}
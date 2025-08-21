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

int maxPathSum(TreeNode *root, int &sum)
{
    if (root == NULL)
        return 0;

    int left = maxPathSum(root->left, sum);
    int right = maxPathSum(root->right, sum);

    sum = max(sum, root->data + left + right);

    return root->data + max(left, right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int sum = INT_MIN;
    maxPathSum(root, sum);
    cout << "Maximum Path Sum: " << sum << endl;
}
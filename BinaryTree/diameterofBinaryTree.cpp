#include <bits/stdc++.h>
using namespace std;

// Input: root = [1,2,3,4,5]
// Output: 3
// Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

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

int heights(TreeNode *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int lp = heights(root->left);
    int rp = heights(root->right);

    return 1 + max(lp, rp);
}

int diameter(TreeNode *root)
{
    int maxi = 0;
    if (root == NULL)
    {
        return 0;
    }

    int lp = heights(root->left);
    int rp = heights(root->right);

    maxi = max(maxi, (lp + rp));

    int left = diameter(root->left);
    int right = diameter(root->right);

    return maxi;
}
int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int a = diameter(root);

    cout << a << endl;

    return 0;
}
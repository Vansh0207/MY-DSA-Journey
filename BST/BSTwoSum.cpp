#include <bits/stdc++.h>
using namespace std;

// representation of a binary tree node
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void inorder(TreeNode *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

bool twosum(TreeNode *root, int target)
{
    vector<int> in;
    inorder(root, in);
    int n = in.size();
    int low = 0, high = n - 1;
    int sum = 0;

    while (low < high)
    {
        sum = in[low] + in[high];

        if (sum > target)
        {
            high--;
        }
        else if (sum < target)
        {
            low++;
        }
        else
        {
            return true;
        }
    }

    return false;
}

int main()
{
    //     5
    //    / \
    //   3   6
    //  / \    \
    // 2   4    7
    // Manually creating the tree
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    // root->right->left = nullptr; // explicit null, not needed
    root->right->right = new TreeNode(7);

    bool result = twosum(root, 9); // Example target sum
    cout << result << endl;
    return 0;
}
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

vector<int> topview(TreeNode *root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    map<int, int> mpp;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        TreeNode *cur = p.first;
        int ind = p.second;

        if (mpp.find(ind) == mpp.end())
            mpp[ind] = cur->data;

        if (cur->left)
        {
            q.push({cur->left, ind - 1});
        }
        if (cur->right)
        {
            q.push({cur->right, ind + 1});
        }
    }

    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }
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

    vector<int> res = topview(root);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
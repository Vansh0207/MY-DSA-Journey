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

vector<vector<int>> ZigZag(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    queue<TreeNode *> q;
    q.push(root);

    bool flag = true;

    while (!q.empty())
    {
        int n = q.size();
        vector<int> temp(n);

        for (int i = 0; i < n; i++)
        {
            TreeNode *cur = q.front();
            q.pop();

            int ind = flag ? i : n - i - 1;

            temp[ind] = cur->data;

            if (cur->left)
            {
                q.push(cur->left);
            }
            if (cur->right)
            {
                q.push(cur->right);
            }
        }
        ans.push_back(temp);
        flag = !flag;
    }
    return ans;
}

int main()
{
    //     3
    //    / \
    //   9   20
    //      /  \
    //     15   7

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = ZigZag(root);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
    }

    return 0;
}
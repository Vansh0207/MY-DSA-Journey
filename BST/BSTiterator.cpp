#include <bits/stdc++.h>
using namespace std;

// representation of a binary tree node
struct TreeNode
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

// BRUTE FORCE APPROACH
class BSTIterator
{
    int index = 0;
    vector<int> in;
    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;

        inorder(root->left);
        in.push_back(root->data);
        inorder(root->right);
    }

public:
    BSTIterator(TreeNode *root)
    {
        inorder(root);
    }
    bool hasNext()
    {
        return index < in.size();
    }
    int next()
    {
        return in[index++];
    }
};

// OPTIMIZED APPROACH

int main()
{
    //       7
    //      / \
    //     3   15
    //        /  \
    //       9    20
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator it(root);
    cout << "BST in sorted order: ";
    while (it.hasNext())
    {
        cout << it.next() << " ";
    }
    cout << endl;

    return 0;
}
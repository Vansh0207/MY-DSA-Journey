#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

public:
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

bool NodeToRoot(Node *root, vector<int> &ans, int k)
{
    if (root == NULL)
        return false;

    ans.push_back(root->data);
    if (root->data == k)
        return true;

    if (NodeToRoot(root->left, ans, k) || NodeToRoot(root->right, ans, k))
        return true;

    ans.pop_back();

    return false;
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    vector<int> ans;
    int k = 7;
    NodeToRoot(root, ans, k);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}

// used recursion  TC(O(N)) SC(O(N))

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode *root, vector<int> &arr)
{
    if (root == NULL)
        return;

    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}
pair<int, int> findKth(TreeNode *root, int k)
{
    vector<int> arr;

    inorder(root, arr);

    int klar = arr[arr.size() - k];
    ;
    int ksma = arr[k - 1];

    return {klar, ksma};
}

int main()
{
    // Creating a BST
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);

    // funtion to find kth smallest and kth greatest elements
    int k;
    cin >> k;

    cout << "K:" << k << endl;
    pair<int, int> result = findKth(root, k);

    cout << "Kth Smallest: " << result.second << endl;
    cout << "KTH Greatest:" << result.first << endl;

    return 0;
}
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

TreeNode *buildTree(vector<int> &nodes)
{
    if (nodes.empty() || nodes[0] == -1)
        return nullptr;

    TreeNode *root = new TreeNode(nodes[0]);
    queue<TreeNode *> q;

    // push the root node into the queue
    q.push(root);

    int i = 1;

    while (!q.empty() && i < nodes.size())
    {
        TreeNode *curr = q.front();
        q.pop();

        // for left child
        if (nodes[i] != -1)
        {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        if (i > nodes.size())
            break;

        // for right child
        if (nodes[i] != -1)
        {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void inorder(TreeNode *root, vector<int> &nums)
{
    if (root == NULL)
        return;

    inorder(root->left, nums);
    nums.push_back(root->data);
    inorder(root->right, nums);
}

void preorder(TreeNode *root, vector<int> &nums)
{
    if (root == NULL)
        return;

    nums.push_back(root->data);
    preorder(root->left, nums);
    preorder(root->right, nums);
}

void postorder(TreeNode *root, vector<int> &nums)
{
    if (root == NULL)
        return;

    postorder(root->left, nums);
    postorder(root->right, nums);
    nums.push_back(root->data);
}

int height(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int lp = height(root->left);
    int rp = height(root->right);

    return 1 + max(lp, rp);
}

int checkBalanced(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int lp = checkBalanced(root->left);
    if (lp == -1)
        return -1; // left subtree is not balanced

    int rp = checkBalanced(root->right);
    if (rp == -1)
        return -1; // right subtree is not balanced

    if (abs(lp - rp) > 1)
        return -1;

    return 1 + max(lp, rp);
}

int main()
{
    // tell the number of nodes in the tree
    int n;
    cout << "Enter the number of nodes in the tree: ";
    cin >> n;

    // nodes will be stored in a level order manner
    vector<int> nodes(n);
    cout << "Enter the values of the nodes in level order (use -1 for null nodes):";

    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i];
    }

    TreeNode *root = buildTree(nodes);

    int choice;
    // menu for all the functions i had implemented
    while (true)
    {
        cout << "\nChoose an option:\n";
        cout << "1. Inorder Traversal\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Postorder Traversal\n";
        cout << "4. Height of the tree\n";
        cout << "5. check if the tree is balanced\n";
        cout << "6. Exit\n";

        // enter the operation you want to perform:
        cout << "Enter your choice:";
        cin >> choice;

        // get the inorder traversal
        if (choice == 1)
        {
            cout << "Inorder Traversal:";
            vector<int> inorderResult;
            inorder(root, inorderResult);

            for (int val : inorderResult)
            {
                cout << val << " ";
            }
            cout << endl;
        }

        // get the preorder traversal
        else if (choice == 2)
        {
            cout << "Preorder Traversal:";
            vector<int> PreorderResult;
            preorder(root, PreorderResult);

            for (int val : PreorderResult)
            {
                cout << val << " ";
            }
            cout << endl;
        }

        // get the postorder traversal
        else if (choice == 3)
        {
            cout << "Preorder Traversal:";
            vector<int> PostorderResult;
            postorder(root, PostorderResult);

            for (int val : PostorderResult)
            {
                cout << val << " ";
            }
            cout << endl;
        }

        // get the height of the tree
        else if (choice == 4)
        {
            int h = height(root);
            cout << "Height of the tree:" << h << endl;
        }

        // check if the tree is balanced
        else if (choice == 5)
        {
            bool isBalanced = checkBalanced(root) != -1;
            cout << (isBalanced ? "the tree is balanced" : "the tree is not balanced") << endl;
        }
        else if (choice == 6)
        {
            break;
        }
        else
        {
            cout << "Invalid Choice!:" << endl;
        }
    }

    return 0;
}

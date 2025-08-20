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

void Iterativeinorder(TreeNode *root)
{
    cout << "Inorder Traversal: ";
    // Inorder Traversal: Left, Root, Right
    if (root == NULL)
        return;

    stack<TreeNode *> st;
    TreeNode *cur = root;

    while (true)
    {
        if (cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            if (st.empty())
                break;

            cur = st.top();
            st.pop();
            cout << cur->data << " ";

            cur = cur->right;
        }
    }
}
void Iterativepreorder(TreeNode *root)
{
    if (root == NULL)
        return;

    stack<TreeNode *> st;
    st.push(root);

    cout << "Preorder Traversal: ";
    // Inorder Traversal: Root,Left, Right

    while (!st.empty())
    {
        TreeNode *cur = st.top();
        st.pop();

        cout << cur->data << " ";

        if (cur->right)
            st.push(cur->right);
        if (cur->left)
            st.push(cur->left);
    }
}

// using  2stacks
void Iterativepostorder(TreeNode *root)
{
    if (root == NULL)
        return;

    stack<TreeNode *> st1, st2;
    st1.push(root);

    cout << "Postorder Traversal Using 2 Stacks: ";
    // Postorder Traversal: Left, Right, Root

    while (!st1.empty())
    {

        TreeNode *temp = st1.top();
        st1.pop();

        st2.push(temp);

        if (temp->left)
        {
            st1.push(temp->left);
        }
        if (temp->right)
        {
            st1.push(temp->right);
        }
    }

    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

void postorder1Stack(TreeNode *root)
{
    if (root == NULL)
        return;

    stack<TreeNode *> st;
    TreeNode *cur = root;

    cout << "Postorder Traversal using 1 stack: ";
    // Postorder Traversal: Left, Right, Root
    while (cur != NULL || !st.empty())
    {
        if (cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            TreeNode *temp = st.top();
            temp = temp->right;

            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                cout << temp->data << " ";

                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                }
            }
            else
            {
                cur = temp;
            }
        }
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Iterativeinorder(root);
    cout << endl;
    Iterativepreorder(root);
    cout << endl;
    Iterativepostorder(root);
    cout << endl;
    postorder1Stack(root);

    return 0;
}
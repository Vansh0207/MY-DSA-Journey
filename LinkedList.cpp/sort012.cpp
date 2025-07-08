// Sort a Linked List containing 0's 1's and 2's
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convert2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node *sort012(Node *head)
{
    Node *temp = head;
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            cnt0++;
        }
        else if (temp->data == 1)
        {
            cnt1++;
        }
        else
        {
            cnt2++;
        }
        temp = temp->next;
    }
    // Add code here
    Node *temp1 = head;

    while (temp1 != NULL)
    {
        if (cnt0)
        {
            temp1->data = 0;
            cnt0--;
        }
        else if (cnt1)
        {
            temp1->data = 1;
            cnt1--;
        }
        else
        {
            temp1->data = 2;
            cnt2--;
        }
        temp1 = temp1->next;
    }
    return head;
}
int main()
{
    vector<int> arr = {2, 1, 0, 0, 1, 2, 1, 1, 2, 0, 0, 0, 1, 1, 2, 2, 1};

    Node *head = convert2LL(arr);
    head = sort012(head);

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}
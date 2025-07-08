#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1)
    {
        data = data1;
        next = NULL;
    }
};

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    // push
    void push(int x)
    {
        Node *temp = new Node(x);

        temp->next = top;
        top = temp;
        cout << "Pushed into the Stack" << endl;
    }

    Node *pop()
    {
        if (top == NULL)
            return top;
        Node *poppedEl = top;

        top = top->next;
        delete (top);

        return poppedEl;
    }
};

int main()
{
    Stack q;

    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.pop()->data << endl;

    return 0;
}
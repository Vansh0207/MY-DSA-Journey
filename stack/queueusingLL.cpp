#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

class Queue
{
public:
    int size = 0;
    Node *front;
    Node *rear;

    Queue()
    {
        front = rear = nullptr;
        size = 0;
    }

    void enqueue(int x)
    {
        Node *temp = new Node(x);

        if (temp == nullptr)
        {
            cout << "heap exhausted" << endl;
        }
        else
        {
            if (front == nullptr)
            {
                front = temp;
                rear = temp;
            }
            else
            {
                rear->next = temp;
                rear = temp;
            }
        }
        size++;
    }

    int dequeue()
    {
        if (front == nullptr)
        {
            cout << "queue is empty" << endl;
        }
        else
        {
            int data1 = front->data;
            Node *temp = front;

            front = front->next;
            delete (temp);
            size--;
            return data1;
        }
    }

    int Size()
    {
        return size;
    }
};

int main()
{
    Queue q;

    q.enqueue(9);
    q.enqueue(1);
    q.enqueue(3);
    q.enqueue(2);
    cout << q.Size() << endl;

    return 0;
}
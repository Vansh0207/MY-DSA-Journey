#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int start, end, currsize, maxSize;

public:
    Queue()
    {
        arr = new int[16];
        start = -1;
        end = -1;
        currsize = 0;
    }
    Queue(int maxSize)
    {
        (*this).maxSize = maxSize;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currsize = 0;
    }

    void push(int x)
    {
        if (currsize == maxSize)
        {
            cout << "queue is full" << endl;
            exit(1);
        }

        if (end == -1)
        {
            start = 0;
            end = 0;
        }
        else
        {
            end = (end + 1) % maxSize;
        }
        arr[end] = x;
        currsize++;
    }

    int pop()
    {
        if (currsize == 0)
        {
            cout << "queue is empty" << endl;
            exit(1);
        }
        int popped = arr[start];

        if (start == end)
        {
            start = -1;
            end = -1;
        }
        else
        {
            start = (start + 1) % maxSize;
        }
        currsize--;

        return popped;
    }
    int Top()
    {
        return arr[start];
    }
    int Size()
    {
        return currsize;
    }
};

int main()
{
    Queue q(6);
    q.push(5);
    q.push(7);
    q.push(10);
    q.push(21);
    cout << q.pop() << endl;
    cout << q.Top() << endl;
    cout << q.Size() << endl;

    return 0;
}

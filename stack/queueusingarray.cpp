#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
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
            cout << "Queue Overflow" << endl;
            return;
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
        if (start == -1)
        {
            cout << "Queue is Empty" << endl;
        }
        int el = arr[start];

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

        return el;
    }
};

int main()
{
    Queue q(10);
    q.push(50);
    q.push(40);
    q.push(30);
    q.push(20);
    q.push(1);

    cout << q.pop() << endl;
    cout << q.pop() << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int size;
    int top;
    int *arr;

public:
    Stack()
    {
        top = -1;
        size = 1000;
        arr = new int[size];
    }

    void push(int x)
    {
        // element to be pushed is x
        top++;
        arr[top] = x;
    }

    int pop()
    {
        int el = arr[top];
        top--;
        return el;
    }
    int Size()
    {
        return top + 1;
    }
    int Top()
    {
        return arr[top];
    }
};

int main()
{
    Stack s;
    s.push(3);
    s.push(2);
    s.push(1);
    cout << s.pop() << endl;
    cout << s.Size() << endl;
    cout << s.Top() << endl;
    return 0;
}
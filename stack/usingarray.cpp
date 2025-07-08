#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int top;
    int *arr;
    int size;

public:
    Stack()
    {
        top = -1;
        size = 10;
        arr = new int[size];
    }

    void push(int x)
    {
        top++;
        arr[top] = x;
    }
    int pop()
    {
        int el = arr[top];
        top--;
        return el;
    }
    int Top()
    {
        return arr[top];
    }
    int Size()
    {
        return top + 1;
    }
};

int main()
{
    Stack s;
    s.push(5);
    s.push(3);
    s.push(10);
    s.pop();
    s.Size();

    cout << s.Size();

    return 0;
}
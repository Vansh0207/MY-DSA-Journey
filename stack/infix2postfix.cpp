#include <bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if (c == '^')
        return 3;

    else if (c == '/' || c == '*')
        return 2;

    else if (c == '+' || c == '-')
        return 1;

    else
        return -1;
}

void infix2postfix(string inf)
{
    stack<char> st;
    string s = "";

    for (int i = 0; i < inf.size(); i++)
    {
        char c = inf[i];

        // if the scanned character is an operand
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        {
            s += c;
        }

        // if the scanned character is an opening parentheses
        else if (c == '(')
        {
            st.push(c);
        }

        // if the scanned character is a closing parentheses
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                s += st.top();
                st.pop();
            }
            st.pop();
        }

        // if the scanned character is an operator
        else
        {
            while (!st.empty() && precedence(c) <= precedence(st.top()))
            {
                s += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // pop all out the elements from the stack
    while (!st.empty())
    {
        s += st.top();
        st.pop();
    }

    cout << s << endl;
}

int main()
{
    string s = "((A+B)*(C+E))";
    cout << s << endl;
    infix2postfix(s);

    return 0;
}

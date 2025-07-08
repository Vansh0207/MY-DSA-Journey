#include <bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infix2postfix(string s)
{
    stack<char> st;
    string res = "";

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        // if it is an operand
        if (isalnum(c))
        {
            res += c;
        }
        // if it is an opening parentheses
        else if (c == '(')
        {
            st.push(c);
        }
        // if it is an closing parentheses
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }

        // if it is an operator
        else
        {
            if (c == '^')
            {
                while (!st.empty() && precedence(c) <= precedence(st.top()))
                {
                    res += st.top();
                    st.pop();
                }
            }
            else
            {
                while (!st.empty() && precedence(c) < precedence(st.top()))
                {
                    res += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}

string infix2prefix(string s)
{
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            s[i] = ')';

        else if (s[i] == ')')
            s[i] = '(';
    }

    string str = infix2postfix(s);

    reverse(str.begin(), str.end());

    return str;
}

int main()
{
    string expr;
    cout << "Enter infix expression: ";
    getline(cin, expr);
    // remove spaces if any
    expr.erase(remove_if(expr.begin(), expr.end(), ::isspace), expr.end());

    string prefix = infix2prefix(expr);
    cout << "Prefix: " << prefix << "\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

string prefix2postfix(string s)
{
    char c;
    stack<string> st;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        c = s[i];

        // if it is an operand
        if (isalnum(c))
        {
            st.push(string(1, c));
        }

        // if it is an operator
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            string a = t1 + t2 + c;
            st.push(a);
        }
    }
    return st.top();
}

int main()
{
    string s = "/-AB*+DEF";
    string a = prefix2postfix(s);

    cout << a << endl;
    return 0;
}
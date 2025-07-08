#include <bits/stdc++.h>
using namespace std;

string prefix2infix(string s)
{
    stack<string> st;
    char c;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        c = s[i];
        // if it is operand
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

            string a = '(' + t1 + c + t2 + ')';
            st.push(a);
        }
    }
    return st.top();
}

int main()
{
    string a = "*+PQ-MN";
    string res = prefix2infix(a);

    cout << res << endl;
    return 0;
}
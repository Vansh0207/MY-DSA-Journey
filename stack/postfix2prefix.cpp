#include <bits/stdc++.h>
using namespace std;

string postfix2prefix(string s)
{
    char c;
    stack<string> st;

    for (int i = 0; i < s.size(); i++)
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

            string a = c + t2 + t1;
            st.push(a);
        }
    }
    return st.top();
}

int main()
{
    string s = "AB-DE+F*/";
    string a = postfix2prefix(s);

    cout << a << endl;
    return 0;
}
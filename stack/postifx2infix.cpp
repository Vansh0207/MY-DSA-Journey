#include <bits/stdc++.h>
using namespace std;

string postfix2infix(string s)
{
    // AB-DE+F*/
    char c;
    stack<string> st;

    for (int i = 0; i < s.size(); i++)
    {
        c = s[i];

        // checking if the character is an operand
        if (isalnum(c))
        {
            st.push(string(1, c));
        }
        // if the character is an operator
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            string a = '(' + t2 + c + t1 + ')';

            st.push(a);
        }
    }

    return st.top();
}

int main()
{
    string a = "AB-DE+F*/";
    string b = postfix2infix(a);

    cout << b << endl;
    return 0;
}
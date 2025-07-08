#include <bits/stdc++.h>
using namespace std;

// Brute Force
string RemoveP(string s)
{
    int count = 0;
    string st;
    int start = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            count++;
        else
            count--;

        if (count == 0)
        {
            st += s.substr(start + 1, i - start - 1);
            start = i + 1;
        }
    }
    return st;
}

// OPTIMAL APPROACH
string RemParentheses(string s)
{
    int count = 0;
    string st = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            if (count > 0)
            {
                st += s[i];
            }
            count++;
        }
        else
        {
            count--;

            if (count > 0)
            {
                st += s[i];
            }
        }
    }
    return st;
}

int main()
{
    string st = "(()())(())";

    // string ans = RemoveP(st);
    string a = RemParentheses(st);

    cout << a << endl;
    return 0;
}
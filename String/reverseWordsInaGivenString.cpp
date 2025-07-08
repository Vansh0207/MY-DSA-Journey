#include <bits/stdc++.h>
using namespace std;

// Input: s = "the sky is blue"
// Output: "blue is sky the"

// Brute Force Approach
string reverseWords(string s)
{
    int n = s.size();
    string st = "";
    vector<string> ans;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            if (!st.empty())
            {
                ans.push_back(st);
                st = "";
            }
        }
        else
        {
            st += s[i];
        }
    }

    if (!st.empty())
    {
        ans.push_back(st);
    }

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }

    reverse(ans.begin(), ans.end());

    string res = "";

    for (int i = 0; i < ans.size(); i++)
    {
        res += ans[i];

        if (i < ans.size() - 1)
            res += " ";
    }

    return res;
}

// OPTIMAL APPROACH
string optimalReverseWords(string s)
{
    reverse(s.begin(), s.end());

    int n = s.size();
    int i = 0, left = 0, right = 0;

    while (i < n)
    {
        // ignore and keep track of whitespace
        while (i < n && s[i] == ' ')
            i++;

        if (i == n)
            break;

        while (i < n && s[i] != ' ')
        {
            s[right] = s[i];
            right++;
            i++;
        }

        reverse(s.begin() + left, s.begin() + right);

        s[right] = ' ';
        right++;
        left = right;
        i++;
    }
    s.resize(right - 1);

    return s;
}

int main()
{
    string s = "the sky is blue";

    string r = reverseWords(s);

    cout << r << endl;

    return 0;
}
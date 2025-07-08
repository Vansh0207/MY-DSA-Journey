#include <bits/stdc++.h>
using namespace std;

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// BRUTE FORCE CODE
int LSWRC(string s)
{
    int maxlen = 0;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> mpp;

        int j;
        for (j = i; j < n; j++)
        {
            if (mpp.find(s[j]) != mpp.end())
            {
                break;
            }
            mpp[s[j]]++;
        }
        maxlen = max(maxlen, j - i);
    }
    return maxlen;
}

// OPTIMAL APPROACH
int Optimal(string s)
{
    unordered_map<char, int> mpp;
    int maxlen = 0;

    int i = 0;
    for (int j = 0; j < s.size(); j++)
    {
        // if its already present in map
        if (mpp.find(s[j]) != mpp.end())
        {
            i = max(i, mpp[s[j]] + 1);
        }
        mpp[s[j]] = j;
        maxlen = max(maxlen, j - i + 1);
    }
}

int main()
{
    string s = "abcabcbb";

    // int st = LSWRC(s);
    int st = Optimal(s);

    cout << st << endl;

    return 0;
}
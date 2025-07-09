#include <bits/stdc++.h>
using namespace std;

// Brute Force O(N^2)
int NoOfSubstrings(string s)
{
    int count = 0;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> mpp;

        for (int j = i; j < n; j++)
        {
            mpp[s[j]]++;

            if (mpp.size() == 3)
            {
                // count++;
                // instead of counting everytime we know if we get valid string then above that all the strings will be valid.
                // so just add all of them at once and break from loop.
                count = count + (n - j);
                break;
            }
        }
    }
    return count;
}

// Optimal Solution
int Optimal(string s)
{
    vector<int> lastSeen = {-1, -1, -1};
    int count = 0;

    for (int i = 0; i < s.size(); i++)
    {
        lastSeen[s[i] - 'a'] = i;

        if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
        {
            count += (1 + min(min(lastSeen[0], lastSeen[1]), lastSeen[2]));
        }
    }
    return count;
}

int main()
{
    string s = "abcabc";

    // int ans = NoOfSubstrings(s);
    int ans = Optimal(s);

    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achieve this answer too.

int BruteForce(string s, int k)
{
    int maxlen = 0;
    int n = s.size();

    // try out all the combinations
    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> mpp;
        int maxf = 0;
        for (int j = i; j < n; j++)
        {
            // storing frequency in map
            mpp[s[j] - 'A']++;
            // calculating the maximum frequency as we will avoid replace the element which is in majority and its the core intuition for brute force code
            maxf = max(maxf, mpp[s[j] - 'A']);

            int change = (j - i + 1) - maxf;

            // calculating maximum length till change is less than zero
            if (change <= k)
            {
                maxlen = max(maxlen, j - i + 1);
            }
            // the moment change variable is greater than k we will break from j loop.
            else
            {
                break;
            }
        }
    }
    return maxlen;
}

// Sliding window integrated with two pointer approach
int OptimalApproach(string s, int k)
{
    unordered_map<char, int> mpp;
    int l = 0, r = 0;
    int maxf = 0, maxlen = 0;

    while (r < s.size())
    {
        mpp[s[r]]++;
        maxf = max(maxf, mpp[s[r]]);

        // shrink the window every iteration when its not a valid string
        if (((r - l + 1) - maxf) > k)
        {
            mpp[s[l]]--;
            l++;
        }
        maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}

int main()
{
    // string s = "AABABBA";
    // int k = 2;
    string s = "ABAB";
    int k = 2;

    // int ans = BruteForce(s, k);
    int ans = OptimalApproach(s, k);

    cout << ans << endl;

    return 0;
}

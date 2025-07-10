#include <bits/stdc++.h>
using namespace std;

// s=aaabbcccc  and k=2   k denotes the no of distinct elements should be in the substring.
// output 6         question is to find the longest substring with k no of distinct elements.

int BruteForce(string s, int k)
{
    int n = s.size();
    int maxlen = 0;
    // trying out all possible subarrays
    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> mpp;

        for (int j = i; j < n; j++)
        {
            mpp[s[j]]++;

            if (mpp.size() > k)
            {
                break;
            }
            maxlen = max(maxlen, j - i + 1);
        }
    }
    return maxlen;
}
int BetterApproach(string s, int k)
{
    int l = 0, r = 0;
    int maxlen = 0;
    unordered_map<int, int> mpp;

    while (r < s.size())
    {
        mpp[s[r]]++;

        // if its not a valid string
        // If we dont encounter a valid string we shrink the window until i get a valid string.
        while (mpp.size() > k)
        {
            mpp[s[l]]--;
            // if frequency turns 0 then just remove from map as it is no more part of subarray
            if (mpp[s[l]] == 0)
                mpp.erase(s[l]);
            l++;
        }
        maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}

// almost same approach as better one.   Better O(2N) Optimal O(N)
int OptimalApproach(string s, int k)
{
    int l = 0, r = 0;
    int maxlen = 0;
    unordered_map<int, int> mpp;
    // if we dont encounter a valid string we have to shrink the window by one
    while (r < s.size())
    {
        mpp[s[r]]++;

        if (mpp.size() > k)
        {
            mpp[s[l]]--;
            // if the frequency of l element decrease to zero remove the value from map as it is of no use.
            if (mpp[s[l]] == 0)
                mpp.erase(s[l]);
            // move forward the l pointer to shrink the window
            l++;
        }
        maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}

int main()
{
    string s;
    cout << "Enter a String:";
    getline(cin, s);

    cout << "Enter K:";
    int k;
    cin >> k;

    // int ans = BruteForce(s, k);
    int ans = BetterApproach(s, k);
    cout << ans << endl;

    return 0;
}
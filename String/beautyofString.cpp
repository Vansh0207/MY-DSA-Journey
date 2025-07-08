#include <bits/stdc++.h>
using namespace std;

int beautyBrute(string s)
{
    int n = s.size();
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            unordered_map<int, int> mpp;

            for (int k = i; k <= j; k++)
            {
                mpp[s[k]]++;
            }

            int mini = INT_MAX;
            int maxi = 0;

            for (auto it : mpp)
            {
                mini = min(mini, it.second);
                maxi = max(maxi, it.second);
            }
            sum += (maxi - mini);
        }
    }

    return sum;
}

int main()
{
    string s = "aabcbaa";

    int a = beautyBrute(s);

    cout << a << endl;

    return 0;
}
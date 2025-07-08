#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &arr, int k)
{
    int n = arr.size();
    // two pointer approach
    int l = 0;
    int r = 0;
    int sum = arr[0];

    int maxlen = 0;

    while (r < n)
    {
        while (l < r && sum > k)
        {
            sum -= arr[l];
            l++;
        }

        if (sum == k)
        {
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
        if (r < n)
            sum += arr[r];
    }
    return maxlen;
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 3, 3};
    int k = 6;
    int a = longestSubarray(arr, k);

    cout << a << endl;

    return 0;
}
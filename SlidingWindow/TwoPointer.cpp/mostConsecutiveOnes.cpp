#include <bits/stdc++.h>
using namespace std;

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

int MCO(vector<int> &nums, int k)
{
    int n = nums.size();
    int maxlen = 0;
    int zerocnt;

    for (int i = 0; i < n; i++)
    {
        zerocnt = 0;
        for (int j = i; j < n; j++)
        {
            if (nums[j] == 0)
                zerocnt++;

            if (zerocnt > k)
                break;

            maxlen = max(maxlen, j - i + 1);
        }
    }
    return maxlen;
}

int main()
{
    vector<int> nums = {1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1};
    int k = 2;

    int maxi = MCO(nums, k);

    cout << maxi << endl;
    return 0;
}
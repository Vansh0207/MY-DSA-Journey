#include <bits/stdc++.h>
using namespace std;

// {1, 2, 2, 4, 6, 8, 9};

int upperbound(int low, int high, vector<int> &nums, int x)
{
    int ans = nums.size();
    if (low > high)
        return -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2, 4, 6, 8, 9};
    int x = 7;

    int a = upperbound(0, nums.size() - 1, nums, x);

    cout << a << endl;

    return 0;
}
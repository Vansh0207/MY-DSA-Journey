#include <bits/stdc++.h>
using namespace std;

int lowerbound(int low, int high, vector<int> &nums, int x)
{
    if (low > high)
        return -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= x)
            high = mid - 1;

        else
            low = mid + 1;
    }

    return low;
}

int main()
{
    vector<int> nums = {1, 2, 2, 4, 6, 8, 9};
    int x = 3;

    int a = lowerbound(0, nums.size() - 1, nums, x);

    cout << a << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int countBinarySubarrayWithSum(vector<int> &nums, int goal)
{
    int l = 0, r = 0;
    int sum = 0, cnt = 0;

    if (goal < 0)
        return 0;

    while (r < nums.size())
    {
        sum += nums[r];

        while (sum > goal)
        {
            sum = sum - nums[l];
            l++;
        }

        cnt += (r - l + 1);
        r++;
    }

    return cnt;
}

int main()
{
    vector<int> nums = {1, 0, 0, 1, 1, 0};
    int goal = 2;

    int a = countBinarySubarrayWithSum(nums, goal) - countBinarySubarrayWithSum(nums, goal - 1);

    cout << a << endl;
    return 0;
}
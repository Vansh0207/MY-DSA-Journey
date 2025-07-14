#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int tar)
{
    unordered_map<int, int> mpp;
    //            sum,index
    // nums = [2, 7, 11, 15], target = 9
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        int rem = tar - sum;

        if (mpp.find(rem) != mpp.end())
        {
            return {i, mpp[rem]};
        }
        mpp[sum] = i;
    }
    return {-1, -1};
}

int main()
{
    vector<int> arr = {2, 7, 11, 15};
    int k = 9;

    vector<int> ans = twoSum(arr, k);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
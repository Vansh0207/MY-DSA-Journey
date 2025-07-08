#include <bits/stdc++.h>
using namespace std;
// BRUTE FORCE USING 2 LOOPS
vector<vector<int>> mergeOverlappingInterval(vector<vector<int>> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        int start = nums[i][0];
        int end = nums[i][1];

        // if end(iterated element) is already present in the ans array
        if (!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (end >= nums[j][0])
            {
                end = max(end, nums[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

int main()
{
    vector<vector<int>> nums = {{1, 3}, {2, 4}, {2, 6}, {8, 9}, {8, 10}, {9, 11}, {15, 18}, {16, 17}};

    vector<vector<int>> ans = mergeOverlappingInterval(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
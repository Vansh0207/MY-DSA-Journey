#include <bits/stdc++.h>
using namespace std;

// 1. Input: candidates = [2,3,6,7], target = 7
//  Output: [[2,2,3],[7]]
//  Explanation:
//  2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
//  7 is a candidate, and 7 = 7.
//  These are the only two combinations.
void combinationSum(int idx, int n, int target, vector<int> nums, vector<int> temp)
{
    // Base Case: if ind reaches end of array and target is zero then return the res else return nothing
    if (idx == n)
    {
        if (target == 0)
        {
            for (auto it : temp)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    // if element exceeds the target then there is no point of taking that element
    if (nums[idx] <= target)
    {
        temp.push_back(nums[idx]);
        combinationSum(idx, n, target - nums[idx], nums, temp);
        temp.pop_back();
    }
    // dont take the element and then call recursively
    combinationSum(idx + 1, n, target, nums, temp);
}

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output:
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.
void combinationSum2(int idx, int n, int target, vector<int> &nums, vector<int> &temp)
{
    if (target == 0)
    {
        for (auto it : temp)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        // if its the first unique element to be entered no one can stop
        // but if its not then we allow to enter the duplicate
        if (i > idx && nums[i] == nums[i - 1])
            continue;
        if (target < nums[i])
            break;
        ;

        temp.push_back(nums[i]);
        combinationSum2(i + 1, n, target - nums[i], nums, temp);
        temp.pop_back();
    }
}
int main()
{
    vector<int> temp;
    int n;
    int target;

    cout << "Target:";
    cin >> target;

    cout << "No of elements:";
    cin >> n;

    vector<int> arr(n);

    cout << "enter array elements:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    // combinationSum(0, n, target, arr, temp);
    combinationSum2(0, n, target, arr, temp);

    return 0;
}
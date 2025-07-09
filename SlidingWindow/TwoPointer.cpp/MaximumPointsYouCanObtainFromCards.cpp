#include <bits/stdc++.h>
using namespace std;

// Input: cardPoints = [1,2,3,4,5,6,1], k = 3
// Output: 12
// Explanation: After the first step, your score will always be 1.
// However, choosing the rightmost card first will maximize your total score.
// The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

int Optimal(vector<int> &nums, int k)
{
    int lsum = 0, rsum = 0;
    int maxsum = 0;

    // calculating the lsum and then we will start diminishing lsum
    for (int i = 0; i < k; i++)
        lsum += nums[i];
    maxsum = lsum;

    int right = nums.size() - 1;
    // diminshing lsum and adding elements from right side and checking for maximum sum can be attianed
    for (int i = k - 1; i >= 0; i--)
    {
        lsum = lsum - nums[i];
        rsum = rsum + nums[right];
        right--;
        maxsum = max(maxsum, (lsum + rsum));
    }
    return maxsum;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    int ans = Optimal(nums, k);

    cout << ans << endl;
    return 0;
}
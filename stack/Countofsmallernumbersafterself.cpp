#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH
vector<int> countSmallerBrute(vector<int> &nums)
{
    int N = nums.size();
    vector<int> res(N, -1);

    for (int i = N - 1; i >= 0; i--)
    {
        int count = 0;

        for (int j = i; j < N; j++)
        {
            if (nums[i] > nums[j])
            {
                count++;
            }
        }
        res[i] = count;
    }
    return res;
}

int main()
{
    vector<int> nums = {5, 2, 6, 1}; // Output Should be {2,1,1,0} we have to count smaller numbers after self

    vector<int> arr = countSmallerBrute(nums);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int FruitInBasketBrute(vector<int> &nums)
{
    int maxlen = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> mpp;

        for (int j = i; j < n; j++)
        {
            mpp[nums[j]]++;

            if (mpp.size() > 2)
            {
                break;
            }

            maxlen = max(maxlen, j - i + 1);
        }
    }
    return maxlen;
}

int FruitInBasketOptimal(vector<int> &nums)
{
    int maxlen = 0;
    int n = nums.size();
    unordered_map<int, int> mpp;

    int i = 0;

    for (int j = 0; j < n; j++)
    {
        mpp[nums[j]]++;

        if (mpp.size() > 2)
        {
            mpp[nums[i]]--;
            if (mpp[nums[i]] == 0)
            {
                mpp.erase(nums[i]);
            }
            i++;
        }
        maxlen = max(maxlen, j - i + 1);
    }
    return maxlen;
}

int main()
{
    vector<int> nums = {1, 2, 3, 2, 2};

    // int a = FruitInBasketBrute(nums);
    int a = FruitInBasketOptimal(nums);

    cout << a << endl;
    return 0;
}
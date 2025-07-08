#include <bits/stdc++.h>
using namespace std;

vector<int> previousSmallestElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = 0; i < nums.size(); i++)
    {
        while (!st.empty() && nums[st.top()] > nums[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            res[i] = st.top();
        }
        st.push(i);
    }
    return res;
}

int main()
{
    vector<int> nums = {2, 3, 1, 4, 2};

    vector<int> arr = previousSmallestElement(nums);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
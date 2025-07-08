#include <bits/stdc++.h>
using namespace std;

// array={2,1,5,6,2,3}
vector<int> pse(vector<int> &nums, int n)
{
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
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

vector<int> nse(vector<int> &nums, int n)
{
    vector<int> res(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] > nums[i])
        {
            st.pop();
        }
        if (st.empty())
            res[i] = n;
        else
            res[i] = st.top();
        st.push(i);
    }
    return res;
}

int largestRectangle(vector<int> &nums)
{
    int n = nums.size();
    vector<int> pse1(n);
    vector<int> nse1(n);
    int maxi = INT_MIN;

    pse1 = pse(nums, n);
    nse1 = nse(nums, n);

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, (nse1[i] - pse1[i] - 1) * nums[i]);
    }
    return maxi;
}

int main()
{
    vector<int> nums = {2, 1, 5, 6, 2, 3};

    int area = largestRectangle(nums);

    cout << area << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &nums, int n)
{
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
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
    int n = 5;
    vector<int> arr = nextSmallerElement(nums, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
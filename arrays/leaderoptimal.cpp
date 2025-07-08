#include <bits/stdc++.h>
using namespace std;

vector<int> leaderoptimal(vector<int> &arr)
{
    vector<int> ans;
    int n = arr.size();
    // last element of the array is always the leader element
    ans.push_back(arr[n - 1]);

    int maxi = arr[n - 1];

    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i] > maxi)
        {
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {10, 22, 12, 3, 0, 6};
    vector<int> res = leaderoptimal(arr);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
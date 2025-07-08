#include <bits/stdc++.h>
using namespace std;

// leader elements in an array
vector<int> leaderarr(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        bool flag = true;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {10, 22, 12, 3, 0, 6};

    vector<int> res = leaderarr(arr);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}
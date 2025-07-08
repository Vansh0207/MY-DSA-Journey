#include <bits/stdc++.h>
using namespace std;

int findsingle(vector<int> &arr)
{
    unordered_map<int, int> mpp;

    for (int i = 0; i < arr.size(); i++)
    {
        mpp[arr[i]]++;
    }
    for (auto [it, itr] : mpp)
    {
        if (itr == 1)
        {
            return it;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1};

    int a = findsingle(arr);
    cout << a << endl;
    return 0;
}
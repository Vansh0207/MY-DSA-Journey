#include <bits/stdc++.h>
using namespace std;

void subSequence(int s, vector<int> &arr, int idx, int sum, vector<int> &a, int n)
{
    if (idx == n)
    {
        if (s == sum)
        {
            for (auto it : a)
                cout << it << " ";
            cout << endl;
        }
        return;
    }

    a.push_back(arr[idx]);

    s += arr[idx];
    subSequence(s, arr, idx + 1, sum, a, n);

    a.pop_back();

    s -= arr[idx];
    subSequence(s, arr, idx + 1, sum, a, n);
}

int main()
{
    int n = 6;
    int idx = 0;
    vector<int> arr = {5, 2, 3, 10, 6, 8};
    int sum = 10;
    vector<int> a;

    subSequence(0, arr, 0, sum, a, n);

    return 0;
}
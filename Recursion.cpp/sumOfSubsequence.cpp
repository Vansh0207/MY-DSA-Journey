#include <bits/stdc++.h>
using namespace std;

void subSequence(int s, vector<int> &arr, int idx, int sum, vector<int> &a, int n)
{
    // base case is anytime we reach the end of array
    if (idx == n)
    {
        // nested if condition if we found sum equal to target
        if (s == sum)
        {
            for (auto it : a)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    // take and push the current element in the array
    a.push_back(arr[idx]);
    // call the function for next recursice call
    subSequence(s + arr[idx], arr, idx + 1, sum, a, n);

    // pop the last element means don't take and move to the next recursive call
    a.pop_back();
    // call the function
    subSequence(s, arr, idx + 1, sum, a, n);
}

// Check if there exists a subsequence with sum K for example arr={1,2,1} sum=2
bool checkSum(int s, int idx, vector<int> &arr, int sum, int n)
{
    // base condition
    if (idx == n)
    {
        if (s == sum)
        {
            return true;
        }
        return false;
    }

    // take
    if (checkSum(s + arr[idx], idx + 1, arr, sum, n) == true)
        return true;
    // not take
    if (checkSum(s, idx + 1, arr, sum, n) == true)
        return true;

    return false;
}

// Count all subsequences with sum K {1,2,1} s=2  count=2
int counting(int s, int idx, vector<int> &arr, int sum, int n)
{
    if (idx == n)
    {
        if (sum == s)
        {
            return 1;
        }
        return 0;
    }

    // take
    int l = counting(s + arr[idx], idx + 1, arr, sum, n);
    // not take
    int r = counting(s, idx + 1, arr, sum, n);

    return l + r;
}

int main()
{
    int n = 6;
    int idx = 0;
    vector<int> arr = {5, 2, 3, 10, 6, 8};
    int sum = 10;
    vector<int> a;

    // print the subsequences containing sum equals k
    subSequence(0, arr, 0, sum, a, n);

    // check is subsequence of given sum exist or not
    if (checkSum(0, 0, arr, sum, n))
        cout << "True" << endl;
    else
        cout << "false" << endl;

    // counting number of subsequence sum equal to k
    int b = counting(0, 0, arr, sum, n);
    cout << b << endl;

    return 0;
}
// Complexity is somewhere about O(2^n x n)

#include <bits/stdc++.h>
using namespace std;

void subSequence(int idx, vector<int> arr, vector<int> ans)
{
    int n = arr.size();

    if (idx >= n)
    {
        for (auto it : ans)
        { // Loop for printing the subsequences is taking O(n).
            cout << it << " ";
        }

        if (ans.size() == 0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }

    ans.push_back(arr[idx]);        // Whole recursion is taking O(2^n).Try making its recursion tree and you will understand.
    subSequence(idx + 1, arr, ans); // Take
    ans.pop_back();
    subSequence(idx + 1, arr, ans); // Not Take
}
// Final Complexity   O(2^n x n)
int main()
{

    vector<int> arr = {5, 2, 3, 10, 6, 8};

    cout << "enter the index:";
    vector<int> ans;

    subSequence(0, arr, ans);

    return 0;
}
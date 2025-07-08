#include <bits/stdc++.h>
using namespace std;

bool linearsearch(vector<int> &arr, int num)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == num)
        {
            return true;
        }
    }
    return false;
}

int longest(vector<int> &arr)
{
    // storing the longest sequence
    int longi = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        int cnt = 1;
        int x = arr[i];
        while (linearsearch(arr, x + 1) == true)
        {
            x += 1;
            cnt++;
        }
        longi = max(cnt, longi);
    }
    return longi;
}
int main()
{
    vector<int> arr = {100, 4, 200, 1, 3, 2};
    int cnt = longest(arr);

    cout << cnt << endl;
}
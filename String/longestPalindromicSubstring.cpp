#include <bits/stdc++.h>
using namespace std;

bool ispalindrome(string s, int l, int r)
{
    while (l < r)
    {
        if (s[l] != s[r])
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

string longestPalindromic(string s)
{
    int maxi = 0;
    int left = 0;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (ispalindrome(s, i, j) && (j - i + 1) > maxi)
            {
                maxi = j - i + 1;
                left = i;
            }
        }
    }
    return s.substr(left, maxi);
}

int main()
{
    string s = "abaxyzzyxf";

    string st = longestPalindromic(s);

    cout << st << endl;

    return 0;
}
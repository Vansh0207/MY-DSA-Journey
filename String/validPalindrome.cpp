#include <bits/stdc++.h>
using namespace std;

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// using two pointer approach
bool OptimalValidPalindrome(string s)
{
    string st = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (isalnum(s[i]))
        {
            st += tolower(s[i]);
        }
    }

    int i = 0;
    int j = st.size() - 1;

    while (i < j)
    {
        if (st[i] != st[j])
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

// using 2 nested loops
bool BruteValidPalindrome(string s)
{
    string st = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (isalnum(s[i]))
        {
            st += tolower(s[i]);
        }
    }

    for (int i = 0; i < st.size(); i++)
    {
        if (st[i] != st[st.size() - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";

    // bool st = OptimalValidPalindrome(s);
    bool st = BruteValidPalindrome(s);

    cout << st << endl;

    return 0;
}
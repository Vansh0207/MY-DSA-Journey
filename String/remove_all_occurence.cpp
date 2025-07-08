#include <bits/stdc++.h>
using namespace std;

string removeOccurrences(string s, string part)
{

    // traversing and finding for the part to be removed
    while (s.find(part) != string::npos)
    {
        // find the index in s where part matches s
        size_t removeIndex = s.find(part);
        // apply substr function to construct new string
        s = s.erase(removeIndex, part.length());
    }
    return s;
}

int main()
{
    string s = "daabcbaabcbc";
    string part = "abc";
    string ans = removeOccurrences(s, part);
    cout << ans << endl;

    return 0;
}
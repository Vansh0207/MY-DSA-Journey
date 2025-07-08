#include <bits/stdc++.h>
using namespace std;

//{{2,3,4,5},{12,21,211,32},{212,22,145,100}}

void traversal()
{
    vector<vector<int>> nums = {{2, 3, 4, 5}, {12, 21, 211, 32}, {212, 22, 145, 100}};

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[i].size(); j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}

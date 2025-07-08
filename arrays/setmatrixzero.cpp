#include <bits/stdc++.h>
using namespace std;

// matrix = [[1,1,1],[1,0,1],[1,1,1]]                                          1,1,1      1,0,1
// we have to give the output  [[]]                                            1,0,1      0,0,0
//                                                                             1,1,1      1,0,1

// Brute Force
void setrow(int row, int col, vector<vector<int>> &nums, int i)
{
    for (int j = 0; j < col; j++)
    {
        if (nums[i][j] != 0)
        {
            nums[i][j] = -1;
        }
    }
}
void setcol(int row, int col, vector<vector<int>> &nums, int j)
{
    for (int i = 0; i < row; i++)
    {
        if (nums[i][j] != 0)
        {
            nums[i][j] = -1;
        }
    }
}

vector<vector<int>> setzero(vector<vector<int>> &nums, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (nums[i][j] == 0)
            {
                setrow(row, col, nums, i);
                setcol(row, col, nums, j);
            }
        }
    }

    // 1,-1,1
    //-1,0,-1
    // 1,-1,1

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (nums[i][j] == -1)
            {
                nums[i][j] = 0;
            }
        }
    }

    return nums;
}

// BETTER APPROACH
vector<vector<int>> betterapproach(vector<vector<int>> &nums, int row, int col)
{
    // using two arrays
}
int main()
{
    // vector<vector<int>> nums = {{1, 1, 1},
    //                             {1, 0, 1},
    //                             {1, 1, 1}};

    vector<vector<int>> nums = {{0, 1, 2, 0},
                                {3, 4, 5, 2},
                                {1, 3, 1, 5}};
    int row = 3;
    int col = 4;
    vector<vector<int>> ans = setzero(nums, row, col);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

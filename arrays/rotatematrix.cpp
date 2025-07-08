#include <bits/stdc++.h>
using namespace std;

//{
//{1,2,3,4}
//{5,6,7,8}
//{9,10,11,12}
//{13,14,15,16}
//}

// i have to return

//{
//{13,9,5,1}
//{14,10,6,2}
//{15,11,7,3}
//{16,12,8,4}
//}

vector<vector<int>> rotatematBrute(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> ans(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans[j][n - 1 - i] = matrix[i][j];
        }
    }
    return ans;
}

vector<vector<int>> rotatematOptimal(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // taking transpose the given matrix
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }

    return matrix;
}
int main()
{
    int n = 4;
    int m = 4;
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}; // 4x4 matrix

    vector<vector<int>> ans = rotatematOptimal(arr); // rotatematBrute(arr);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
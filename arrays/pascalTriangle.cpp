#include <bits/stdc++.h>
using namespace std;

// if someone asks which pascal's triangle element's will be present at which given row and column
int pascalTriangle(int numrows, int col)
{
    // i have to find factorial
    // then by finding combination nCr we will get the element and particular row and column of the pascal triangle
    int el = 1;

    for (int i = 0; i < col; i++)
    {
        el *= (numrows - i);
        el /= i + 1;
    }

    return el;
}

// if someone asks to print the whole row of that triangle for example if n=4 return 1,4,6,4,1
void pascalTraingle2(int numrows)
{
    int f = 1;
    cout << f << " ";

    for (int i = 1; i < numrows; i++)
    {
        f = f * (numrows - i);
        f /= i;
        cout << f << " ";
    }
}

// print whole pascals triangle
vector<long long> printPascal(int row)
{
    vector<long long> ans;
    long long f = 1;
    ans.push_back(f);

    for (int i = 1; i < row; i++)
    {
        f *= row - i;
        f /= i;
        ans.push_back(f);
    }
    return ans;
}

int main()
{
    int row, col;
    // Take input of rows
    cin >> row;
    // cin >> col;

    // int pt = pascalTriangle(row, col);
    // pascalTraingle2(row);

    // cout << pt << endl;

    vector<vector<long long>> res;

    for (int i = 1; i <= row; i++)
    {
        vector<long long> ans = printPascal(i);
        res.push_back(ans);
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
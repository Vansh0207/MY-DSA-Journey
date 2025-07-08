#include <bits/stdc++.h>
using namespace std;

// union of two arrays using a SET

void unionA(vector<int> &nums1, vector<int> &nums2)
{
    set<int> a;
    vector<int> temp;

    // storing element in the set
    // set stores distinct elements
    for (int i = 0; i < nums1.size(); i++)
    {
        a.insert(nums1[i]);
    }

    // storing element of array nums2
    for (int i = 0; i < nums2.size(); i++)
    {
        a.insert(nums2[i]);
    }

    // we have the distinct elements stored in the array
    // copying the elements in temp array and printing on screen
    for (auto it : a)
    {
        temp.push_back(it);
    }

    for (size_t i = 0; i < a.size(); i++)
    {
        /* code */
        cout << temp[i] << " ";
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {2, 3, 4, 5, 6};
    unionA(nums1, nums2);
    return 0;
}
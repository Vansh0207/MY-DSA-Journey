//Binary Search to Find X in Sorted Array

#include<bits/stdc++.h>
using namespace std;

//k= target value

int binarysearch(int nums[],int k,int n){
    int l=0;
    int r=n-1;
    while(l<=r){
        int mid=(l+r)/2;

        if(nums[mid]==k) return mid;       //if mid element is the target value

        else if(nums[mid]<k) l=mid+1;      //go to the right side of array

        else r=mid-1;                      //go to the left side of array
    }
    return  -1;                            //if target element is not present in the array
}

int main(){
    int nums[100];
    int size;

    int target;

    cout << "enter the size:";
    cin >> size;

    cout << "enter the target number:";
    cin >> target;

    //enter elements in sorted order

    for(int i=0;i<size;i++){
        cout << "enter the number:";
        cin >> nums[i];
    }

    cout<<binarysearch(nums,target,size);
    return 0;
}
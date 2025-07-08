//Find Peak Element
#include<bits/stdc++.h>
using namespace std;

int peak(int arr[100],int n){
    int low=1;
    int high=n-2;

    if(arr[0] > arr[1]) return 0;

    if(arr[n-1]>arr[n-2]) return n-1;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }
        else if(arr[mid]>arr[mid-1]){
            low=mid+1;
        }
        else if(arr[mid]>arr[mid+1]){
            high=mid-1;
        }
        else high=mid-1;
    }

}

int main(){
    int nums[100];
    int size;

    int target;

    cout << "enter the size:";
    cin >> size;

    //enter elements in sorted order

    for(int i=0;i<size;i++){
        cout << "enter the number:";
        cin >> nums[i];
    }

    cout<<peak(nums,size);
    return 0;
}
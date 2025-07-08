//Search in a Rotated Sorted Array

#include<bits/stdc++.h>
using namespace std;

int search(int arr[100], int n, int k)
{
    int low=0;
    int high=n-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]==k) return mid;

        //left side is sorted
        if(arr[low]<=arr[mid]){
            if(arr[low]<=k && k<=arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        //right side sorted
        else{
            if(arr[mid]<=k && arr[high]>=k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return -1;
}

int main(){
    int arr[100];
    int n;
    int k;

    cout << "enter the number of elements in array:";
    cin >> n;

    cout << "enter the target element:";
    cin >> k;

    cout << "enter the elements in sorted order\n";

    for(int i=0;i<n;i++){
        cout << "enter array element:";
        cin >> arr[i];
    }

   int nums=search(arr,n,k);
   cout <<"Index of Target element is : "<< nums;
    return 0;
}


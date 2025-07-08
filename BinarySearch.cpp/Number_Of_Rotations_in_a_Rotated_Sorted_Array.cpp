//Number of Rotations In a Rotated Sorted Array

#include<bits/stdc++.h>
using namespace std;

int NoOfRotations(int arr[100],int n){
    int low=0;
    int high=n-1;
    int ans=INT_MAX;
    int index=-1;

    while(low<=high){
        int mid=(low+high)/2;
        
        if(arr[low]<=arr[high]){
            if(arr[low]<ans){
                index=low;
                ans=arr[low];
            }
        }

        //left half is sorted
        if(arr[low]<=arr[mid]){
            if(arr[low]<ans){
                index=low;
                ans=arr[low];
            }
            low=mid+1;
        }
        else{
            if(arr[mid]<ans){
                index=mid;
                ans=arr[mid];
            }
            high=mid-1;
        }
    }
    return index;
}

int main(){
    int arr[100];
    int n;

    cout << "enter the number of elements in array:";
    cin >> n;

    cout << "enter the elements in sorted order\n";

    for(int i=0;i<n;i++){
        cout << "enter array element:";
        cin >> arr[i];
    }

   int nums=NoOfRotations(arr,n);
   cout <<" Number of Rotations : "<< nums;
    return 0;
}
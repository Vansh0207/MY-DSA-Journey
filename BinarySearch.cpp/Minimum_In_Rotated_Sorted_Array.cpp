//Minimum in Rotated Sorted Array  

#include<bits/stdc++.h>
using namespace std;

int mini(int arr[100],int n){
    int low=0;
    int high=n-1;
    int ans=INT_MAX;

    while(low<=high){
        int mid=(low+high)/2;

        if(arr[low]<=arr[mid] && arr[mid]<=arr[high]){
            ans=min(ans,arr[low]);
            break;
        }

        //left half is sorted
        if(arr[low]<=arr[mid]){
            ans=min(ans,arr[low]);
            low=mid+1;
        }
        else{
            ans=min(ans,arr[mid]);
            high=mid-1;
        }
    }
    return ans;
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

   int nums=mini(arr,n);
   cout <<" minimum element is : "<< nums;
    return 0;
}
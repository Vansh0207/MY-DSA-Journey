//Implement Lower Bound

#include<bits/stdc++.h>
using namespace std;

//k= target value

int binarysearch(int nums[],int k,int n){
    int l=0;
    int r=n-1;
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;      

        if(nums[mid]>=k){
            ans=mid;                                 //store in ans
            r=mid-1;                                 // if element in array is greater than target then move left
        }                                  
        else l=mid+1;                               // if element in array is lesser than target then move right
    }                  
    return  ans;                            
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
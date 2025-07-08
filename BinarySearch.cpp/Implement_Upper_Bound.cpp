//Implement_Upper_Bound

#include<bits/stdc++.h>
using namespace std;

int UpperBound(int nums[],int k,int n){
    int l=0;
    int h=n-1;
    int ans=n;
    
    while(l<=h){
        int mid=(l+h)/2;
        
        if(nums[mid]>k){
            ans=mid;
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
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

    cout<<UpperBound(nums,target,size);
    return 0;
}
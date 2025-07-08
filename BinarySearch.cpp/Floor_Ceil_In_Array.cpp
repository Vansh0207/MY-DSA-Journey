//Implement_Floor_Ceil_Function

#include<bits/stdc++.h>
using namespace std;

pair<int,int> getFloorAndCeil(int nums[],int k,int n){
    int l=0;
    int h=n-1;
    int floor=-1;
    int ceil=-1;
    
    while(l<=h){
        int mid=(l+h)/2;

        if(nums[mid]==k) return {nums[mid],nums[mid]};

        else if(nums[mid]>k){
            ceil=nums[mid];
            h=mid-1;
        }
        else{
            floor=nums[mid];
            l=mid+1;
        }
    }
    return {floor,ceil};
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
    pair<int,int> result=getFloorAndCeil(nums,target,size);
    cout<< "Floor:"<< result.first<<"\n";
    cout<< "Ceil:" << result.second; 
    return 0;
}